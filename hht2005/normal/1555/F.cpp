#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int dfn[N],siz[N],dep[N],top[N],son[N],fa[N],sum[N],dfns;
vector<int>S[N];
void dfs0(int x) {
	siz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for(int Y:S[x]) {
		int y=Y>>1,w=Y&1;
		if(y==fa[x])continue;
		sum[y]=sum[x]+w;
		fa[y]=x;
		dfs0(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void dfs1(int x) {
	dfn[x]=++dfns;
	if(son[fa[x]]==x)top[x]=top[fa[x]];
	else top[x]=x;
	if(son[x])dfs1(son[x]);
	for(int Y:S[x]) {
		int y=Y>>1;
		if(y==fa[x]||y==son[x])continue;
		dfs1(y);
	}
}
int lca(int a,int b) {
	while(top[a]!=top[b])
		if(dep[top[a]]>dep[top[b]])a=fa[top[a]];
		else b=fa[top[b]];
	return dep[a]<dep[b]?a:b;
}
int a[N],b[N],c[N],val[N<<2],tag[N<<2],n;
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void push_down(int p) {
	if(tag[p]) {
		val[p<<1]=val[p<<1|1]=1;
		tag[p<<1]=tag[p<<1|1]=1;
		tag[p]=0;
	}
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return val[p];
	push_down(p);
	int mid=(l+r)>>1,sum=0;
	if(x<=mid)sum+=qry(p<<1,l,mid,x,y);
	if(y>mid)sum+=qry(p<<1|1,mid+1,r,x,y);
	return sum;
}
int qry(int a,int b,int c) {
	int s=sum[a]+sum[b];
	while(top[a]!=top[b]) {
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		if(qry(1,1,n,dfn[top[a]],dfn[a]))return 0;
		a=fa[top[a]];
	}
	if(dep[a]<dep[b])swap(a,b);
	if(a!=b&&qry(1,1,n,dfn[b]+1,dfn[a]))return 0;
	return (s-2*sum[b]+c)%2;
}
void cover(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		tag[p]=val[p]=1;
		return;
	}
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)cover(p<<1,l,mid,x,y);
	if(y>mid)cover(p<<1|1,mid+1,r,x,y);
	val[p]=val[p<<1]+val[p<<1|1];
}
void cover(int a,int b) {
	while(top[a]!=top[b]) {
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		cover(1,1,n,dfn[top[a]],dfn[a]);
		a=fa[top[a]];
	}
	if(dep[a]<dep[b])swap(a,b);
	if(a!=b)cover(1,1,n,dfn[b]+1,dfn[a]);
}
int main() {
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,c+i);
		if(get(a[i])==get(b[i]))continue;
		S[a[i]].push_back(b[i]*2+c[i]);
		S[b[i]].push_back(a[i]*2+c[i]);
		fa[fa[a[i]]]=fa[b[i]];
		a[i]=b[i]=0;
	}
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++) {
		if(dfn[i])continue;
		dfs0(i);
		dfs1(i);
	}
	for(int i=1;i<=m;i++) {
		if(a[i]==b[i]) {
			puts("YES");
			continue;
		}
		if(qry(a[i],b[i],c[i])) {
			cover(a[i],b[i]);
			puts("YES");
		} else puts("NO");
	}
	return 0;
}