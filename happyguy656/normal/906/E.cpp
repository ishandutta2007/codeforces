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

const int mxn=1e6+3;
char ss[mxn],s[mxn];int n;
int dp[mxn],zp[mxn],g[mxn],pz[mxn];
int len[mxn],fail[mxn],ts[mxn][26],nd,tt,le[mxn],ju[mxn],num[mxn];
inline int gf(int x,int i){for(;s[i]!=s[i-len[x]-1];x=fail[x]);return x;}
inline void ins(int c,int n){
    int x=gf(nd,n),y;
    if(!ts[x][c]){
        ++tt,len[tt]=len[x]+2,fail[tt]=ts[gf(fail[x],n)][c],ts[x][c]=tt;
        y=fail[tt];
        le[tt]=len[tt]-len[y];
        ju[tt]=le[tt]==le[y]?ju[y]:y;
    }
    nd=ts[x][c];
}

int main(){
    scanf("%s",ss+1);n=strlen(ss+1);for(int i=1;i<=n;++i)s[i*2]=ss[i];scanf("%s",ss+1);for(int i=1;i<=n;++i)s[i*2-1]=ss[i];
    n*=2;memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    tt=1,len[1]=-1,fail[0]=1;
    for(int i=1;i<=n;++i){
        ins(s[i]-'a',i);
        for(int x=nd,y;x;x=ju[x]){
            y=fail[x];
            pz[x]=i-len[ju[x]]-le[x];
            g[x]=dp[pz[x]];
            if(le[x]==le[y]&&g[y]<g[x])g[x]=g[y],pz[x]=pz[y];
            if(g[x]<dp[i])dp[i]=g[x],zp[i]=pz[x];
        }
        ++dp[i];if(s[i]==s[i-1]&&dp[i-2]<dp[i])dp[i]=dp[i-2],zp[i]=i-2;
        if(i%2)dp[i]=1e9;
    }
    if(dp[n]>n)return puts("-1"),0;
    printf("%d\n",dp[n]);
    for(int i=n;i;i=zp[i]){if(zp[i]!=i-2)printf("%d %d\n",(zp[i]+2)>>1,i>>1);}
    return 0;
}