#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 105
#define M 40020
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
int n,m,d;
ll dp[N][M],pre[M],suf[M],ans,a[N][M],s[N][M],p[M];
struct node{
	int l,r,mx,tag;
	inline void Add(int d){
		tag+=d;
		mx+=d;
	}
}tree[M<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].mx=max(tree[ls].mx,tree[rs].mx);
}
inline void pushdown(int i){
	if(tree[i].tag){
		tree[ls].Add(tree[i].tag);
		tree[rs].Add(tree[i].tag);
		tree[i].tag=0;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].mx=p[l];
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
int Ask(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mx;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	int ans=0;
	if(l<=mid){
		ans=max(ans,Ask(ls,l,r));
	}
	if(r>mid){
		ans=max(ans,Ask(rs,l,r));
	}
	return ans;
}
int main(){
	n=read(),m=read(),d=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i+d-1<=m;i++){
		dp[1][i]=s[1][i+d-1]-s[1][i-1]+s[2][i+d-1]-s[2][i-1];
	}
	for(int i=2;i<=n;++i){
		int up=m-d+1;
		for(int j=1;j<=up;j++)pre[j]=max(pre[j-1],dp[i-1][j]);
		for(int j=up;j>=1;j--)suf[j]=max(suf[j+1],dp[i-1][j]);
		memset(tree,0,sizeof(tree));
		memset(p,0,sizeof(p));
		for(int j=1;j<=d;j++){
			p[j]=dp[i-1][j]-(s[i][d]-s[i][j-1]);
		}
		for(int j=d+1;j<=m-d+1;++j){
			p[j]=dp[i-1][j];
		}
		build(1,1,m-d+1);
		for(int j=1;j<=m-d+1;++j){
			int tmp=s[i+1][j+d-1]-s[i+1][j-1]+s[i][j+d-1]-s[i][j-1];
			if(j>1){
				Change(1,max(1,j-d),j-1,a[i][j-1]);
				Change(1,j,min(m-d+1,j+d-1),-a[i][j+d-1]);
			}
			dp[i][j]=Ask(1,max(1,j-d+1),min(j+d-1,m-d+1))+tmp;
			if(j-d>=1)dp[i][j]=max(dp[i][j],pre[j-d]+tmp);
			if(j+d<=m)dp[i][j]=max(dp[i][j],suf[j+d]+tmp);
		}
	}
	for(int i=1;i<=m-d+1;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}