#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int t,n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&t);
	while(t--)
	  {
	   scanf("%d",&n);
	   if(n%4==0)
	     printf("%d\n",n/4);
	   else if(n%4==1)
	     if(n<=5)
	       printf("-1\n");
	     else
	       printf("%d\n",n/4-1);
	   else if(n%4==2)
	     if(n==2)
	       printf("-1\n");
	     else
	       printf("%d\n",n/4);
	   else
	     if(n<=11)
	       printf("-1\n");
	     else
	       printf("%d\n",n/4-1);
	  }
	return 0;
}