#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=5e5+3;
int to[mxn*2],nxt[mxn*2],fir[mxn],gn=1,n,m;void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,to[++gn]=x,nxt[gn]=fir[y],fir[y]=gn;}
int dfn[mxn],low[mxn],dn,tk[mxn],sn,be[mxn],bn,eh[mxn],e2[mxn];
int dp[mxn];
int xl[mxn*2],xn,h1[mxn],h2[mxn],vd[mxn],vv[mxn];
void tar(int x,int e=0){
    dfn[x]=low[x]=++dn,tk[++sn]=x;
    forg(i,x){
        int y=to[i];if(!dfn[y]){
            tar(y,i^1),eh[y]=i,low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x])--sn;
            else if(low[y]==dfn[x]){
                ++bn;xn=0;
                int z=e2[tk[sn]];be[z>>1]=bn,xl[++xn]=z>>1;
                do z=eh[tk[sn--]],be[z>>1]=bn,xl[++xn]=z>>1;while(to[z]!=y);
                int mn=1e9,mx=0,t1,t2;
                for(int j=1,k;j<=xn;++j){k=xl[j];if(k<mn)mn=k,t2=j;if(k>mx)mx=k,t1=j;}
                for(int j=1;j<=xn;++j)xl[j+xn]=xl[j];
                h1[bn]=mx,h2[bn]=mn;
                bool ok=1;
                if(t1>t2)t2+=xn;assert(t1<t2);
                for(int j=t1+1;j<t2;++j)ok&=xl[j]<xl[j-1];
                for(int j=t2+1;j<t1+xn;++j)ok&=xl[j]>xl[j-1];
                vd[bn]=ok;
            }
        }else if(i!=e&&dfn[y]<low[x])low[x]=dfn[y],e2[x]=i;
    }
}

int main(){
    scanf("%d%d",&n,&m);for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),gadd(x,y);
    tar(1);for(int i=1;i<=n;++i)assert(dfn[i]);
    for(int i=1;i<=n;++i)dp[i]=1;
    for(int i=m;i;--i){
        int x=to[i*2],y=to[i*2+1],H=dp[x]+dp[y];
        dp[x]=dp[y]=H;
        if(be[i]){
            int k=be[i];
            if(i==h2[k]&&vd[k])dp[x]-=vv[k],dp[y]-=vv[k];else if(i==h1[k])vv[k]=H;
        }
    }
    for(int i=1;i<=n;++i)printf("%d ",dp[i]-1);puts("");
    return 0;
}