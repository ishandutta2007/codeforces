#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,m,ctr=0,temp;
	scanf("%d%d",&n,&m);
	if(m==0||n==0)
	{
		printf("-1");
	}
	else if(m%n!=0)
	{ printf("-1");
	}
	else
	{
	   temp= m/n;
	   while(temp%2==0)
	   {
	   	ctr++;
	   	temp= temp/ 2;
	   }
	   while(temp%3==0)
	   {
	   	ctr++;
	   	temp=temp/ 3;
	   }
	   if(temp==1)
	   printf("%d",ctr);
	   else printf("-1");
	}
	return 0;
}