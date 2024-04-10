#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
using namespace std;
int n,m,w,h,x[100010],l,r,u[100010],v[100010];
vector<pair<int,int> > a[200010],b[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%d%d",&n,&w,&h);
	int nn=n;
	for(l=1;l<=n;l++)
	  {
	   scanf("%d%d%d",&i,&j,&k);
	   if(i==2)
	     a[j-k+100000].push_back(make_pair(j,l));
	   else
	     b[j-k+100000].push_back(make_pair(j,l));
	  }
	for(i=0;i<=200000;i++)
	  {
	   n=a[i].size();
	   m=b[i].size();
	   if(n)
	     sort(&a[i][0],&a[i][0]+n);
	   if(m)
	     sort(&b[i][0],&b[i][0]+m);
	   l=1;
	   r=0;
	   for(j=n-1;j>=0;j--)
	     x[++r]=a[i][j].yy;
	   for(j=0;j<m;j++)
	     {
		  x[++r]=b[i][j].yy;
		  u[x[l]]=b[i][j].xx;
		  v[x[l]]=h;
		  l++;
		 }
	   for(j=n-1;j>=0;j--)
	     {
		  u[x[l]]=w;
		  v[x[l]]=a[i][j].xx;
		  l++;
		 }
	  }
	for(i=1;i<=nn;i++)
	  printf("%d %d\n",u[i],v[i]);
	return 0;
}