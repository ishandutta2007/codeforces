#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int siz[N<<2][21],tag[N<<2],a[N];
void push_up(int p) {
	for(int i=0;i<=20;i++)
		siz[p][i]=siz[p<<1][i]+siz[p<<1|1][i];
}
void build(int p,int l,int r) {
	if(l==r) {
		for(int i=0;i<=20;i++)
			siz[p][i]=a[l]>>i&1;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	push_up(p);
}
void make_tag(int p,int L,int v) {
	tag[p]^=v;
	for(int i=0;i<=20;i++)
		if(v>>i&1)siz[p][i]=L-siz[p][i];
}
void push_down(int p,int L) {
	if(tag[p]) {
		make_tag(p<<1,L-L/2,tag[p]);
		make_tag(p<<1|1,L/2,tag[p]);
		tag[p]=0;
	}
}
void mdf_xor(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,r-l+1,v);
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)mdf_xor(p<<1,l,mid,x,y,v);
	if(y>mid)mdf_xor(p<<1|1,mid+1,r,x,y,v);
	push_up(p);
}
long long qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		long long ans=0;
		for(int i=0;i<=20;i++)
			ans+=siz[p][i]*(1ll<<i);
		return ans;
	}
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid)ans+=qry(p<<1,l,mid,x,y);
	if(y>mid)ans+=qry(p<<1|1,mid+1,r,x,y);
	return ans;
}
int main() {
	int n,m,op,l,r,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	while(m--) {
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)printf("%lld\n",qry(1,1,n,l,r));
		else scanf("%d",&v),mdf_xor(1,1,n,l,r,v);
	}
	return 0;
}