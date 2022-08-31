#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,w[210],d[210][30010],f[30010],x[210][30010],u[30010],p;
vector<int> a[30010],b[30010];
inline void GG()
{
	printf("-1\n");
	exit(0);
}
inline void line(int i,int j)
{
	a[i].push_back(j);
	a[j].push_back(i);
}
inline void dfs(int i,int j,int k,int l)
{
	if(d[k][i]!=l)
	  GG();
	int u;
	for(u=0;u<a[i].size();u++)
	  if(a[i][u]!=j)
	    dfs(a[i][u],i,k,l+1);
}
inline void check()
{
	int i;
	for(i=1;i<=m;i++)
	  dfs(w[i],0,i,0);
}
inline bool cmp(int i,int j)
{
	return d[1][i]<d[1][j];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
	   for(j=1;j<=n;j++)
	     {
	      scanf("%d",&d[i][j]);
	      if(d[i][j]==0)
	        if(w[i])
	          GG();
	        else
	          w[i]=j;
		 }
	   if(!w[i])
	     GG();
	   for(j=1;j<i;j++)
	     if(w[i]==w[j])
	       GG();
	  }
	for(i=2;i<=m;i++)
	  {
	   for(j=1;j<=n;j++)
	     if(d[i][j]+d[1][j]==d[i][w[1]])
	       x[i][d[i][j]]=j;
	   for(j=0;j<=d[i][w[1]];j++)
	     if(!x[i][j])
	       GG();
	   for(j=0;j<d[i][w[1]];j++)
	     if(f[x[i][j]] && f[x[i][j]]!=x[i][j+1])
	       GG();
	     else
	       f[x[i][j]]=x[i][j+1];
	  }
	for(i=1;i<=n;i++)
	  if(f[i])
	    line(i,f[i]);
	check();
	for(i=1;i<=n;i++)
	  if(!f[i] && i!=w[1])
	    u[++p]=i;
	  else
	    b[i].push_back(i);
	if(p)
	  {
	   sort(u+1,u+p+1,cmp);
	   for(i=1;i<=p;i++)
	     {
		  for(j=2,k=w[1];j<=m;j++)
		    {
			 l=d[1][u[i]]+d[j][u[i]]-d[1][w[j]];
			 if((l&1) || l==0)
			   GG();
			 r=d[j][u[i]]-l/2;
			 r=x[j][r];
			 if(d[1][r]>d[1][k])
			   k=r;
			}
		  j=d[1][u[i]]-d[1][k];
		  if(b[k].size()>=j)
		    {
		     line(b[k][j-1],u[i]);
		     if(b[k].size()==j)
		       b[k].push_back(u[i]);
			}
		  else
		    GG();
		 }
	   check();
	  }
	for(i=1;i<=n;i++)
	  for(j=0;j<a[i].size();j++)
	    if(a[i][j]>i)
	      printf("%d %d\n",i,a[i][j]);
	return 0;
}