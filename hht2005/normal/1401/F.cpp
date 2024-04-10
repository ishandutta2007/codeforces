#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int f[maxn<<2],ls[maxn<<2],rs[maxn<<2],n,S;
long long sum[maxn<<2];
void pushdown(int p) {
	if(f[p]) {
		f[p<<1]^=1;
		f[p<<1|1]^=1;
		f[p]=0;
	}
}
int qry(int p,int l,int r,int x) {
	if(l==r)return f[p];
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)return qry(p<<1,l,mid,x);
	else return qry(p<<1|1,mid+1,r,x);
}
void add(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		f[p]^=1;
		return;
	}
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y);
	if(y>mid)add(p<<1|1,mid+1,r,x,y);
}
void pudo(int p) {
	if(qry(1,1,S,p)) {
		swap(ls[p],rs[p]);
		add(1,1,S,p,p);
	}
}
void change(int p,int l,int r,int x,int v) {
	if(l==r) {
		sum[p]=v;
		return;
	}
	pudo(p);
	int mid=(l+r)>>1;
	if(x<=mid)change(ls[p],l,mid,x,v);
	else change(rs[p],mid+1,r,x,v);
	sum[p]=sum[ls[p]]+sum[rs[p]];
}
long long qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return sum[p];
	pudo(p);
	int mid=(l+r)>>1;
	long long Sum=0;
	if(x<=mid)Sum+=qry(ls[p],l,mid,x,y);
	if(y>mid)Sum+=qry(rs[p],mid+1,r,x,y);
	return Sum;
}
void build(int p,int l,int r) {
	if(l==r) {
		scanf("%lld",sum+p);
		return;
	}
	int mid=(l+r)>>1;
	build(ls[p]=p<<1,l,mid);
	build(rs[p]=p<<1|1,mid+1,r);
	sum[p]=sum[ls[p]]+sum[rs[p]];
}
int main() {
	int q,opt,k,x;
	scanf("%d%d",&n,&q);
	S=(1<<(n+1))-1;
	build(1,1,1<<n);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&opt,&k);
		if(opt==1) {
			scanf("%d",&x);
			change(1,1,1<<n,k,x);
		}
		if(opt==2)add(1,1,S,1<<(n-k),S);
		if(opt==3)add(1,1,S,1<<(n-k-1),(1<<(n-k))-1);
		if(opt==4) {
			scanf("%d",&x);
			printf("%lld\n",qry(1,1,1<<n,k,x));
		}
	}
	return 0;
}