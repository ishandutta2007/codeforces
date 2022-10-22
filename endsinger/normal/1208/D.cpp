#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,a[N],p[N],tr[N<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=l;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
void add(int k,int l,int r,int v)
{
	if(l==r)
	{
		tr[k]=0;
		return;
	}
	int mid=l+r>>1;
	if(v<=mid) add(k<<1,l,mid,v);
	else add(k<<1|1,mid+1,r,v);
	tr[k]=tr[k<<1]+tr[k<<1|1];
} 
int query(int k,int l,int r,int v)
{
	if(l==r)
	{
		return tr[k]==v?l:l-1;
	} 
	int mid=l+r>>1;
	if(tr[k<<1]>v) return query(k<<1,l,mid,v);
	else query(k<<1|1,mid+1,r,v-tr[k<<1]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		p[i]=query(1,1,n,a[i])+1;
		add(1,1,n,p[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<' ';
	return 0;
}