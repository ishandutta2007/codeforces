#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define L long long
using namespace std;
const L inf=1e13;
int n,m,q;
L s[1000010],t[1000010],f[100010],p;
vector<int> x[1000010],y[1000010],z[1000010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	  {
	   scanf("%d%d%d%d",&i,&j,&k,&l);
	   x[i].push_back(j);
	   y[i].push_back(k);
	   z[i].push_back(l);
	  }
	for(i=1;i<=n;i++)
	  f[i]=inf;
	s[0]=inf*n;
	for(i=1;i<=1000000;i++)
	  {
	   s[i]=s[i-1];
	   for(j=0;j<x[i].size();j++)
	     if(y[i][j]==0 && z[i][j]<f[x[i][j]])
	       {
			s[i]-=f[x[i][j]]-z[i][j];
			f[x[i][j]]=z[i][j];
		   }
	  }
	for(i=1;i<=n;i++)
	  f[i]=inf;
	t[1000001]=inf*n;
	for(i=1000000;i>0;i--)
	  {
	   t[i]=t[i+1];
	   for(j=0;j<x[i].size();j++)
	     if(x[i][j]==0 && z[i][j]<f[y[i][j]])
	       {
			t[i]-=f[y[i][j]]-z[i][j];
			f[y[i][j]]=z[i][j];
		   }
	  }
	p=inf;
	for(i=2;i+q<=1000000;i++)
	  p=min(p,s[i-1]+t[i+q]);
	if(p>1e12)
	  printf("-1\n");
	else
	  cout<<p<<"\n";
	return 0;
}