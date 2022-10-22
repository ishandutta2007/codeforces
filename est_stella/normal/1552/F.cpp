#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
ll x[200010];
ll y[200010];
ll s[200010];
ll dp[200010];
ll sum[200010];
ll Dp[200010];

vector<int> l;

int main() {
    fast;

    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        l.eb(x[i]);
    }

    for(int i=1; i<=n; i++) {
        int k = lower_bound(all(l), y[i]) - l.begin() + 1;

        Dp[i] = (x[i] - y[i] + sum[i-1] + Mod - sum[k-1]) % Mod;
        sum[i] = (sum[i-1] + Dp[i]) % Mod;
    }

    ll ans = (x[n]+1) % Mod;
    for(int i=1; i<=n; i++) {
        if(s[i]) ans += Dp[i];
        ans %= Mod;
    }

    cout << ans;
}