#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
ll n;
int k,inv[66];
int dp[51][51][10002],pre[51][51][10002];
vector<ll> divisors;
vector<pair<ll,ll>> primes;
void solve(){
    cin>>n>>k;
    rep(i,1,60) inv[i]=expo(i,hell-2,hell);
    rep(j,0,k+1){
        rep(y,0,51){
            rep(x,y,51){
                if(j==0) dp[x][y][j]=x==y;
                else dp[x][y][j]=1LL*inv[x+1]*pre[x][y][j-1]%hell;                  
                pre[x][y][j]=((x?1LL*pre[x-1][y][j]:0)+dp[x][y][j])%hell;
            }            
        }
    }
    for(ll i=1;i*i<=n;i++){
        if(n%i==0) divisors.pb(i);
        if(n%i==0 and i*i!=n) divisors.pb(n/i);
    }
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0) cnt++,n/=i;
            primes.pb({i,cnt});
        }
    }
    if(n>1) primes.pb({n,1});
    int ans=0;
    for(auto i:divisors){
        ll d=i,cur=1;
        for(auto j:primes){
            int x=j.y;
            int y=0;
            while(d%j.x==0) y++,d/=j.x;
            cur=1LL*cur*dp[x][y][k]%hell;
        }
        ans=(ans+1LL*(i%hell)*cur)%hell;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}