#include<stdio.h>
#include<stdlib.h>
//Node structure
struct Node
{
	int data;
	struct Node* next;
};
//Function to create a new node
struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	return newNode;
}
//Insert a new node at the end of the list
void insertNode(struct Node** head, int value)
{
	struct Node* newNode = createNode(value);
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	struct Node* temp= *head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newNode;
}
//Delete the node that contains the given value
void deleteNode(struct Node** head, int value)
{
	struct Node* temp= *head;
	struct Node* prev= NULL;

//Traverse to find the node
while(temp!=NULL && temp->data!=value)
{
	prev=temp;
	temp=temp->next;
}
//Value not found
if(temp==NULL)
{
	printf("Value %d not found in the list.\n",value);
	return;
}
//If node to delete is head
if(prev==NULL)
*head = temp->next;
else
prev->next= temp->next;

free(temp);
printf("Deleted node with value %d\n",value);
}

//Print the list
void displayList(struct Node* head)
{
	if(head==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	printf("Linked list: ");
	while(head!=NULL)
	{
		printf("%d-> ",head->data);
		head=head->next;
	}
	printf("NULL\n");
}

//Main menu
int main()
{
	struct Node* head= NULL;
	int choice,value;
	
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1:
    		printf("Enter the value to insert: ");
    		scanf("%d",&value);
    		insertNode(&head, value);
    		break;
    	case 2:
    		printf("Enter the value to delete: ");
    		scanf("%d",&value);
    		deleteNode(&head, value);
    		break;
    	case 3:
    		displayList(head);
    		break;
    	case 4:
    		exit(0);
    	default:
    		printf("Invalid choice.\n");
	}
}
return 0;
}
