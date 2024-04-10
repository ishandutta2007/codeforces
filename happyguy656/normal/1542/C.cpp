#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a13=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a13;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mod=1e9+7;
ll lc[55];
ll gcd(ll x,ll y){for(ll z;y;z=x%y,x=y,y=z);return x;}
int main(){
    lc[1]=1;for(int i=2;i<=41;++i){lc[i]=lc[i-1]/gcd(lc[i-1],i)*i;}
    int ca;scanf("%d",&ca);while(ca--){
        ll n,re=0;scanf("%lld",&n);
        for(int i=1;i<=40;++i)re+=(n/lc[i]-n/lc[i+1])%mod*(i+1)%mod;
        re%=mod;printf("%lld\n",re);
    }
    return 0;
}