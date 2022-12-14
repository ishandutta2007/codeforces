#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    int ans = 0;
    vector<bool> vis(n);
    int ptr = n;
    int min_cur = n, min_nxt = n;
    for (int i = n - 1; i >= 0; i--) {
        vis[a[i]] = true;
        min_nxt = min(min_nxt, a[i]);
        if (ptr > 0 && vis[ptr - 1]) {
            if (ptr <= min_cur) ans++;
            while (ptr > 0 && vis[ptr - 1]) ptr--;
            min_cur = min_nxt;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}