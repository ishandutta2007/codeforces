#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    map<int, int> pfs_;
    auto decomp = [&](int x) {
        for (int i = 2; i * i <= x; i++) {
            for (; x % i == 0; x /= i) {
                pfs_[i]++;
            }
        }
        if (x > 1) pfs_[x]++;
    };
    decomp(a);
    decomp(b);

    vector<pii> pfs;
    for (auto [p, f] : pfs_) {
        pfs.emplace_back(p, f);
    }
    int m = SZ(pfs);

    int ans_x = -1;
    int ans_y = -1;
    auto dfs = [&](auto &self, int x, int i) -> void {
        if (i == m) {
            ll y_ = ll(a) * b / x;
            if (y_ > d) return;
            int y = int(y_);

            int s = x * (a / x + 1);
            int t = y * (b / y + 1);
            if (s <= c && t <= d) {
                ans_x = s;
                ans_y = t;
            }
        } else {
            auto [p, f] = pfs[i];
            unsigned long long y = 1;
            for (int e = 0; e <= f && x * y <= unsigned(c); e++, y *= p) {
                self(self, int(x * y), i + 1);
            }
        }
    };
    dfs(dfs, 1, 0);

    cout << ans_x << ' ' << ans_y << '\n';
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