#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    multiset<int> m;
    vt<int> c(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m.insert(x);
    }
    for (int &i : c) cin >> i, i *= -1;

    vt<vt<int>> ans{{}};
    int cur = 1;
    while (!m.empty()) {
        auto it = upper_bound(all(c), -cur);
        auto it2 = m.upper_bound(distance(c.begin(), it));
        if (it2 == m.begin()) {
            ans.emplace_back();
            cur = 1;
            it2 = m.end();
        }
        it2--;

        ans.back().push_back(*it2);
        m.erase(it2);

        cur++;
    }

    cout << sz(ans) << '\n';
    for (auto &i : ans) {
        cout << sz(i);
        for (int j : i) cout << ' ' << j;
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}