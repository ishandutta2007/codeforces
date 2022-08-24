#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,f[200010],h[200010];
vector<int> a[200010],x[200010];
bool z[200010];
inline void dfs(int i,int j)
{
	int k;
	z[i]=1;
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j)
	    if(!z[a[i][k]])
	      {
		   z[a[i][k]]=1;
		   h[a[i][k]]=h[i]+1;
		   dfs(a[i][k],i);
		  }
	    else if(h[a[i][k]]>h[i])
	      {
		   f[i]^=1;
		   x[i].push_back(a[i][k]);
		  }
	if(j)
  	  if(f[i])
	    x[i].push_back(j);
	  else
	    {
	     f[j]^=1;
	     x[j].push_back(i);
	    }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].push_back(k);
	   a[k].push_back(j);
	  }
	for(i=1;i<=n;i++)
	  if(!z[i])
	    dfs(i,0);
	for(i=1,k=0;i<=n;i++)
	  k+=x[i].size()/2;
	printf("%d\n",k);
	for(i=1;i<=n;i++)
	  for(j=0;j+1<x[i].size();j+=2)
	    printf("%d %d %d\n",x[i][j],i,x[i][j+1]);
	return 0;
}