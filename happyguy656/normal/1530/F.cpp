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

const int mod=31607;
int por(int x,int y=mod-2){int r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,a[24][24],g1[24],g2[22][1<<21],db[1<<25],dp[22][2],vv[22],ans;
int main(){
    for(int i=0;i<25;++i)db[1<<i]=i;
    scanf("%d",&n);for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){int x;scanf("%d",&x);a[i][j]=x*por(10000)%mod;}
    for(int i=1;i<=n;++i){g1[i]=1;for(int j=1;j<=n;++j)g1[i]=g1[i]*a[i][j]%mod;}
    for(int j=1;j<=n;++j){
        g2[j][0]=1;for(int i=1;i<(1<<n);++i){
            int t=i&-i;g2[j][i]=g2[j][i^t]*a[db[t]+1][j]%mod;
        }
    }
    for(int Z=0;Z<(1<<(n+2));++Z){
        int T=Z&3,z=Z>>2;
        for(int i=1;i<=n;++i){
            int zz=z;if(T&1)zz|=1<<(i-1);if(T&2)zz|=1<<(n-i+1-1);
            vv[i]=g2[i][zz^((1<<n)-1)];
        }
        dp[0][0]=1;
        for(int i=1;i<=n;++i)dp[i][0]=(dp[i-1][0]+dp[i-1][1]*vv[i])%mod,dp[i][1]=(dp[i-1][1]+dp[i-1][0]*vv[i])%mod;
        ll re=1;for(int i=0;i<n;++i)if(z>>i&1)re=re*g1[i+1]%mod;
        if(T&1){
            for(int i=0;i<n;++i)if(!(z>>i&1))re=re*a[i+1][i+1]%mod;
        }
        if(T&2){
            for(int i=1;i<=n;++i)if(!(z>>(i-1)&1)){
                if(i*2-1==n&&T==3)continue;
                re=re*a[i][n-i+1]%mod;
            }
        }
        int cc=0,kk=Z;while(kk)kk-=kk&-kk,cc^=1;
        if(cc)ans+=(dp[n][1]-dp[n][0])*re;else ans+=(dp[n][0]-dp[n][1])*re;ans%=mod;
    }
    ans=1-ans;
    ans=(ans%mod+mod)%mod;printf("%d\n",ans);
    return 0;
}