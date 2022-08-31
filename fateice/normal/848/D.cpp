#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
const int q=1000000007;
int n,m,f[60][60],c[60][60][60],g[60][60][60][60],x[60];
inline int C(int n,int m)
{
	int i,k=1;
	for(i=n;i>n-m;i--)
	  k=(L)k*i%q;
	for(i=1;i<=m;i++)
	  k=(L)k*x[i]%q;
	return k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,u,kk,ll;
	scanf("%d%d",&n,&m);
	x[1]=1;
	for(i=2;i<=n;i++)
	  x[i]=q-(L)q/i*x[q%i]%q;
	f[0][0]=1;
	f[1][1]=1;
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    g[0][0][i][j]=g[1][1][i][j]=c[i][j][0]=1;
	g[0][0][0][n]=1;
	for(k=0;k<=n;k++)
	  c[1][1][k]=1;
	for(i=2;i<=n;i++)
	  for(j=1;j<=n;j++)
	  {
	    for(k=j-1;k<=n;k++)
	      for(l=j-1;l<=((k==j-1)?n:(j-1));l++)
	        for(u=0;u<i;u++)
	          f[i][j]=(f[i][j]+(L)g[u][k][n][n]*g[i-u-1][l][n][n])%q;
	    for(k=1;k<=50;k++)
	      c[i][j][k]=C(k+f[i][j]-1,k);
	    c[i][j][0]=1;
	    for(k=1;k<=n;k++)
	      for(l=1;l<=n;l++)
	        {
			 if(l>1)
			   kk=k,ll=l-1;
			 else
			   kk=k-1,ll=n;
			 for(u=0;k*u<=i && l*u<=j;u++)
			   g[i][j][k][l]=(g[i][j][k][l]+(L)g[i-k*u][j-l*u][kk][ll]*c[k][l][u])%q;
			}
	  }
	printf("%d\n",g[n][m-1][n][n]);
	return 0;
}