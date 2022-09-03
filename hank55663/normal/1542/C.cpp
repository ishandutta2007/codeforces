#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    LL n;
    scanf("%lld",&n);
    LL ans=0;
    LL lcm=1;
    LL now=2;
    while(lcm<=n){
        ans+=(n/lcm-n/(lcm*now/__gcd(lcm,now)))*now%mod;
        ans%=mod;
        lcm=lcm*now/__gcd(lcm,now);
        now++;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}