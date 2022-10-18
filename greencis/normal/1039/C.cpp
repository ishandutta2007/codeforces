#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 1000000007;

ll binpow(ll x, ll deg) {
    ll ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans = ans * x % mod;
        deg >>= 1;
        x = x * x % mod;
    }
    return ans;
}

ll a[500500];
vector<int> g[500500];
map<ll, vector<int>> gg[500500];
map<ll, vector<int>> mpver;
int u[500500];
ll curx;
int ses;

void dfs(int v) {
    if (u[v] == ses)
        return;
    u[v] = ses;
    for (int to : gg[v][curx])
        dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        set<ll> cur;
        for (int to : g[i]) {
            ll x = a[i] ^ a[to];
            gg[i][x].push_back(to);
            cur.insert(x);
        }
        for (ll x : cur)
            mpver[x].push_back(i);
    }
    ll ans = binpow(2, n + k);
    for (auto& p : mpver) {
        auto& v = p.second;
        if (v.size() > 1) {
            ++ses;
            curx = p.first;
            ll sub = 1;
            for (int x : v) {
                if (u[x] != ses) {
                    sub = (sub * 2) % mod;
                    dfs(x);
                }
            }
            ll cur = binpow(2, n - v.size()) * ll(binpow(2, v.size()) - sub) % mod;
            if (cur < 0)
                cur += mod;
            ans = (ans + mod - cur) % mod;
        }
    }
    cout << ans << endl;
}