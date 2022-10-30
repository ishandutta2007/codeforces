#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 100050
typedef long long ll;
#define ls p<<1
#define rs p<<1|1
int mod,phi,cnt,ys[15];
ll sum[N<<2],mul[N<<2];
int a[N],n,q;
ll qp(ll x,ll y) {
	ll re=1; for(;y;y>>=1,x=x*x%mod) if(y&1) re=re*x%mod; return re;
}
struct sanae {
	int a[15]; ll num;
	void fix(int x) {
		int i;
		for(i=1;i<=cnt;i++) {
			a[i]=0;
			while(x%ys[i]==0) a[i]++,x/=ys[i];
		}
		num=x;
	}
	bool chkis() {int i;if(num!=1) return 1;for(i=1;i<=cnt;i++)if(a[i])return 1;return 0;}
	sanae operator + (const sanae &u) const {
		sanae re;
		int i;
		for(i=1;i<=cnt;i++) re.a[i]=a[i]+u.a[i];
		re.num=num*u.num%mod;
		return re;
	}
	sanae operator - (const sanae &u) const {
		sanae re;
		int i;
		for(i=1;i<=cnt;i++) re.a[i]=a[i]-u.a[i];
		re.num=num*qp(u.num,phi-1)%mod;
		return re;
	}
	void prt() {
		int i;
		for(i=1;i<=cnt;i++) printf("%d ",a[i]); printf("%lld\n",num);
	}
}tag[N<<2],tt,Div,Mul;
int getphi(int x) {
	int i,re=x;
	for(i=2;i*i<=x;i++) {
		if(x%i==0) {
			re=re/i*(i-1); while(x%i==0) x/=i;
		}
	}if(x!=1) re=re/x*(x-1);
	return re;
}
inline void giv(int p,int v) {
	mul[p]=mul[p]*v%mod;
	sum[p]=sum[p]*v%mod;
	tag[p]=tag[p]+tt;
}
inline void pushdown(int p) {
	if(tag[p].chkis()||mul[p]!=1) {
		tt=tag[p];
		giv(ls,mul[p]); giv(rs,mul[p]);
		mul[p]=1;
		tag[p].fix(1);
	}
}
inline void pushup(int p) {
	sum[p]=(sum[ls]+sum[rs])%mod;
}
void build(int l,int r,int p) {
	mul[p]=1;
	tag[p].num=1;
	if(l==r) {
		tag[p].fix(a[l]);
		sum[p]=a[l]%mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls),build(mid+1,r,rs);
	pushup(p);
}
void update(int l,int r,int x,int y,int v,int p) {
	if(x<=l&&y>=r) {
		tt=Mul; giv(p,v); return ;
	}int mid=(l+r)>>1; pushdown(p);
	if(x<=mid) update(l,mid,x,y,v,ls);
	if(y>mid) update(mid+1,r,x,y,v,rs);
	pushup(p);
}
int query(int l,int r,int x,int y,int p) {
	if(x<=l&&y>=r) return sum[p];
	int mid=(l+r)>>1,re=0; pushdown(p);
	if(x<=mid) re+=query(l,mid,x,y,ls);
	if(y>mid) re+=query(mid+1,r,x,y,rs);
	return re%mod; 
}
void upd2(int l,int r,int x,int p) {
	if(l==r) {
		int i;
		sum[p]=1;
		tag[p]=tag[p]-Div;
		// tag[p].prt();
		for(i=1;i<=cnt;i++) sum[p]=sum[p]*qp(ys[i],tag[p].a[i])%mod;
		sum[p]=sum[p]*tag[p].num%mod;
		return ;
	}
	int mid=(l+r)>>1; pushdown(p);
	if(x<=mid) upd2(l,mid,x,ls);
	else upd2(mid+1,r,x,rs);
	pushup(p);
}
int main() {
	scanf("%d%d",&n,&mod);
	int i,x=mod;
	phi=getphi(mod);
	for(i=2;i*i<=x;i++) {
		if(x%i==0) {
			ys[++cnt]=i; while(x%i==0) x/=i;
		}
	}
	if(x!=1) ys[++cnt]=x;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	scanf("%d",&q);
	int opt,y;
	while(q--) {
		scanf("%d",&opt);
		int l,r;
		if(opt==1) {
			scanf("%d%d%d",&l,&r,&x);
			Mul.fix(x); 
			update(1,n,l,r,x,1);
		}else if(opt==2) {
			scanf("%d%d",&x,&y);
			Div.fix(y);
			upd2(1,n,x,1);
		}else {
			scanf("%d%d",&l,&r); printf("%d\n",query(1,n,l,r,1));
		}
	}
}