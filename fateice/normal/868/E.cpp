#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,s,f[60][60],g[60][60],x[3000],w[60],p,q,ans=1e9;
vector<int> a[60];
inline void dfs(int i,int j)
{
	int k;
	if(a[i].size()==1)
	  for(k=0;k<m;k++)
	    x[++p]=f[i][k]+g[i][s];
	q+=w[i];
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j)
	    dfs(a[i][k],i);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    if(i!=j)
	      g[i][j]=1e9;
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d%d",&j,&k,&l);
	   a[j].push_back(k);
	   a[k].push_back(j);
	   g[j][k]=g[k][j]=l;
	  }
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    for(k=1;k<=n;k++)
	      g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
	scanf("%d%d",&s,&m);
	for(i=1;i<=m;i++)
	  {
	   scanf("%d",&j);
	   w[j]++;
	  }
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	    if(a[j].size()==1)
	      {
		   p=0;
	       for(k=1;k<=n;k++)
	         if(a[k].size()==1 && k!=j)
	           for(l=0;l<i;l++)
	             x[++p]=f[k][l]+g[j][k];
	       sort(x+1,x+p+1);
	       f[j][i]=x[p-i+1];
		  }
	for(i=0;i<a[s].size();i++)
	  {
	   p=q=0;
	   dfs(a[s][i],s);
	   if(q)
	     {
	      sort(x+1,x+p+1);
	      ans=min(ans,x[p-q+1]);
		 }
	  }
	printf("%d\n",ans);
	return 0;
}