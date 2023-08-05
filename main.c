#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,a;
int size=8; //Initializing the size as 8
struct Node
{
    int data;
    struct Node *next;
}*temp,*head;
int isFull()
{
    if(rear==size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if(front==-1 || rear-front<0)
    {
        front=rear=-1;
        return 1;
    }
    return 0;
}

int dequeue(struct Node *n[])
{
    int ele;
    ele=n[front]->data;
        if(front<rear)
        {
            head=n[front+1];
        }
    front=front+1;
    return ele;
}

void enqueue(struct Node *n[])
{
    
    rear=rear+1;
    n[rear]=(struct Node*)malloc(sizeof(struct Node));
    n[rear]->data=a;
    if(rear==0)
    {
    front=0;
    head=n[front];
    n[front]->next=NULL;
    temp=head;
    }
    else
    {
        n[rear]->next=NULL;
        temp->next=n[rear];
    }
    //temp = n->next;
    //printf("%d",temp->data);
}
int peek(struct Node *n[])
{
    return n[rear-a+1]->data;    
}
void display(struct Node *n[])
{
    if(rear-front>=0)
    {
    int s=front;
    while(s<=rear)
    {
        printf("%d ",n[s]->data);
        s++;
    }
    }
}

int main()
{
    int i,flag=1;
    struct Node *n[size];
    while(flag)
    {
        printf("\nEnter 1 to enter elements, 2 to delete, 3 to peek and 0 to finally print:\n");
        scanf("%d",&i);
        switch (i)
        {
        case 0:
        printf("Elements are: ");
         display(n);
         break;
        case 1:
         if(isFull()==1)
         {
            printf("\nThe z is full\n");
         }
         else
         {
            printf("\nEnter the element: ");
            scanf("%d",&a);
            enqueue(n);
         }
         break;
        case 2:
         if(isEmpty()==1)
         {
            printf("\nThe stack is empty\n");
         }
         else
         {
         printf("Deleted element is: %d\n",dequeue(n));
         }
         break;
         case 3:
         printf("\nEnter the index position: ");
         scanf("%d",&a);
         if(a>rear || a<front)
         {
            printf("\nDoesn't exist\n");
         }
         else
         {
            printf("The element present in index: %d\n",dequeue(n));
         }
         break;
        default:
         printf("\nInvalid Case\n");
         flag=0;
        }
    }
}