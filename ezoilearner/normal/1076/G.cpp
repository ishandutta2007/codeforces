#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
int n,q,m;ll a[N];
struct Node{
	int sg[7];
	Node operator+(const Node&b)const{
		Node res;
		for(int i=1;i<=m+1;++i)res.sg[i]=sg[b.sg[i]];
		return res;
	}
};
struct TreeNode{int rev_tag;Node dp[2];}t[N<<2];
inline void pushup(int x){
	t[x].dp[1]=t[x<<1].dp[1]+t[x<<1|1].dp[1];
	t[x].dp[0]=t[x<<1].dp[0]+t[x<<1|1].dp[0];
}
inline void pushdown(int x){
	if(!t[x].rev_tag)return;
	t[x<<1].rev_tag^=1,t[x<<1|1].rev_tag^=1;
	swap(t[x<<1].dp[0],t[x<<1].dp[1]);
	swap(t[x<<1|1].dp[0],t[x<<1|1].dp[1]); 
	t[x].rev_tag=0;
}
inline void build(int x,int l,int r){
	if(l==r){
		for(int i=1;i<=m;++i)
			t[x].dp[1].sg[i]=t[x].dp[0].sg[i]=i+1;
		t[x].dp[1].sg[m+1]=1+m*a[l],t[x].dp[0].sg[m+1]=m+1-m*a[l];
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	pushup(x);
}
inline void update(int x,int l,int r,int L,int R){
	if(L<=l&&R>=r)return t[x].rev_tag^=1,swap(t[x].dp[0],t[x].dp[1]),void();
	int mid=l+r>>1;pushdown(x);
	if(L<=mid)update(x<<1,l,mid,L,R);
	if(R>mid)update(x<<1|1,mid+1,r,L,R);
	pushup(x);
}
inline Node query(int x,int l,int r,int L,int R){
	if(L<=l&&R>=r)return t[x].dp[1];
	int mid=l+r>>1;pushdown(x);
	if(R<=mid)return query(x<<1,l,mid,L,R);
	if(L>mid)return query(x<<1|1,mid+1,r,L,R);
	return query(x<<1,l,mid,L,R)+query(x<<1|1,mid+1,r,L,R);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),a[i]=a[i]&1^1;
	build(1,1,n);
	while(q--){
		int type,l,r;ll v;
		scanf("%d%d%d",&type,&l,&r);
		if(type&1){
			scanf("%lld",&v);
			if(v&1)update(1,1,n,l,r);
		}
		else printf("%d\n",(query(1,1,n,l,r).sg[m+1]==1)+1);
	}
	return 0;
}