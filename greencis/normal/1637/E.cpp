#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

inline ll makeEdge(int x, int y) {
    if (x > y) swap(x, y);
    return (x * 300973LL + y) ^ 0x5987'2309'7583'9751LL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++mp[x];
        }
        map<int, vector<int>> cnt2x;
        for (auto [x, cnt] : mp)
            cnt2x[cnt].push_back(x);

        unordered_set<ll> edges;
        while (m--) {
            int x, y;
            cin >> x >> y;
            edges.insert(makeEdge(x, y));
        }

        ll ans = 0;
        for (auto it = cnt2x.rbegin(); it != cnt2x.rend(); ++it) {
            int cx = it->first;
            const auto& vx = it->second;
            for (auto it2 = it; it2 != cnt2x.rend(); ++it2) {
                int cy = it2->first;
                const auto& vy = it2->second;

                for (int x : vx) {
                    for (auto itY = vy.rbegin(); itY != vy.rend(); ++itY) {
                        int y = *itY;
                        if (x == y)
                            break;
                        if (edges.find(makeEdge(x, y)) == edges.end()) {
                            ans = max(ans, ll(cx + cy) * (x + y));
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}