#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=3603,mod=998244353;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,m,T;bool v1[mxn],v2[mxn];
int n1,n2,p1[mxn],p2[mxn];
ll jc[mxn],inv[mxn];
ll dp[mxn][mxn];
ll f1[mxn],f2[mxn];
ll C(int x,int y){if(x<y)return 0;return jc[x]*inv[x-y]%mod;}
int main(){
    n=mxn-1;jc[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n]);for(int i=n;i;--i)inv[i-1]=inv[i]*i%mod;
    cin>>n>>m>>T;while(T--){int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;v1[x1]=v1[x2]=v2[y1]=v2[y2]=1;}
    for(int i=1;i<=n;++i)if(!v1[i])p1[++n1]=i;for(int i=1;i<=m;++i)if(!v2[i])p2[++n2]=i;
    if(!n1||!n2)return puts("1"),0;
    p1[0]=p2[0]=-1;
    memset(dp,0,sizeof(dp));dp[0][0]=1;for(int i=1;i<=n1;++i)for(int j=0;j<=i;++j){dp[i][j]=dp[i-1][j];if(p1[i]==p1[i-1]+1&&j)(dp[i][j]+=dp[i-2][j-1])%=mod;}
    for(int i=0;i<=n1;++i)f1[i]=dp[n1][i];
    memset(dp,0,sizeof(dp));dp[0][0]=1;for(int i=1;i<=n2;++i)for(int j=0;j<=i;++j){dp[i][j]=dp[i-1][j];if(p2[i]==p2[i-1]+1&&j)(dp[i][j]+=dp[i-2][j-1])%=mod;}
    for(int i=0;i<=n2;++i)f2[i]=dp[n2][i];
    ll ans=0;
    for(int i=0;i<=n1;++i)for(int j=0;j<=n2;++j)if(f1[i]&&f2[j])ans+=f1[i]*f2[j]%mod*C(n1-2*i,j)%mod*C(n2-2*j,i),ans%=mod;
    printf("%lld\n",ans);
    return 0;
}