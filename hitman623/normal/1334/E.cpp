#include <bits/stdc++.h> 

#define int         long long
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
#define hell        998244353
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
int d,q;
map<int,int> prime_factors_d;
int fac[55],inv[55];
void solve(){
    fac[0]=1;
    rep(i,1,55) fac[i]=i*fac[i-1]%hell;
    rep(i,0,55) inv[i]=expo(fac[i],hell-2,hell);
    cin>>d;
    for(int i=2;i*i<=d;i++){
        if(d%i==0){
            while(d%i==0){
                d/=i;
                prime_factors_d[i]++;
            }
        }
    }
    if(d!=1) prime_factors_d[d]++;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        int g=__gcd(u,v);
        int extra_u=u/g;
        int extra_v=v/g;
        map<int,int> primes_extra_u;
        map<int,int> primes_extra_v;
        for(auto entry:prime_factors_d){
            int prime=entry.x;
            while(extra_u%prime==0){
                primes_extra_u[prime]++;
                extra_u/=prime;
            }
            while(extra_v%prime==0){
                primes_extra_v[prime]++;
                extra_v/=prime;
            }
        }
        // Prime factorisation of extra_u and extra_v done
        int arrangements_u=1,arrangements_v=1;
        int total_u=0,total_v=0;
        for(auto entry:primes_extra_u){
            int prime=entry.x;
            int freq=entry.y;
            total_u+=freq;
            arrangements_u = arrangements_u * inv[freq] % hell; 
        }
        arrangements_u = arrangements_u * fac[total_u] % hell;
        for(auto entry:primes_extra_v){
            int prime=entry.x;
            int freq=entry.y;
            total_v+=freq;
            arrangements_v = arrangements_v * inv[freq] % hell; 
        }
        arrangements_v = arrangements_v * fac[total_v] % hell;
        int ans=arrangements_u * arrangements_v % hell;
        cout<<ans<<endl;
    }
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