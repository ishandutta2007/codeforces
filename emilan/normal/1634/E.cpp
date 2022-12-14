#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
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
    vector<vector<int>> a(n);
    for (auto &v : a) {
        int m;
        cin >> m;
        v.resize(m);
        for (int &x : v) cin >> x;
    }

    map<int, set<pii>> pos;
    REP(i, n) REP(j, SZ(a[i])) pos[a[i][j]].emplace(i, j);

    for (auto [x, s] : pos) {
        if (SZ(s) & 1) {
            cout << "NO\n";
            return;
        }
    }

    vector<string> ans(n);
    REP(i, n) ans[i].resize(SZ(a[i]));

    vector<set<int>> yet(n);
    REP(i, n) REP(j, SZ(a[i])) yet[i].insert(end(yet[i]), j);

    int need_l = -1, need_r = -1;
    auto go = [&](int i) {
        int j = *begin(yet[i]);
        auto &s = pos[a[i][j]];

        yet[i].erase(begin(yet[i]));
        s.erase({i, j});

        ans[i][j] = 'R';
        if (need_r == -1) need_l = i;

        auto [p, q] = *begin(s);

        yet[p].erase(q);
        s.erase(begin(s));

        ans[p][q] = 'L';
        if (p == need_l) need_l = need_r = -1;
        else need_r = p;
    };
    REP(i, n) {
        while (!yet[i].empty()) {
            if (need_r != -1) go(need_r);
            else go(i);
        }
    }

    cout << "YES\n";
    for (auto v : ans) cout << v << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}