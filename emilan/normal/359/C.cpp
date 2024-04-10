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

const ll mod = 1e9 + 7;

ll mod_pow(ll b, ll e) {
    ll r = 1;
    for (; e; e >>= 1, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    map<int, int> cnt;
    for (int x : a) cnt[-x]++;

    for (auto it = cnt.begin(); it != cnt.end();) {
        if (it->se % m) break;

        cnt[it->fi + 1] += it->se / m;
        auto it2 = it;
        it++;
        cnt.erase(it2);
    }

    ll p = accumulate(all(a), 0ll);
    if (!cnt.empty() && cnt.begin()->fi < 0) p += cnt.begin()->fi;
    cout << mod_pow(m, p);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}