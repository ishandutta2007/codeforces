#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#define L long long
using namespace std;
int n,x[200010],a[40],l[200010],r[200010];
map<int,int> f;
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	p=(L)n*(n+1)/2;
	for(i=1;i<=n;i++)
	  {
	   l[i]=f[x[i]]+1;
	   f[x[i]]=i;
	   for(j=0;j<30;j++)
	     if(!(x[i]&(1<<j)))
	       l[i]=max(l[i],a[j]+1);
	     else
	       a[j]=i;
	  }
	for(i=0;i<30;i++)
	  a[i]=n+1;
	for(i=n;i>0;i--)
	  {
	   r[i]=n+1;
	   for(j=0;j<30;j++)
	     if(!(x[i]&(1<<j)))
	       r[i]=min(r[i],a[j]-1);
	     else
	       a[j]=i;
	   p-=(L)(i-l[i]+1)*(r[i]-i+1);
	  }
	cout<<p;
	return 0;
}