#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int Max[N],v[N];
long long sum[N];
void push_up(int p) {
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void build(int p,int l,int r) {
	if(l==r) {
		sum[p]=Max[p]=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	push_up(p);
}
void mdf_mod(int p,int l,int r,int x,int y,int v) {
	if(Max[p]<v)return;
	if(l==r) {
		sum[p]=Max[p]=sum[p]%v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)mdf_mod(p<<1,l,mid,x,y,v);
	if(y>mid)mdf_mod(p<<1|1,mid+1,r,x,y,v);
	push_up(p);
}
void modify(int p,int l,int r,int x,int v) {
	if(l==r) {
		sum[p]=Max[p]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(p<<1,l,mid,x,v);
	else modify(p<<1|1,mid+1,r,x,v);
	push_up(p);
}
long long qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return sum[p];
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid)ans+=qry(p<<1,l,mid,x,y);
	if(y>mid)ans+=qry(p<<1|1,mid+1,r,x,y);
	return ans;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	int opt,l,r,v;
	build(1,1,n);
	while(m--) {
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)printf("%lld\n",qry(1,1,n,l,r));
		if(opt==2)scanf("%d",&v),mdf_mod(1,1,n,l,r,v);
		if(opt==3)modify(1,1,n,l,r);
	}
	return 0;
}