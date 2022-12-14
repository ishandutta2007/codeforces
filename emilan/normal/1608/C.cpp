#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n);
    for (auto &x : b) cin >> x;

    vector<int> p(n);
    iota(ALL(p), 0);

    sort(ALL(p), [&](int i, int j) { return a[i] < a[j]; });

    int r = n - 1;
    int min_ = b[p[n - 1]];
    for (int l = n - 2; l >= 0; l--) {
        if (b[p[l]] > min_) {
            while (r > l) {
                min_ = min(min_, b[p[r - 1]]);
                r--;
            }
        }
    }

    vector<bool> ans(n);
    for (int i = r; i < n; i++) {
        ans[p[i]] = true;
    }

    for (auto x : ans) cout << x;
    cout << '\n';
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