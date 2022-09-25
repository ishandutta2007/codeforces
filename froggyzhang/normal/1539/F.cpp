#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int inf=0x3f3f3f3f;
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
int n,ans[N];
vector<int> p[N];
struct Segment_Tree{
	struct node{
		array<int,2> mn;
		array<int,2> mx;
		int add;
		inline void Add(int d){
			add+=d;
			for(int i=0;i<=1;++i)mn[i]+=d,mx[i]+=d;
		}
		node(){mn[0]=mn[1]=inf,mx[0]=mx[1]=-inf,add=0;}
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		for(int k=0;k<=1;++k){
			tree[i].mn[k]=min(tree[ls].mn[k],tree[rs].mn[k]);
			tree[i].mx[k]=max(tree[ls].mx[k],tree[rs].mx[k]);	
		}	
	}
	void build(int i,int L,int R){
		if(L==R){
			tree[i].mn[L&1]=tree[i].mx[L&1]=L;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(i);
	}
	inline void pushdown(int i){
		if(tree[i].add){
			tree[ls].Add(tree[i].add);
			tree[rs].Add(tree[i].add);
			tree[i].add=0;
		}
	}
	void Plus(int i,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			tree[i].Add(d);
			return;
		}
		pushdown(i);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(i);	
	}
	pair<array<int,2>,array<int,2> > Query(int i,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return make_pair(tree[i].mn,tree[i].mx);
		}
		pushdown(i);
		int mid=(L+R)>>1;
		pair<array<int,2>,array<int,2> > ans;
		ans.first[0]=ans.first[1]=inf;
		ans.second[0]=ans.second[1]=-inf;
		if(l<=mid){
			auto t=Query(ls,L,mid,l,r);
			for(int k=0;k<=1;++k){
				ans.first[k]=min(ans.first[k],t.first[k]);
				ans.second[k]=max(ans.second[k],t.second[k]);
			}
		}
		if(r>mid){
			auto t=Query(rs,mid+1,R,l,r);
			for(int k=0;k<=1;++k){
				ans.first[k]=min(ans.first[k],t.first[k]);
				ans.second[k]=max(ans.second[k],t.second[k]);
			}
		}
		return ans;
	}
}T;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[read()].push_back(i);
	}
	T.build(1,0,n);
	for(int i=1;i<=n;++i){
		for(auto x:p[i]){
			auto [mnl,mxl]=T.Query(1,0,n,0,x-1);
			auto [mnr,mxr]=T.Query(1,0,n,x,n);
			ans[x]=max(ans[x],(mxr[0]-mnl[0])/2);
			ans[x]=max(ans[x],(mxr[1]-mnl[1])/2);
			ans[x]=max(ans[x],(mxr[0]-mnl[1])/2);
			ans[x]=max(ans[x],(mxr[1]-mnl[0])/2);
		}
		for(auto x:p[i]){
			T.Plus(1,0,n,x,n,-2);
		}
		for(auto x:p[i]){
			auto [mnl,mxl]=T.Query(1,0,n,0,x-1);
			auto [mnr,mxr]=T.Query(1,0,n,x,n);
			ans[x]=max(ans[x],(mxl[0]-mnr[0])/2-1);
			ans[x]=max(ans[x],(mxl[1]-mnr[1])/2-1);
			ans[x]=max(ans[x],(mxl[0]-mnr[1])/2);
			ans[x]=max(ans[x],(mxl[1]-mnr[0])/2);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);	
	}
	return 0;
}