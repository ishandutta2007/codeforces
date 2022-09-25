#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],f[N],dfn[N],num,siz[N];
vector<int> G[N];
void dfs(int u){
	dfn[u]=++num;
	siz[u]=1;
	for(auto v:G[u]){
		dfs(v);
		siz[u]+=siz[v];
	}
}
class Segment_Tree{
public:
	struct node{
		int mx,add;
		inline void Add(int d){
			mx+=d,add+=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mx=max(tree[ls].mx,tree[rs].mx);
	}
	inline void pushdown(int i){
		if(tree[i].add){
			tree[ls].Add(tree[i].add);
			tree[rs].Add(tree[i].add);
			tree[i].add=0;
		}
	}
	void Plus(int i,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r)return tree[i].Add(d);
		int mid=(L+R)>>1;
		pushdown(i);
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(i);
	}	
}T;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();	
	}
	for(int i=n;i>=1;--i){
		static int st[N],top;
		while(top&&a[i]>=a[st[top]])--top;
		if(top)f[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		if(f[i])G[f[i]].push_back(i);
	}
	for(int i=n;i>=1;--i){
		if(!dfn[i])dfs(i);	
	}
	for(int i=1;i<m;++i){
		T.Plus(1,1,n,dfn[i],dfn[i]+siz[i]-1,1);	
	}
	for(int i=m;i<=n;++i){
		T.Plus(1,1,n,dfn[i],dfn[i]+siz[i]-1,1);
		printf("%d ",T.tree[1].mx);
		T.Plus(1,1,n,dfn[i-m+1],dfn[i-m+1],-inf);
	}
	return 0;
}