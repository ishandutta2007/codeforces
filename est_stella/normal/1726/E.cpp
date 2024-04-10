#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

ll inv(ll a){
    ll b = Mod - 2, ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

int n, m;
ll fact[300010];
ll infact[300010];
ll dp[300010];

void solve() {
    cin >> n;

    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = fact[i-1] * i % Mod;
    infact[n] = inv(fact[n]);
    for(int i=n; i>=1; i--) infact[i-1] = infact[i] * i % Mod;

    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] * (i-1)) % Mod;
    }

    ll ans = 0;
    for(int i=0; 4*i<=n; i++) {
        ans += fact[n-2*i] * infact[n-4*i] % Mod * infact[i] % Mod * dp[n-4*i] % Mod;
        ans %= Mod;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}