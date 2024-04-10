#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 35050
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
int n,k,dp[55][N],a[N],las[N],now,pos[N];
struct node{
	int l,r,mx,add;
	inline void Add(int d){
		mx+=d;
		add+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
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
	tree[i].add=0;
	if(l==r){
		tree[i].mx=dp[now-1][l-1];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
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
int Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mx;
	}
	pushdown(i);
	int ans=0;
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		ans=max(ans,Query(ls,l,r));
	}
	if(r>mid){
		ans=max(ans,Query(rs,l,r));
	}
	return ans;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		pos[i]=las[a[i]]+1;
		las[a[i]]=i;
	}
	for(int i=1;i<=k;++i){
		now=i;
		build(1,1,n);
		for(int j=1;j<=n;++j){
			Change(1,pos[j],j,1);
			dp[i][j]=Query(1,1,j);
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}