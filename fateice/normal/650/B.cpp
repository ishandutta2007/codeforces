#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,a,b,s[500010],t[500010],p;
char x[500010];
int main()
{
	int i,j;
	scanf("%d%d%d%d%s",&n,&a,&b,&m,&x);
	s[1]=t[n+1]=b*(x[0]=='w')+1;
	for(i=2;i<=n;i++)
	  s[i]=s[i-1]+a+b*(x[i-1]=='w')+1;
	for(i=n;i>1;i--)
	  t[i]=t[i+1]+a+b*(x[i-1]=='w')+1;
	if(s[n]<=m)
	  {
	   printf("%d\n",n);
	   return 0;
	  }
	if(s[1]>m)
	  {
	   printf("0\n");
	   return 0;
	  }
	for(i=1;s[i+1]<=m;i++);
	for(j=n+1;t[j-1]+s[i]-s[1]+(i-1)*a<=m;j--);
	if(i+n+1-j>p)
	  p=i+n+1-j;
	for(i--;i>1;i--)
	  {
	   for(;t[j-1]+s[i]-s[1]+(i-1)*a<=m;j--);
	   if(i+n+1-j>p)
	     p=i+n+1-j;
	  }
	for(j=n+1;t[j-1]<=m;j--);
	for(i=1;s[i+1]+t[j]-s[1]+(n+1-j)*a<=m;i++);
	if(i+n+1-j>p)
	  p=i+n+1-j;
	for(j++;j<n+1;j++)
	  {
	   for(;s[i+1]+t[j]-s[1]+(n+1-j)*a<=m;i++);
	   if(i+n+1-j>p)
	     p=i+n+1-j;
	  }
	printf("%d\n",p);
	return 0;
}