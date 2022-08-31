#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[5010],b[5010],c[5010],x[5010],y[5010],p,f[5010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  {
	   printf("? 0 %d\n",i);
	   fflush(stdout);
	   scanf("%d",&a[i]);
	  }
	for(i=0;i<n;i++)
	  {
	   printf("? %d 0\n",i);
	   fflush(stdout);
	   scanf("%d",&b[i]);
	  }
	for(i=0;i<n;i++)
	  {
	   x[0]=i;
	   for(j=0;j<n;j++)
	     y[j]=x[0]^a[j];
	   for(j=1;j<n;j++)
	     x[j]=y[0]^b[j];
	   for(j=0;j<n;j++)
	     c[j]=0;
	   for(j=0;j<n;j++)
	     if(x[j]<n && c[x[j]]==0 && y[x[j]]==j)
	       c[x[j]]=1;
	     else
	       break;
	   if(j==n)
	     {
	      p++;
	      for(j=0;j<n;j++)
	        f[j]=x[j];
		 }
	  }
	printf("!\n");
	fflush(stdout);
	printf("%d\n",p);
	fflush(stdout);
	for(i=0;i<n;i++)
	  {
	   printf("%d ",f[i]);
	   fflush(stdout);
	  }
	return 0;
}