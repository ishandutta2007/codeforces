#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,m,a[100010],x[100010],l=1,r;
L f[100010][30],p;
inline void add(int i)
{
	p+=x[a[i]];
	x[a[i]]++;
}
inline void del(int i)
{
	x[a[i]]--;
	p-=x[a[i]];
}
inline void make(int ll,int rr)
{
	while(r<rr)
	  add(++r);
	while(l>ll)
	  add(--l);
	while(l<ll)
	  del(l++);
	while(r>rr)
	  del(r--);
}
inline void solve(int m,int i,int j,int ll,int rr)
{
	if(j<i)
	  return;
	int k=(i+j>>1),u,v;
	make(ll,k);
	f[k][m]=p+f[ll-1][m-1];
	v=ll;
	for(u=ll+1;u<=rr && u<=k;u++)
	  {
	   del(l++);
	   if(p+f[u-1][m-1]<f[k][m])
	     {
		  f[k][m]=p+f[u-1][m-1];
		  v=u;
		 }
	  }
	solve(m,k+1,j,v,rr);
	solve(m,i,k-1,ll,v);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	  f[i][0]=1e18;
	for(i=1;i<=m;i++)
	  {
	   make(1,0);
	   solve(i,1,n,1,n);
	  }
	cout<<f[n][m]<<"\n";
	return 0;
}