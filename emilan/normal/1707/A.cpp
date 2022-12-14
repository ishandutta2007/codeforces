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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    auto f = [&](int m) -> string {
        string ans(n, '0');

        for (int i = n - 1; i >= 0; i--) {
            if (i >= n - m || a[i] <= q) ans[i] = '1';
        }

        int iq = q;
        for (int i = 0; i < n; i++) if (ans[i] == '1') {
            if (iq == 0) return "";
            if (a[i] > iq) iq--;
        }

        return ans;
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (!empty(f(m))) l = m;
        else r = m;
    }
    cout << f(l) << '\n';
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