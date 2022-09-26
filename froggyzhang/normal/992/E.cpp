#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200010
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
int n,Q,a[N];
struct node{
	int l,r,mx;
	ll sum;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].mx=max(tree[ls].mx,tree[rs].mx);
	tree[i].sum=tree[ls].sum+tree[rs].sum;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].mx=tree[i].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
ll Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].sum;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	ll ans=0;
	if(l<=mid){
		ans+=Query(ls,l,r);
	}
	if(r>mid){
		ans+=Query(rs,l,r);
	}
	return ans;
}
void Change(int i,int p){
	if(tree[i].l==tree[i].r){
		tree[i].sum=tree[i].mx=a[p];
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p<=mid){
		Change(ls,p);
	}
	else{
		Change(rs,p);
	}
	update(i);
}
int Find(int i,int l,int r,ll s){
	if(tree[i].mx<s)return n+1;
	if(tree[i].l==tree[i].r)return tree[i].l;
	int mid=(tree[i].l+tree[i].r)>>1;
	int ans=n+1;
	if(l<=mid){
		ans=min(ans,Find(ls,l,r,s));
		if(ans<=n)return ans;
	}
	if(r>mid){
		ans=min(ans,Find(rs,l,r,s));
	}
	return ans;
}
int Ask(){
	int p=1;
	ll s=0;
	while(p<=n){
		int k=Find(1,p,n,s);
		if(k>n)break;
		s=Query(1,1,k);
		if(a[k]==s-a[k])return k;
		p=k+1;
	}
	return -1;
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	while(Q--){
		int p=read();
		a[p]=read();
		Change(1,p);
		printf("%d\n",Ask());
	}
	return 0;
}