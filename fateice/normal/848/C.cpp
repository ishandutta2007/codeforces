#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#define L long long
using namespace std;
int n,m,x[100010],w[400010],l[15000010],r[15000010],p,q;
L f[15000010];
set<int> a[100010],b[100010];
inline void add2(int i,int j,int k,int p,int x)
{
//	cout<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<x<<"\n";
	f[i]+=x;
	if(j<k)
	  {
	   if(p<=(j+k>>1))
	     {
		  if(!l[i])
		    l[i]=++q;
	      add2(l[i],j,j+k>>1,p,x);
		 }
	   else
	     {
		  if(!r[i])
		    r[i]=++q;
	      add2(r[i],(j+k>>1)+1,k,p,x);
		 }
	  }
}
inline void add(int i,int j,int k,int ll,int rr,int x)
{
	for(i=n+1-ll;i<=n;i+=i&-i)
	  {
	   if(!w[i])
	     w[i]=++q;
	   add2(w[i],1,p,rr,x);
	  }
}
inline L sum2(int i,int j,int k,int p)
{
//cout<<i<<" "<<j<<" "<<k<<" "<<p<<"!!!!\n";
	if(!i)
	  return 0;
	if(p>=k)
	  return f[i];
	else
	  {
	   L q=sum2(l[i],j,j+k>>1,p);
	   if(p>(j+k>>1))
	     q+=sum2(r[i],(j+k>>1)+1,k,p);
	   return q;
	  }
}
inline L sum(int i,int j,int k,int ll,int rr)
{
	L u=0;
	for(i=n+1-ll;i>0;i^=i&-i)
	  u+=sum2(w[i],1,p,rr);
	return u;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,u;
	scanf("%d%d",&n,&m);
	for(p=1;p<n;p<<=1);
	for(i=1;i<=n;i++)
	  {
	   a[i].insert(n+1);
	   b[i].insert(0);
	  }
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   a[x[i]].insert(i);
	   b[x[i]].insert(-i);
	   j=-*b[x[i]].upper_bound(-i);
	   if(j)
	     add(1,1,p,j,i,i-j);
	  }
	while(m--)
	  {
	   scanf("%d",&i);
	   if(i==1)
	     {
		  scanf("%d%d",&i,&j);
		  a[x[i]].erase(i);
		  b[x[i]].erase(-i);
		  k=*a[x[i]].upper_bound(i);
		  if(k<=n)
		    add(1,1,p,i,k,i-k);
		  u=-*b[x[i]].upper_bound(-i);
		  if(u)
		    add(1,1,p,u,i,u-i);
		  if(u && k<=n)
		    add(1,1,p,u,k,k-u);
		  x[i]=j;
		  a[x[i]].insert(i);
		  b[x[i]].insert(-i);
		  k=*a[x[i]].upper_bound(i);
		  if(k<=n)
		    add(1,1,p,i,k,k-i);
		  u=-*b[x[i]].upper_bound(-i);
		  if(u)
		    add(1,1,p,u,i,i-u);
		  if(u && k<=n)
		    add(1,1,p,u,k,u-k);
		 }
	   else
	     {
		  scanf("%d%d",&i,&j);
		  printf("%I64d\n",sum(1,1,p,i,j));
		 }
	  }
	return 0;
}