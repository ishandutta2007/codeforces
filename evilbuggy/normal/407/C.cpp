#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 1000000007;
const int maxn = 111111;
const int maxk = 111;

ll fac[maxn], ifac[maxn];

inline ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void pre(){
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < maxn; i++){
        fac[i] = (fac[i-1]*i)%mod;
        ifac[i] = (ifac[i-1]*modPow(i, mod-2))%mod;
    }
}

inline ll ncr(int n, int r){
    if(n < r || n < 0 || r < 0)return 0;
    return fac[n]*(ifac[n-r]*ifac[r]%mod)%mod;
}

ll dp[maxk][maxn];

void add(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

void sub(ll &a, ll b){
    a -= b;
    if(a < 0)a += mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);
    
    pre();
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>dp[0][i];
    }
    int l, r, k;
    while(m--){
        cin>>l>>r>>k;
        dp[k+1][l]++;
        for(int i = k+1; i > 0; i--){
            sub(dp[i][r+1], ncr(r-l+(k+1-i), r-l));
        }
    }
    
    for(int k = maxk-1; k > 0; k--){
        for(int i = 1; i <= n; i++){
            add(dp[k][i], dp[k][i-1]);
            add(dp[k-1][i], dp[k][i]);
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<dp[0][i]<<" ";
    }
    cout<<endl;
}