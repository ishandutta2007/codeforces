#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
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
	int l,r,mn,cov;
	ll s;
	void Cover(int d){
		cov=mn=d;
		s=1LL*(r-l+1)*d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].mn=min(tree[ls].mn,tree[rs].mn);
	tree[i].s=tree[ls].s+tree[rs].s;
}
inline void pushdown(int i){
	if(tree[i].cov){
		tree[ls].Cover(tree[i].cov);
		tree[rs].Cover(tree[i].cov);
		tree[i].cov=0;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].mn=tree[i].s=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
int Get1(int i,int l,int r,int t){
	if(tree[i].mn>t)return n+1;
	if(tree[i].l==tree[i].r)return tree[i].l;
	pushdown(i);
	int ans=n+1;
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		ans=min(ans,Get1(ls,l,r,t));
		if(ans<=n)return ans;
	}
	if(r>mid){
		ans=min(ans,Get1(rs,l,r,t));
	}
	return ans;
}
int Get2(int i,int l,int &t){
	if(tree[i].l>=l&&t>=tree[i].s){
		t-=tree[i].s;
		return tree[i].r;
	}
	if(tree[i].l==tree[i].r)return n+1;
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l>mid)return Get2(rs,l,t);
	int ans=Get2(ls,l,t);
	if(ans==mid){
		int tmp=Get2(rs,l,t);
		if(tmp<=n)return tmp;
	}
	return ans;
}
void Change(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Cover(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,d);
	}
	if(r>mid){
		Change(rs,l,r,d);
	}
	update(i);
}
int Ask(int p,int t){
	int ans=0;
	while(p<=n){
		int x=Get1(1,p,n,t);
		if(x>n)break;
		int y=Get2(1,x,t);
		ans+=y-x+1;
		p=y+1;
	}
	return ans;
}
void Max(int r,int t){
	int l=Get1(1,1,r,t);
	if(l>n)return;
	Change(1,l,r,t);
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	while(Q--){
		int opt=read(),x=read(),y=read();
		if(opt==2){
			printf("%d\n",Ask(x,y));
		}
		else{
			Max(x,y);
		}
	}
	return 0;
}