#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ll> b(n), g(m);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) cin >> g[i];
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (g.front() < b.back()) {
        cout << "-1\n";
        return 0;
    }
    ll sm = 0;
    for (int i = 0; i < n; ++i) sm += (ll)b[i] * m;
    vector <int> cnt(n);
    vector <bool> kek(n);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(g.begin(), g.end(), b[i]);
        if (it != g.end() && (*it) == b[i]) kek[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int id = upper_bound(b.begin(), b.end(), g[i]) - b.begin() - 1;
        while (id >= 0 && !kek[id] && cnt[id] == m - 1) --id;
        if (id == -1) {
            cout << "-1\n";
            return 0;
        }
        ++cnt[id];
        sm += g[i] - b[id];
    }
    cout << sm << '\n';
}