#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x[300010],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	printf("1");
	for(i=1,k=n;i<=n;i++)
	  {
	   scanf("%d",&j);
	   x[j]=1;
	   p++;
	   while(x[k])
	     k--,p--;
	   printf(" %d",p+1);
	  }
	printf("\n");
	return 0;
}