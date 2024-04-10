#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=1e9;
typedef long long ll;
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
int n,p[N],a[N];
class Segment_Tree{
public:
	struct node{
		int mx,add;
		inline void Add(int d){
			mx+=d,add+=d;
		}
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		tree[u].mx=max(tree[ls].mx,tree[rs].mx);
	}
	inline void pushdown(int u){
		if(tree[u].add){
			tree[ls].Add(tree[u].add);
			tree[rs].Add(tree[u].add);
			tree[u].add=0;
		}
	}
	void build(int u,int L,int R){
		tree[u].add=0;
		if(L==R)return (void)(tree[u].mx=-inf-L);
		int mid=(L+R)>>1;
		build(ls,L,mid),build(rs,mid+1,R);
		update(u);
	}
	void Change(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			tree[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Change(ls,L,mid,l,r,d);
		if(r>mid)Change(rs,mid+1,R,l,r,d);
		update(u);
	}
	int Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u].mx;
		pushdown(u);
		int mx=-inf;
		int mid=(L+R)>>1;
		if(l<=mid)mx=max(mx,Query(ls,L,mid,l,r));
		if(r>mid)mx=max(mx,Query(rs,mid+1,R,l,r));
		return mx;
	}
}T;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[a[i]]=i;
	}
	T.build(1,1,n);
	for(int i=1;i<=n;++i){
		if(!(i&1))T.Change(1,1,n,i,i,1);
	}
	static int vis[N];
	for(int i=1;i<=n;++i)vis[i]=0;
	int ans=0;
	for(int i=n,r=n;i>=2;--i){
		int u=p[i];
		vis[u]=1;
		while(vis[r])--r;
		if(u<n)T.Change(1,1,n,u+1,n,2);
		T.Change(1,1,n,u,u,inf);
		ans=max(ans,i+T.Query(1,1,n,1,r));
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)Solve();
	return 0;
}