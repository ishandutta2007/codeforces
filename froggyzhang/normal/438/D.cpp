#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,a[N];
struct node{
	int mx,l,r;
	ll sum;
}tree[N<<2];
#define ls (i<<1)
#define rs (i<<1|1)
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
	ll ans=0;
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		ans+=Query(ls,l,r);
	}
	if(r>mid){
		ans+=Query(rs,l,r);
	}
	return ans;
}
void Change(int i,int pos,int d){
	if(tree[i].l==tree[i].r){
		a[tree[i].l]=tree[i].mx=tree[i].sum=d;
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid){
		Change(ls,pos,d);
	}
	else{
		Change(rs,pos,d);
	}
	update(i);
}
void Modulo(int i,int l,int r,int d){
	if(tree[i].mx<d)return;
	if(tree[i].l==tree[i].r){
		tree[i].mx=tree[i].sum=(a[tree[i].l]%=d);
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Modulo(ls,l,r,d);
	}
	if(r>mid){
		Modulo(rs,l,r,d);
	}
	update(i);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read(); 
	}
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int opt=read();
		if(opt==1){
			int l=read(),r=read();
			printf("%lld\n",Query(1,l,r));
		}
		else if(opt==2){
			int l=read(),r=read(),d=read();
			Modulo(1,l,r,d);
		} 
		else{
			int pos=read(),d=read();
			Change(1,pos,d);
		}
	}
	return 0;
}