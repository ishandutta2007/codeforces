#include<stdio.h>
int n;
int main()
{
    scanf("%i",&n);
    if(n==0)
	printf("1\n");
    else
    {
	n--;
	if(n%4==0)
	    printf("8\n");
	else if(n%4==1)
	    printf("4\n");
	else if(n%4==2)
	    printf("2\n");
	else
	    printf("6\n");
    }
}