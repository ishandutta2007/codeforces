#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define M N*40
#define mod 1000000007
using namespace std;
namespace TR{
    int val[N],n;
    void add(int x){for(;x<=n;x+=(x&(-x))) val[x]++;}
    int qry(int x){int v=0;for(;x;x-=(x&(-x))) v+=val[x];return v;}
}
int ls[M],rs[M],sx[M],sl[M],sr[M],sml[M],smr[M],res[M];
void update(int u)
{
    sx[u]=sx[ls[u]]+sx[rs[u]];
    sl[u]=(sl[ls[u]]+sl[rs[u]])%mod,sr[u]=(sr[ls[u]]+sr[rs[u]])%mod;
    sml[u]=(sml[ls[u]]+sml[rs[u]]+1ll*sl[ls[u]]*sx[rs[u]])%mod,smr[u]=(smr[ls[u]]+smr[rs[u]]+1ll*sx[ls[u]]*sr[rs[u]])%mod;
    res[u]=(res[ls[u]]+res[rs[u]]+1ll*sml[ls[u]]*sr[rs[u]]%mod+1ll*sl[ls[u]]*smr[rs[u]])%mod;
}
int cnt=0;
void insert(int &u,int l,int r,int p,int xl,int xr,int xv)
{
    if(!u) u=++cnt;
    if(l==r){sx[u]=xv,sl[u]=xl,sr[u]=xr;return;}
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],l,mid,p,xl,xr,xv);
    else insert(rs[u],mid+1,r,p,xl,xr,xv);
    update(u);
}
int root[N],w[N],pw[N];
int pa[N],pb[N];
int ans=0;
#define chg(x,a,b,c) ans-=res[root[w[x]]],insert(root[w[x]],1,n,x,a,b,c),ans=(ans+1ll*res[root[w[x]]]+mod)%mod
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),pw[i]=w[i];
    sort(pw+1,pw+n+1);
    int m=unique(pw+1,pw+n+1)-pw-1;
    for(int i=1;i<=n;i++) w[i]=lower_bound(pw+1,pw+m+1,w[i])-pw;
    TR::n=m;
    for(int i=1;i<=n;i++) pa[i]=TR::qry(w[i]),TR::add(w[i]);
    memset(TR::val,0,sizeof(TR::val));
    for(int i=n;i;i--) pb[i]=TR::qry(w[i]),TR::add(w[i]);
    for(int i=1;i<=n;i++) chg(i,pa[i],pb[i],1);
    int q;
    scanf("%d",&q);
    while(q --> 0)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1) chg(x,0,0,0);
        else chg(x,pa[x],pb[x],1);
        printf("%d\n",ans);
    }
    return 0;
}