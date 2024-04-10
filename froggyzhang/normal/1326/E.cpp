#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#pragma GCC optimize(3)
#define N 300030
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
int n,p[N],q[N],pos[N];
struct node{
	int l,r,mx,add;
	inline void Add(int d){
		mx+=d,add+=d;
	}
}tree[N<<2];
#define ls (i<<1)
#define rs (i<<1|1)
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
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].mx=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void Change(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(d);
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
int main(){
//	freopen("E.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
		pos[p[i]]=i;
	}
	for(int i=1;i<=n;++i)q[i]=read();
	build(1,1,n);
	int now=n;
	Change(1,1,pos[n],1);
	for(int i=1;i<=n;++i){
		printf("%d ",now);
		if(i==n)break;
		Change(1,1,q[i],-1);
		while(tree[1].mx<=0){
			Change(1,1,pos[--now],1);
		}
	}
	return 0;
}