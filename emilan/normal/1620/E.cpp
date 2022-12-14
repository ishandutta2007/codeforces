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

const int kM = 5e5;

void solve() {
    int dsu[2 * kM + 69];
    memset(dsu, -1, sizeof dsu);

    auto root_ = [&](auto &self, int u) -> int {
        return dsu[u] < 0 ? u : dsu[u] = self(self, dsu[u]);
    };
    auto root = [&](int u) { return root_(root_, u); };

    auto combine = [&](int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        dsu[v] = u;
    };

    int color2root[kM + 1];
    iota(ALL(color2root), 0);

    int root2color[2 * kM + 69];
    iota(begin(root2color), begin(root2color) + kM + 1, 0);

    int ptr = kM + 1;
    vector<int> ans;

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;

            ans.push_back(color2root[x]);
        } else {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;

            combine(color2root[y], color2root[x]);
            root2color[ptr] = x;
            color2root[x] = ptr;
            ptr++;
        }
    }

    REP(i, SZ(ans)) {
        cout << root2color[root(ans[i])] << " \n"[i == SZ(ans) - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}