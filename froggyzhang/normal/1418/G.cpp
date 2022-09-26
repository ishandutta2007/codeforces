#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define N 500050
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
int n,a[N];
vector<int> vec[N];
ll ans;
struct node{
	int l,r,add;
	pair<int,int> p;
	void Add(int d){
		add+=d;
		p.first+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	if(tree[ls].p.first^tree[rs].p.first){
		tree[i].p=min(tree[ls].p,tree[rs].p);
	}
	else{
		tree[i].p=make_pair(tree[ls].p.first,tree[ls].p.second+tree[rs].p.second);
	}
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
	if(l==r){
		tree[i].p=make_pair(0,1);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int l,int r,int x){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(x);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,x);
	}
	if(r>mid){
		Change(rs,l,r,x);
	}
	update(i);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		vec[i].push_back(0);
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		int k=vec[a[i]].size();
		vec[a[i]].push_back(i);
		if(k>=1)Change(1,vec[a[i]][k-1]+1,vec[a[i]][k],1);
		if(k>=3)Change(1,vec[a[i]][k-3]+1,vec[a[i]][k-2],-1);
		if(k>=4)Change(1,vec[a[i]][k-4]+1,vec[a[i]][k-3],1);
		if(!tree[1].p.first){
			ans+=tree[1].p.second-(n-i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}