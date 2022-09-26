#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 400040
inline int read(){
	int x=0,f=1;
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
int b[N],len,n,dp[N];
struct Seg{
	int l,r,t;
	bool operator <(const Seg b)const{
		return r<b.r;
	}
}a[N];
struct SGT{
	struct node{
		int mx,add,l,r;
		void Add(int d){
			add+=d;
			mx+=d;
		}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		tree[i].add=tree[i].mx=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
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
	void Add(int i,int l,int r,int d){
		if(tree[i].l>=l&&tree[i].r<=r){
			tree[i].Add(d);
			return;
		}
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid){
			Add(ls,l,r,d);
		}
		if(r>mid){
			Add(rs,l,r,d);
		}
		update(i);
	}
	int Query(int i,int l,int r){
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].mx;
		}
		int ans=0;
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid){
			ans=max(ans,Query(ls,l,r));
		}
		if(r>mid){
			ans=max(ans,Query(rs,l,r));
		}
		return ans;
	}
}T[2];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read(),a[i].t=read()-1;
		b[++len]=a[i].l,b[++len]=a[i].r;
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+len+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+len+1,a[i].r)-b;
	}
	sort(a+1,a+n+1);
	T[0].build(1,0,len);
	T[1].build(1,0,len);
	int pos=1;
	for(int i=1;i<=len;++i){
		while(pos<=n&&a[pos].r==i){
			T[a[pos].t].Add(1,0,a[pos].l-1,1);
			++pos;
		}
		dp[i]=max(T[0].Query(1,0,i-1),T[1].Query(1,0,i-1));
		T[0].Add(1,i,i,dp[i]),T[1].Add(1,i,i,dp[i]);
	}
	printf("%d\n",dp[len]);
	return 0;
}