#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
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

using A3 = array<int, 3>;

void solve() {
    int entries, len;
    cin >> entries >> len;
    vector<string> phone_book(entries);
    for (auto &x : phone_book) cin >> x;
    string pat;
    cin >> pat;

    map<string, A3> seg[4];
    REP(i, entries) {
        for (int sz : {2, 3}) {
            REP(j, len - sz + 1) {
                seg[sz][phone_book[i].substr(j, sz)]
                    = {j, j + sz - 1, i};
            }
        }
    }

    vector<bool> vis(len + 1);
    vector<A3> par(len + 1);
    vis[0] = true;
    for (int i = 0; i <= len; i++) {
        for (int sz : {2, 3}) {
            if (i >= sz && vis[i - sz]) {
                string s = pat.substr(i - sz, sz);
                if (auto it = seg[sz].find(s); it != end(seg[sz])) {
                    vis[i] = true;
                    par[i] = it->second;
                    break;
                }
            }
        }
    }

    if (!vis[len]) cout << "-1\n";
    else {
        vector<A3> ans;
        for (int i = len; i > 0;) {
            ans.push_back(par[i]);
            auto [l, r, ent] = par[i];
            i -= r - l + 1;
        }

        cout << SZ(ans) << '\n';
        for (auto [l, r, ent] : vector(RALL(ans))) {
            cout << l + 1 << ' ' << r + 1 << ' ' << ent + 1 << '\n';
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