#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,p,c[60][60],f[60][60][110],g[60][60][110],ans,q=1000000007;
inline void add(int &a,int b)
{
	a+=b;
	if(a>=q)
	  a-=q;
}
int main()
{
	int i,j,k,l,u;
	scanf("%d%d%d",&n,&m,&p);
	n/=2;
	for(i=0;i<=n;i++)
	  {
	   c[i][0]=1;
	   for(j=1;j<=i;j++)
	     c[i][j]=min(c[i-1][j]+c[i-1][j-1],200);
	  }
	f[0][1][1]=1;
	for(i=1;i<=m;i++)
	  {
	   if(i>1)
	     for(j=1;j<=n;j++)
	       g[j][j][1]=1;
	   for(j=1;j<=n;j++)
	     for(k=1;k<=j;k++)
	       for(l=1;l<=p;l++)
	         if(f[j][k][l])
		   	   for(u=1;j+u<=n && l*c[u+k-1][k-1]<=p;u++)
				 add(g[j+u][u][l*c[u+k-1][k-1]],f[j][k][l]);
	   for(j=1;j<=n;j++)
	     for(k=1;k<=j;k++)
	       for(l=1;l<=p;l++)
	         if(g[j][k][l])
	           {
				f[j][k][l]=g[j][k][l];
				g[j][k][l]=0;
				add(ans,f[j][k][l]);
			   }
	  }
	printf("%d\n",ans);
	return 0;
}