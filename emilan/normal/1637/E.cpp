#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kS = 700;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    set<pii> bad;
    while (m--) {
        int x, y;
        cin >> x >> y;
        bad.emplace(x, y);
        bad.emplace(y, x);
    }

    map<int, int> freq;
    for (int x : a) freq[x]++;

    map<int, vector<int>> group;
    for (auto [x, f] : freq) group[f].push_back(x);

    ll ans = 0;
    for (auto it1 = begin(group); it1 != end(group); it1++) {
        for (auto it2 = it1; it2 != end(group); it2++) {
            int cnt = it1->first + it2->first;
            auto v1 = it1->second;
            auto v2 = it2->second;

            pii s = {SZ(v1) - 1, SZ(v2) - 1};
            set<pii> vis{s};
            queue<pii> q({s});
            while (!empty(q)) {
                auto [i, j] = q.front();
                q.pop();

                if (v1[i] == v2[j] || bad.count({v1[i], v2[j]})) {
                    if (i > 0 && !vis.count({i - 1, j})) {
                        q.emplace(i - 1, j);
                        vis.emplace(i - 1, j);
                    }
                    if (j > 0 && !vis.count({i, j - 1})) {
                        q.emplace(i, j - 1);
                        vis.emplace(i, j - 1);
                    }
                } else {
                    ans = max(ans, cnt * ll(v1[i] + v2[j]));
                }
            }
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