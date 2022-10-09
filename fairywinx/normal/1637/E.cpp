#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    const int mx = 1e9 + 228;
    unordered_set<long long> c(10 * m);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        c.insert(1ll * a * mx + b);
        c.insert(a + 1ll * b * mx);
    }
    map<int, vector<int>> who;
    for (auto i : cnt) {
        who[i.second].emplace_back(i.first);
    }
    for (auto &i : who)
        sort(rall(i.second));
    long long ans = 0;
    for (auto it = who.begin(); it != who.end(); ++it) {
        for (auto p = it; p != who.end(); ++p) {
            auto &a = it->second, &b = p->second;
            for (int i : a) {
                for (int j : b) {
                    if (i == j || c.count(1ll * i * mx + j))
                        continue;
                    // cout << it->first << ' ' << p->first << ' ' << i << ' ' << j << '\n';
                    ans = max(ans, 1ll * (it->first + p->first) * (i + j));
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}