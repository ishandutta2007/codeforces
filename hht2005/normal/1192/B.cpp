#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef long long ll;
typedef pair<int,ll> pii;
vector<pii>S[N];
ll C[N],dis[N],c[N];
int top[N],fa[N],son[N],siz[N],dfn[N],pos[N],dep[N],dfns;
int A[N<<2],B[N<<2],a[N],b[N],n;
void add(int x,ll v) {
	for(int i=x;i<=n;i+=i&-i)
		C[i]+=v;
}
ll qry(int x) {
	ll sum=dis[x];
	x=dfn[x];
	for(int i=x;i;i-=i&-i)
		sum+=C[i];
	return sum;
}
void dfs0(int x) {
	siz[x]=1;
	for(pii i:S[x]) {
		int y=i.first;
		ll w=i.second;
		if(y==fa[x])continue;
		dis[y]=dis[fa[y]=x]+w;
		dep[y]=dep[x]+1;
		dfs0(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void dfs1(int x) {
	pos[dfn[x]=++dfns]=x;
	if(son[fa[x]]==x)top[x]=top[fa[x]];
	else top[x]=x;
	for(pii i:S[x]) {
		int y=i.first;
		if(y==fa[x])continue;
		dfs1(y);
	}
}
ll get_dis(int a,int b) {
	ll sum=qry(a)+qry(b);
	while(top[a]!=top[b]) {
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b])swap(a,b);
	return sum-2*qry(a);
}
void push_up(int p) {
	ll Max=get_dis(A[p]=A[p<<1],B[p]=B[p<<1]),t;
	if(Max<(t=get_dis(A[p<<1],A[p<<1|1])))A[p]=A[p<<1],B[p]=A[p<<1|1],Max=t;
	if(Max<(t=get_dis(A[p<<1],B[p<<1|1])))A[p]=A[p<<1],B[p]=B[p<<1|1],Max=t;
	if(Max<(t=get_dis(B[p<<1],A[p<<1|1])))A[p]=B[p<<1],B[p]=A[p<<1|1],Max=t;
	if(Max<(t=get_dis(B[p<<1],B[p<<1|1])))A[p]=B[p<<1],B[p]=B[p<<1|1],Max=t;
	if(Max<(t=get_dis(A[p<<1|1],B[p<<1|1])))A[p]=A[p<<1|1],B[p]=B[p<<1|1],Max=t;
}
void build(int p,int l,int r) {
	if(l==r) {
		A[p]=B[p]=pos[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	push_up(p);
}
void updata(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return;
	int mid=(l+r)>>1;
	if(x<=mid)updata(p<<1,l,mid,x,y);
	if(y>mid)updata(p<<1|1,mid+1,r,x,y);
	push_up(p);
}
int main() {
	int m,d;
	ll las=0,e,W;
	scanf("%d%d%lld",&n,&m,&W);
	for(int i=1;i<n;i++) {
		scanf("%d%d%lld",a+i,b+i,c+i);
		S[a[i]].push_back(make_pair(b[i],c[i]));
		S[b[i]].push_back(make_pair(a[i],c[i]));
	}
	dfs0(1);
	dfs1(1);
	build(1,1,n);
	while(m--) {
		scanf("%d%lld",&d,&e);
		d=(d+las)%(n-1)+1;
		e=(e+las)%W;
		if(dep[a[d]]<dep[b[d]])swap(a[d],b[d]);
		add(dfn[a[d]],e-c[d]);
		add(dfn[a[d]]+siz[a[d]],c[d]-e);
		c[d]=e;
		updata(1,1,n,dfn[a[d]],dfn[a[d]]+siz[a[d]]-1);
		printf("%lld\n",las=get_dis(A[1],B[1]));
	}
	return 0;
}