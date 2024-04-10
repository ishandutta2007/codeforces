#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,a[N],p[N];
struct Segment_Tree{
	struct node{
		int l,r;
		ll mn;
		ll add;
		inline void Add(ll d){
			mn+=d,add+=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mn=min(tree[ls].mn,tree[rs].mn);
	}
	inline void pushdown(int i){
		if(tree[i].add){
			tree[ls].Add(tree[i].add);
			tree[rs].Add(tree[i].add);
			tree[i].add=0;
		}
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void Plus(int i,int l,int r,int d){
		if(tree[i].l>=l&&tree[i].r<=r)return tree[i].Add(d);
		int mid=(tree[i].l+tree[i].r)>>1;
		pushdown(i);
		if(l<=mid)Plus(ls,l,r,d);
		if(r>mid)Plus(rs,l,r,d);
		update(i);
	}
	ll Ask(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r)return tree[i].mn;
		ll mn=1e18;
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)mn=min(mn,Ask(ls,l,r));
		if(r>mid)mn=min(mn,Ask(rs,l,r));
		return mn;
	}
}T;
int ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;
	}
	T.build(1,1,n);
	sort(p+1,p+n+1,[&](int i,int j){return a[i]>a[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(a[u]+T.Ask(1,u,n)>=0)T.Plus(1,u,n,a[u]),++ans;
	}
	printf("%d\n",ans);
	return 0;
}