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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<pii> ans;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (p == -1) {
                ans.emplace_back(i, i);
                p = i;
            } else {
                if (a[i] == a[p]) ans.back().second++;
                else ans.emplace_back(i, i);
                p = -1;
            }
        } else {
            ans.emplace_back(i, i);
        }
    }

    if (p != -1) cout << "-1\n";
    else {
        cout << SZ(ans) << '\n';
        for (auto [l, r] : ans) {
            cout << l + 1 << ' ' << r + 1 << '\n';
        }
    }
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