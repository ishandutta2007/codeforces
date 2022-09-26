#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,Q,a[N],tot,In[N],Out[N],cnt,head[N];
ll W,dep[N],Val[N],Id[N],lastans;
struct Edge{
	int to,nxt;
	ll val;
}edge[N];
void add(int a,int b,ll c){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	a[++tot]=u,In[u]=tot;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dep[v]=dep[u]+edge[i].val;
		Id[(i+1)>>1]=v;
		Val[v]=edge[i].val;
		dfs(v,u);
		a[++tot]=u;
	}
	Out[u]=tot;
}
struct node{
	int l,r;
	ll A,AB,BA,B,ABA,add;
	inline void Add(ll d){
		A+=d;
		B-=(d<<1);
		AB-=d,BA-=d;
		add+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void pushdown(int i){
	if(tree[i].add){
		tree[ls].Add(tree[i].add);
		tree[rs].Add(tree[i].add);
		tree[i].add=0;
	}
}
inline void update(int i){
	tree[i].A=max(tree[ls].A,tree[rs].A);
	tree[i].B=max(tree[ls].B,tree[rs].B);
	tree[i].AB=max(max(tree[ls].AB,tree[rs].AB),tree[ls].A+tree[rs].B);
	tree[i].BA=max(max(tree[ls].BA,tree[rs].BA),tree[ls].B+tree[rs].A);
	tree[i].ABA=max(max(tree[ls].ABA,tree[rs].ABA),max(tree[ls].AB+tree[rs].A,tree[ls].A+tree[rs].BA));
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].A=dep[a[l]];
		tree[i].B=-2*dep[a[l]];
		tree[i].AB=tree[i].BA=-dep[a[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
inline void Change(int i,int l,int r,ll w){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(w);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,w);
	}
	if(r>mid){
		Change(rs,l,r,w);
	}
	update(i);
}
int main(){
	n=read(),Q=read(),W=read();
	for(int i=2;i<=n;++i){
		int u=read(),v=read();
		ll w=read();
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	build(1,1,tot);
	while(Q--){
		int u=Id[(read()+lastans)%(n-1)+1];
		ll w=(read()+lastans)%W;
		Change(1,In[u],Out[u],w-Val[u]);
		Val[u]=w;
		printf("%I64d\n",lastans=tree[1].ABA);
	}
	return 0;
}