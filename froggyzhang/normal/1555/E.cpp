#include<bits/stdc++.h>
using namespace std;
#define N 1000100
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
int n,m;
struct Seg{
	int l,r,w;
	friend bool operator < (const Seg &a,const Seg &b){
		return a.w<b.w;
	}
}a[N];
class Segment_Tree{
public:
	struct node{
		int mn,add;
		inline void Add(int d){
			add+=d,mn+=d;
		}
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		tree[u].mn=min(tree[ls].mn,tree[rs].mn);
	}
	inline void pushdown(int u){
		if(tree[u].add){
			tree[ls].Add(tree[u].add);
			tree[rs].Add(tree[u].add);
			tree[u].add=0;
		}
	}
	void Change(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r)return tree[u].Add(d);	
		int mid=(L+R)>>1;
		pushdown(u);
		if(l<=mid)Change(ls,L,mid,l,r,d);
		if(r>mid)Change(rs,mid+1,R,l,r,d);
		update(u);
	}
}T;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read(),a[i].w=read();
	}
	sort(a+1,a+n+1);
	int ans=1e9;
	a[0].w=-1e9;
	for(int i=1,j=1;i<=n;++i){
		T.Change(1,1,m-1,a[i].l,a[i].r-1,1);
		while(T.tree[1].mn>0)T.Change(1,1,m-1,a[j].l,a[j].r-1,-1),++j;
		ans=min(ans,a[i].w-a[j-1].w);
	}
	printf("%d\n",ans);
	return 0;
}