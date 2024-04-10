#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 1000000007;
const int maxn = 1111111;

ll fac[maxn], ifac[maxn];

ll modPow(ll a, ll b){
    a %= mod;
    if(b < 0) b += mod-1;
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void add(ll &a, ll b){
    a += b;
    if(a > mod)a -= mod;
}

void sub(ll &a, ll b){
    a -= b;
    if(a <= 0)a += mod;
}

void pre(){
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < maxn; i++){
        fac[i] = (fac[i-1]*i)%mod;
        ifac[i] = (ifac[i-1]*modPow(i, mod-2))%mod;
    }
}

inline ll ncr(int n, int r){
    if(n < r || r < 0 || n < 0)return 0;
    return fac[n]*(ifac[n-r]*ifac[r]%mod)%mod;
}

inline ll npr(int n, int r){
    if(n < r || n < 0 || r < 0)return 0;
    return fac[n]*ifac[n-r]%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);
    
    pre();
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    ll ans = 0;
    for(int k = 2; k <= n; k++){
        ll tmp = k*modPow(n, n-k-1)%mod;
        tmp *= modPow(m, n-k);
        tmp %= mod;
        tmp *= ncr(m-1, k-2);
        tmp %= mod;
        tmp *= npr(n-2, k-2);
        tmp %= mod;
        add(ans, tmp);
    }
    cout<<ans<<endl;
}