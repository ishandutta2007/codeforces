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

int n;
int sp[200010];
vector<int> p;

ll ans;
ll dp[200010];
int mn[200010];
int cnt[200010];
vector<pair<int,pii>> g[200010];

ll inv(ll a) {
    ll b = Mod - 2, ret = 1;
    while(b) {
        if(b & 1) ret = a * ret % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

void dfs(int x, int p = 0) {
    ans += dp[x];
    ans %= Mod;
    
    for(auto i : g[x]) {
        if(i.fi == p) continue;

        for(int j = i.se.se; j > 1; j /= sp[j]) cnt[sp[j]]++;
        for(int j = i.se.fi; j > 1; j /= sp[j]) {cnt[sp[j]]--; mn[sp[j]] = min(mn[sp[j]], cnt[sp[j]]); }

        dp[i.fi] = dp[x] * i.se.se % Mod * inv(i.se.fi) % Mod;
        dfs(i.fi, x);

        for(int j = i.se.fi; j > 1; j /= sp[j]) cnt[sp[j]]++;
        for(int j = i.se.se; j > 1; j /= sp[j]) {cnt[sp[j]]--; mn[sp[j]] = min(mn[sp[j]], cnt[sp[j]]); }
    }
}

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1; i<=n; i++) mn[i] = 0;

    for(int i=1; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].eb(b, mp(c, d));
        g[b].eb(a, mp(d, c));
    }

    ans = 0;
    dp[1] = 1;
    dfs(1);

    for(int i=1; i<=n; i++) {
        for(int j=0; j<-mn[i]; j++) ans = (ans * i) % Mod;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    for(int i=2; i<=200000; i++) {
        if(!sp[i]) {
            p.eb(i);
            sp[i] = i;
        }
        for(auto j : p) {
            if(i * j > 200000) break;
            sp[i*j] = j;
            if(i%j == 0) break;
        }
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}