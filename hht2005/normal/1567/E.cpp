#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int v[N];
long long C(int x) {
	return 1ll*x*(x+1)/2;
}
struct node {
	int ls,rs,l,r;
	long long sum;
	node(int x=0) {
		sum=ls=rs=1;
		l=r=x;
	}
	node operator+(const node &a)const {
		node b;
		b.sum=sum+a.sum;
		b.l=l;
		b.r=a.r;
		b.ls=ls;
		b.rs=a.rs;
		if(v[r]>v[a.l])return b;
		b.sum=b.sum-C(rs)-C(a.ls)+C(rs+a.ls);
		if(b.ls==r-l+1)b.ls+=a.ls;
		if(b.rs==a.r-a.l+1)b.rs+=rs;
		return b;
	}
}a[N<<2];
void build(int p,int l,int r) {
	if(l==r) {
		a[p]=node(l);
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	a[p]=a[p<<1]+a[p<<1|1];
}
void add(int p,int l,int r,int x) {
	if(l==r) {
		a[p]=node(l);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x);
	else add(p<<1|1,mid+1,r,x);
	a[p]=a[p<<1]+a[p<<1|1];
}
node qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return a[p];
	int mid=(l+r)>>1;
	if(y<=mid)return qry(p<<1,l,mid,x,y);
	if(x>mid)return qry(p<<1|1,mid+1,r,x,y);
	return qry(p<<1,l,mid,x,y)+qry(p<<1|1,mid+1,r,x,y);
}
int main() {
	int n,q,op,l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	build(1,1,n);
	while(q--) {
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) {
			v[l]=r;
			add(1,1,n,l);
		} else printf("%lld\n",qry(1,1,n,l,r).sum);
	}
	return 0;
}