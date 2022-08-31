#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[210][15][10000],w[210],l[210][20],r[210][20],a[40],p;
char s[110];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,u,v,ii,jj,kk;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s",&s);
	   w[i]=strlen(s);
	   for(j=1;j<=min(w[i],13);j++)
	     l[i][j]=s[j-1]-'0',r[i][j]=s[w[i]-j]-'0';
	   for(ii=1;ii<=w[i];ii++)
	     for(j=1,k=0;j<=13 && ii+j-1<=w[i];j++)
	       {
		    k=(k<<1)+s[ii+j-2]-'0';
		    x[i][j][k]=1;
		   }
	   w[i]=min(w[i],13);
	  }
	scanf("%d",&m);
	for(i=n+1;i<=n+m;i++)
	  {
	   scanf("%d%d",&j,&k);
	   for(u=1;u<=13;u++)
	     for(v=0;v<(1<<u);v++)
	       x[i][u][v]=x[j][u][v]|x[k][u][v];
	   for(p=0,u=w[j];u>0;u--)
	     a[++p]=r[j][u];
	   for(u=1;u<=w[k];u++)
	     a[++p]=l[k][u];
	   for(ii=1;ii<=p;ii++)
	     for(jj=1,kk=0;jj<=13 && ii+jj-1<=p;jj++)
	       {
	        kk=(kk<<1)+a[ii+jj-1];
	        x[i][jj][kk]=1;
	       }
	   w[i]=min(w[j]+w[k],13);
	   for(u=1;u<=w[j];u++)
	     l[i][u]=l[j][u];
	   for(;u<=w[i];u++)
	     l[i][u]=l[k][u-w[j]];
	   for(u=1;u<=w[k];u++)
	     r[i][u]=r[k][u];
	   for(;u<=w[i];u++)
	     r[i][u]=r[j][u-w[k]];
	   for(u=13;u>0;u--)
	     {
		  for(v=0;v<(1<<u);v++)
		    if(x[i][u][v]==0)
		      break;
		  if(v==(1<<u))
		    break;
		 }
	   printf("%d\n",u);
	  }
	return 0;
}