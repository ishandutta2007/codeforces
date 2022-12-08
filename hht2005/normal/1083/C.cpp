#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int pos[N],p[N];
int top[N],fa[N],son[N],siz[N],dep[N],dfn[N],dfns;
int lca(int a,int b) {
	if(dep[a]<dep[b])swap(a,b);
	if(dfn[b]<=dfn[a]&&dfn[a]<=dfn[b]+siz[b]-1)return b;
	while(top[a]!=top[b]) {
		if(dep[top[a]]<dep[top[b]])
			swap(a,b);
		a=fa[top[a]];
	}
	return dep[a]<dep[b]?a:b;
}
inline int chk(int s,int t,int p,int x,int S,int T) {
	return (S==p&&T==x)||(T==p&&S==x);
}
inline int check(int s,int t,int x,int y,int p,int sx,int tx,int sy,int ty) {
	return chk(s,t,p,x,sx,tx)&&chk(s,t,p,y,sy,ty);
}
struct node {
	int A,B,C;
}val[N<<2],Sum;
inline node operator+(const node &x,const node &y) {
	node z;
	if(!x.C||!y.C) {
		z.A=z.B=z.C=0;
		return z;
	}
	int a=x.A,b=x.B,c=y.A,d=y.B;
	z.A=z.B=z.C=0;
	int ab=lca(a,b),ac=lca(a,c),ad=lca(a,d);
	int bc=lca(b,c),bd=lca(b,d),cd=lca(c,d);
	if(!z.C&&check(a,b,c,d,ab,ac,bc,ad,bd))z.A=a,z.B=b,z.C=1;
	if(!z.C&&check(a,c,b,d,ac,ab,bc,ad,cd))z.A=a,z.B=c,z.C=1;
	if(!z.C&&check(a,d,b,c,ad,ab,bd,ac,cd))z.A=a,z.B=d,z.C=1;
	if(!z.C&&check(b,c,a,d,bc,ab,ac,bd,cd))z.A=b,z.B=c,z.C=1;
	if(!z.C&&check(b,d,a,c,bd,ab,ad,bc,cd))z.A=b,z.B=d,z.C=1;
	if(!z.C&&check(c,d,a,b,cd,ac,ad,bc,bd))z.A=c,z.B=d,z.C=1;
	return z;
}
void build(int p,int l,int r) {
	if(l==r) {
		val[p].A=pos[l];
		val[p].B=pos[r];
		val[p].C=1;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	val[p]=val[p<<1]+val[p<<1|1];
}
void add(int p,int l,int r,int x) {
	if(l==r) {
		val[p].A=pos[l];
		val[p].B=pos[r];
		val[p].C=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x);
	else add(p<<1|1,mid+1,r,x);
	val[p]=val[p<<1]+val[p<<1|1];
}
void dfs1(int x) {
	dfn[x]=++dfns;
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	for(int y:S[x]) {
		fa[y]=x;
		dfs1(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void dfs2(int x) {
	if(son[fa[x]]==x)
		top[x]=top[fa[x]];
	else top[x]=x;
	for(int y:S[x])
		dfs2(y);
}
int qry(int p,int l,int r) {
	if(val[1].C==1)return r+1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(l==1) {
		if(val[p<<1].C) {
			Sum=val[p<<1];
			return qry(p<<1|1,mid+1,r);
		} else return qry(p<<1,l,mid);
	} else {
		if((Sum+val[p<<1]).C) {
			Sum=Sum+val[p<<1];
			return qry(p<<1|1,mid+1,r);
		} else return qry(p<<1,l,mid);
	}
}
int main() {
	int n,f,q,opt,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",p+i);
		p[i]++;
		pos[p[i]]=i;
	}
	for(int i=2;i<=n;i++) {
		scanf("%d",&f);
		S[f].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	build(1,1,n);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&opt);
		if(opt==1) {
			scanf("%d%d",&x,&y);
			swap(p[x],p[y]);
			swap(pos[p[x]],pos[p[y]]);
			add(1,1,n,p[x]);
			add(1,1,n,p[y]);
		} else printf("%d\n",qry(1,1,n)-1);
	}
	return 0;
}