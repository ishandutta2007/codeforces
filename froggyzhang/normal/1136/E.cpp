#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=99999999;
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
ll n,a[N],s[N],g[N],b[N],q,m;
struct node{
	int l,r;
	ll cov,sum,mx;
	node(){cov=-inf;}
}tree[N<<2];
void update(int i){
	tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].sum=tree[i].mx=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	update(i);
}
void pushdown(int i){
	if(tree[i].cov!=-inf){
		tree[i*2].cov=tree[i*2+1].cov=tree[i].cov;
		tree[i*2].mx=tree[i*2+1].mx=tree[i].cov;
		tree[i*2].sum=tree[i].cov*(tree[i*2].r-tree[i*2].l+1);
		tree[i*2+1].sum=tree[i].cov*(tree[i*2+1].r-tree[i*2+1].l+1);
		tree[i].cov=-inf;
	}
}

ll ask(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].sum;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	pushdown(i);
	ll tot=0;
	if(l<=mid){
		tot+=ask(i*2,l,r);
	}
	if(r>mid){
		tot+=ask(i*2+1,l,r);
	}
	return tot;
}
int find(int i,int l,int r,ll v){
	if(tree[i].l==tree[i].r)return tree[i].l;
	pushdown(i);
	if(tree[i*2].r>=l&&tree[i*2].mx>=v)return find(i*2,l,r,v);
	if(tree[i*2+1].l<=r&&tree[i*2+1].mx>=v)return find(i*2+1,l,r,v);
	return n+1;
}
void Cover(int i,int l,int r,ll v){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].cov=v;
		tree[i].sum=(tree[i].r-tree[i].l+1)*v;
		tree[i].mx=v;
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Cover(i*2,l,r,v);
	}
	if(r>mid){
		Cover(i*2+1,l,r,v);
	}
	update(i);
}
void _plus(int x,ll v){
	ll val=ask(1,x,x)+v;
	int r=find(1,x+1,n,val)-1;
	Cover(1,x,r,val);
}
ll Sum(int x,int y){
	return ask(1,x,y)+s[y-1]-s[x-2];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		int x;
		if(i<n)x=read();
		else x=0;
		g[i]=g[i-1]+x;
		s[i]=s[i-1]+g[i];
		b[i]=a[i]-g[i-1];
	}
	build(1,1,n);
	m=read();
	for(int i=1;i<=m;i++){
		char ch[3];
		scanf("%s",ch+1);
		int x=read(),y=read();
		if(ch[1]=='+'){
			_plus(x,y);
		}
		else{
			cout<<Sum(x,y)<<endl;
		}
	}
	return 0;
}