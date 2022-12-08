#include<bits/stdc++.h>
using namespace std;
#define ub(x) upper_bound(c+1,c+m+1,x)-c-1
const int N=2e5+10;
int siz[N<<2],tag_xor[N<<2],tag_cov[N<<2];
long long c[N];
void make_tag_xor(int p,int L) {
	siz[p]=L-siz[p];
	tag_xor[p]^=1;
}
void make_tag_cov(int p,int v,int L) {
	siz[p]=v*L;
	tag_xor[p]=0;
	tag_cov[p]=v;
}
void push_down(int p,int L) {
	if(tag_cov[p]!=-1) {
		make_tag_cov(p<<1,tag_cov[p],L-L/2);
		make_tag_cov(p<<1|1,tag_cov[p],L/2);
		tag_cov[p]=-1;
	}
	if(tag_xor[p]) {
		make_tag_xor(p<<1,L-L/2);
		make_tag_xor(p<<1|1,L/2);
		tag_xor[p]=0;
	}
}
void mdf_xor(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return make_tag_xor(p,r-l+1);
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)mdf_xor(p<<1,l,mid,x,y);
	if(y>mid)mdf_xor(p<<1|1,mid+1,r,x,y);
	siz[p]=siz[p<<1]+siz[p<<1|1];
}
void mdf_cov(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag_cov(p,v,r-l+1);
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)mdf_cov(p<<1,l,mid,x,y,v);
	if(y>mid)mdf_cov(p<<1|1,mid+1,r,x,y,v);
	siz[p]=siz[p<<1]+siz[p<<1|1];
}
int qry(int p,int l,int r) {
	if(l==r)return l;
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	if(siz[p<<1]<=mid-l)return qry(p<<1,l,mid);
	return qry(p<<1|1,mid+1,r);
}
int op[N];
long long L[N],R[N];
signed main() {
	memset(tag_cov,-1,sizeof(tag_cov));
	int q,m;
	scanf("%d",&q);
	c[m=1]=1;
	for(int i=1;i<=q;i++) {
		scanf("%d%lld%lld",op+i,L+i,R+i);
		c[++m]=L[i];
		c[++m]=R[i]+1;
	}
	sort(c+1,c+m+1);
	m=unique(c+1,c+m+1)-c-1;
	for(int i=1;i<=q;i++) {
		if(op[i]==1)mdf_cov(1,1,m,ub(L[i]),ub(R[i]),1);
		if(op[i]==2)mdf_cov(1,1,m,ub(L[i]),ub(R[i]),0);
		if(op[i]==3)mdf_xor(1,1,m,ub(L[i]),ub(R[i]));
		printf("%lld\n",c[qry(1,1,m)]);
	}
	return 0;
}