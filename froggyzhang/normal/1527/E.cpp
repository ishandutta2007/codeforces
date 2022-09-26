#include<bits/stdc++.h>
using namespace std;
#define N 35005
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3fll;
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
int n,m,a[N],pre[N];
ll ans,dp[105][N];
struct Segment_Tree{
	struct node{
		int l,r;
		ll mn,add;
		inline void Add(ll d){
			add+=d,mn+=d;
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
		tree[i].mn=min(tree[ls].mn,tree[rs].mn);
	}
	inline void build(int i,int l,int r,int x){
		tree[i].l=l;
		tree[i].r=r;
		tree[i].add=0;
		if(l==r){
			tree[i].mn=dp[x][l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid,x);
		build(rs,mid+1,r,x);
		update(i);
	}
	void Change(int i,int l,int r,int d){
		if(tree[i].l>=l&&tree[i].r<=r){
			tree[i].Add(d);
			return;
		}
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)Change(ls,l,r,d);
		if(r>mid)Change(rs,l,r,d);
		update(i);
	}
	ll Query(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].mn;
		}
		pushdown(i);
		ll mn=inf;
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)mn=min(mn,Query(ls,l,r));
		if(r>mid)mn=min(mn,Query(rs,l,r));
		return mn;
	}
}T;
int main(){
	n=read(),m=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)a[i]=read();
	ans=inf;
	for(int i=1;i<=m;++i){
		T.build(1,0,n,i-1);
		memset(pre,0,sizeof(pre));
		for(int j=1;j<=n;++j){
			if(pre[a[j]])T.Change(1,0,pre[a[j]]-1,j-pre[a[j]]);
			pre[a[j]]=j;
			dp[i][j]=T.Query(1,0,j-1);
		}
		ans=min(ans,dp[i][n]);
	}
	printf("%lld\n",ans);
	return 0;
}