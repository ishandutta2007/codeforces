#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
typedef long long ll;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=4053,mod=998244353;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
ll jc[mxn],inv[mxn];ll C(int x,int y){if(x<y)return 0;return jc[x]*inv[y]%mod*inv[x-y]%mod;}ll CC(int x,int y){return C(x+y,x);}
int n,m;ll ans;

int main(){
    n=mxn-1;jc[0]=1;for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;inv[n]=por(jc[n]);for(int i=n;i;--i)inv[i-1]=inv[i]*i%mod;
    cin>>n>>m;--n,--m;
    for(int i=1;i<=n;++i){ll s=0;for(int j=0;j<m;++j){s+=CC(n-i+1,j)*CC(n-i,m-j);s%=mod;ans+=CC(i-1,j+1)*CC(i,m-j-1)%mod*s,ans%=mod;}}
    for(int j=0;j<m;++j){ll s=0;for(int i=n;i>1;--i){s+=CC(n-i,m-j)*CC(i,m-j-1);s%=mod;ans+=CC(i-2,j+1)*CC(n-i+2,j)%mod*s,ans%=mod;}}
    printf("%lld\n",ans*2%mod);
    return 0;
}