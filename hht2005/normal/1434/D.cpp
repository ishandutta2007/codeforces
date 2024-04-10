#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],w[maxn<<1],S,T,tot,n;
int a[maxn],b[maxn],dep[maxn];
void add(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
struct Tree {
	int r[maxn<<2],o[maxn<<2],e[maxn<<2],dep[maxn],f[maxn],dfn[maxn],pos[maxn],siz[maxn],dfns;
	void tag(int p) {
		r[p]^=1;
		swap(o[p],e[p]);
	}
	void pushdown(int p) {
		if(r[p]) {
			tag(p<<1);
			tag(p<<1|1);
			r[p]=0;
		}
	}
	void pushup(int p) {
		o[p]=max(o[p<<1],o[p<<1|1]);
		e[p]=max(e[p<<1],e[p<<1|1]);
	}
	void reverse(int p,int l,int r,int x,int y) {
		if(x<=l&&r<=y)return tag(p);
		pushdown(p);
		int mid=(l+r)>>1;
		if(x<=mid)reverse(p<<1,l,mid,x,y);
		if(y>mid)reverse(p<<1|1,mid+1,r,x,y);
		pushup(p);
	}
	void build(int p,int l,int r) {
		if(l==r) {
			if(f[pos[l]])o[p]=dep[pos[l]];
			else e[p]=dep[pos[l]];
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void dfs(int x,int fa) {
		pos[dfn[x]=++dfns]=x;
		siz[x]=1;
		for(int i=hea[x];i;i=nxt[i])
			if(to[i]!=fa) {
				dep[to[i]]=dep[x]+1;
				f[to[i]]=f[x]^w[i];
				dfs(to[i],x);
				siz[x]+=siz[to[i]];
			}
	}
	void reverse(int p,int q) {
		if(dep[p]<dep[q])swap(p,q);
		reverse(1,1,n,dfn[p],dfn[p]+siz[p]-1);
	}
}A,B;
void dfs(int x,int fa) {
	dep[x]=dep[fa]+1;
	if(!S||dep[S]<dep[x])S=x;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa)dfs(to[i],x);
}
int main() {
	int q,c;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",a+i,b+i,&c);
		add(a[i],b[i],c);
		add(b[i],a[i],c);
	}
	dfs(1,0);
	T=S,S=0;
	dfs(T,0);
	A.dfs(S,0);
	B.dfs(T,0);
	A.build(1,1,n);
	B.build(1,1,n);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&c);
		A.reverse(a[c],b[c]);
		B.reverse(a[c],b[c]);
		printf("%d\n",max(A.e[1],B.e[1]));
	}
	return 0;
}