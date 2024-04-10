#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[6010];
bool f[20000000];
int main()
{
	//freopen("prime.in","r",stdin);
	//freopen("prime.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	m=n*(n+1)/2;
	f[1]=1;
	for(i=2;i<=m;i++)
	  if(!f[i])
	    for(j=i+i;j<=m;j+=i)
	      f[j]=1;
	if(!f[m])
	  i=0;
	else
      if(m&1)
        if(!f[m-2])
          i=2;
        else
          {
           for(i=1;;i++)
             if(!f[i] && !f[m-3-i])
               break;
          }
      else
        for(i=1;;i++)
          if(!f[i] && !f[m-i])
            break;
    for(j=1;j<=n;j++)
      x[j]=1;
    for(j=n,k=i;k;j--)
      if(k>=j)
        {
         k-=j;
         x[j]=2;
        }
    if(f[m-i])
      if(x[3]==1)
        x[3]=3;
      else
        x[1]=x[2]=3;
    for(i=1;i<=n;i++)
      printf("%d ",x[i]);
    printf("\n");
	return 0;
}