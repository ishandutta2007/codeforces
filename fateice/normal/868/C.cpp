#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[20];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
	   for(j=1,k=0;j<=m;j++)
	     {
		  scanf("%d",&l);
	      k=k*2+1-l;
		 }
	   for(j=k;j;j=(j-1&k))
	     x[j]++;
	   x[0]++;
	  }
	for(i=0,k=0;i<(1<<m);i++)
	  if(x[i] && x[i^(1<<m)-1])
	    k=1;
	if(k)
	  printf("YES\n");
	else
	  printf("NO\n");
	return 0;
}