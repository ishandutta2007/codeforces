#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

LL sum[maxn<<2],lazy[maxn<<2];
void update(int x,int l,int r,LL val,int L,int R){
//    if (x==1) printf("update %d %d; val=%I64d ;L,R=%d %d\n",l,r,val,L,R);
    if (l>r) return;
    if (l<=L&&R<=r) {lazy[x]+=val;sum[x]+=(R-L+1)*val;return;}
    int mid=(L+R)/2;
    if (lazy[x]){
        lazy[x<<1]+=lazy[x];lazy[x<<1|1]+=lazy[x];
        sum[x<<1]+=(mid-L+1)*lazy[x];
        sum[x<<1|1]+=(R-mid)*lazy[x];
        lazy[x]=0;
    }
    if (l<=mid) update(x<<1,l,r,val,L,mid);
    if (mid<r) update(x<<1|1,l,r,val,mid+1,R);
    sum[x]=sum[x<<1]+sum[x<<1|1];
}
LL query(int x,int l,int r,int L,int R){
//    if (x==1) printf("query %d %d ; %d %d\n",l,r,L,R);
    LL ret=0;if (l>r) return 0;
    if (l<=L&&R<=r) return sum[x];
    int mid=(L+R)/2;
    if (lazy[x]){
        lazy[x<<1]+=lazy[x];lazy[x<<1|1]+=lazy[x];
        sum[x<<1]+=(mid-L+1)*lazy[x];
        sum[x<<1|1]+=(R-mid)*lazy[x];
        lazy[x]=0;
    }
    if (l<=mid) ret+=query(x<<1,l,r,L,mid);
    if (mid<r) ret+=query(x<<1|1,l,r,mid+1,R);
    sum[x]=sum[x<<1]+sum[x<<1|1];
    return ret;
}
vector<int> edge[maxn];
int fa[maxn][27];
int in[maxn],out[maxn],tot,dep[maxn];
void dfs(int x,int f,int d){
    int i;
    fa[x][0]=f;in[x]=++tot;dep[x]=d;
    rep(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int v:edge[x]) if (v!=f) dfs(v,x,d+1);
    out[x]=tot;
}
int lca(int x,int y){
    int i;
    if (dep[x]<dep[y]) swap(x,y);
    rREP(i,20) if (dep[x]-dep[y]>=1<<i) x=fa[x][i];
    if (x==y) return x;
    rREP(i,20) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int getnthfa(int x,int k){
    int i;
    rREP(i,20) if ((k>>i)&1) x=fa[x][i];
    return x;
}
int root;
int n,m;
int a[maxn];
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }dfs(1,0,0);
    FOR(i,1,n) update(1,in[i],in[i],a[i],1,n);
//    FOR(i,1,n) printf("in,out= %d %d\n",in[i],out[i]);
    root=1;
    while (m--){
        int op,u,v,x;
        scanf("%d",&op);
        if (op==1){
            scanf("%d",&root);
        }else if (op==2){
            scanf("%d%d%d",&u,&v,&x);
            int f=lca(u,v)^lca(v,root)^lca(u,root);
            if (f==root) update(1,1,n,x,1,n);
            else if (lca(f,root)==f){
                int t=getnthfa(root,dep[root]-dep[f]-1);
                update(1,1,in[t]-1,x,1,n);
                update(1,out[t]+1,n,x,1,n);
            }else update(1,in[f],out[f],x,1,n);
        }else if (op==3){
            int x;LL ans;
            scanf("%d",&x);
            if (x==root) ans=query(1,1,n,1,n);
            else if (in[x]<=in[root]&&in[root]<=out[x]){
                int t=getnthfa(root,dep[root]-dep[x]-1);
                ans=query(1,1,in[t]-1,1,n)+query(1,out[t]+1,n,1,n);
            }else ans=query(1,in[x],out[x],1,n);
            printf("%I64d\n",ans);
        }
    }
}
/*
6 7
1 4 2 8 5 7
1 2
3 1
4 3
4 5
3 6
3 1
2 4 6 3
3 4
1 6
2 2 4 -5
1 4
3 3
*/