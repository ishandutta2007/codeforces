#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int> pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=3e5+3;
int n,m,X;ll b[mxn];
struct bcj{int fa[mxn];void init(){for(int i=1;i<=n;++i)fa[i]=i;}int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}bool mer(int x,int y){x=find(x),y=find(y);if(x==y)return 0;return fa[x]=y,1;}}U;
int to[mxn*2],nxt[mxn*2],fir[mxn],gn=1,bb[mxn*2];
void gadd(int x,int y,int k){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,bb[gn]=k;}
int stk[mxn],sn,jg[mxn],an,fe[mxn];
void dfs(int x,int f){
    int K=sn;
    ll&v=b[x];int t;
    forg(i,x)if(to[i]!=f){
        dfs(to[i],x),fe[to[i]]=bb[i];
        t=to[i];
        if(b[t]>=X)v+=b[t]-X,--sn,jg[++an]=t;
    }
    while(sn>K&&(t=stk[sn],v+b[t]>=X))v+=b[t]-X,--sn,jg[++an]=t;
    stk[++sn]=x;
}
int main(){
    scanf("%d%d%d",&n,&m,&X);ll S=0;for(int i=1;i<=n;++i)scanf("%lld",b+i),S+=b[i];if(S<1ll*(n-1)*X)return puts("NO"),0;else puts("YES");
    U.init();
    for(int i=1,u,v;i<=m;++i){scanf("%d%d",&u,&v);if(U.mer(u,v))gadd(u,v,i),gadd(v,u,i);}
    assert(gn==2*n-1);
    dfs(1,0);
    assert(an==n-1);
    for(int i=1;i<n;++i)printf("%d\n",fe[jg[i]]);
    return 0;
}