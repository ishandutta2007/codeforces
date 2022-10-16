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

const int mxn=1e6+3,mod=1e9+7;
ll por(ll x,int y){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
ll jc[mxn],inv[mxn];ll C(int x,int y){if(x<y)return 0;return jc[x]*inv[y]%mod*inv[x-y]%mod;}
int n;

int main(){
    scanf("%d",&n);jc[0]=inv[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n],mod-2);for(int i=n-1;i;--i)inv[i]=inv[i+1]*(i+1)%mod;
    ll ans=0;
    for(int i=1;i<n;i+=2)ans+=C(i+1,n-i-1)*jc[i]%mod;
    ans=ans%mod*2*n%mod;printf("%lld\n",ans);
    return 0;
}