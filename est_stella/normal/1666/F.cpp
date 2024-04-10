#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

int n;
int a[5010];
int l[5010];
ll dp[5010][5010];
ll inv[5010];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        l[a[i]] = i;
    }

    dp[0][0] = 1;
    for(int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][0] * inv[l[a[i]] - i + 1] % Mod;
        for(int j=1; 2*j<i; j++) {
            dp[i][j] = dp[i-1][j] * inv[l[a[i]] - i + 1] % Mod;

            if(a[i] == a[i-1]) continue;

            if(j == 1) dp[i][j] += dp[i-1][j-1] * (i + 1 - j * 2) % Mod * (i - j * 2) % Mod; 
            else dp[i][j] +=  dp[i-1][j-1] * (i - j * 2) % Mod;

            dp[i][j] %= Mod;
        }
    }

    if(a[n] == a[n-1]) cout << "0\n";
    else cout << dp[n-1][n/2-1] << "\n";
}

int main() {
    fast;

    for(int i=1; i<=5000; i++) inv[i] = pw(i, Mod-2);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}