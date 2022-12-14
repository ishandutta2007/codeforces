#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const ll mod = 998244353;
const int maxn = 3e5 + 1;
ll fact[maxn], finv[maxn], inv[maxn];

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * finv[r] % mod * finv[n - r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, vt<int>> fin;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        fin[l].push_back(r);
    }

    ll ans = 0;
    priority_queue<int> q;
    for (auto &p : fin) {
        int x = p.fi;
        while (!q.empty() && -q.top() < x) q.pop();

        int ps = sz(q);
        for (int i : p.se) q.push(-i);

        int ns = sz(q) - ps;
        for (int i = 1; i <= ns; i++) {
            ans = (ans + C(ns, i) * C(ps, k - i)) % mod;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }

    finv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        finv[i] = finv[i - 1] * inv[i] % mod;
    }

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}