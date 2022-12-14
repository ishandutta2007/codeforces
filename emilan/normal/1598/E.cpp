#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<set<int>> stairs;
    using vpii = vector<pair<int, int>>;
    vector<vector<vpii>> labels(n, vector<vpii>(m));
    ll ans = 0;
    auto build = [&](int x, int y, bool down) {
        int i = stairs.size();
        int j = 0;
        stairs.emplace_back();
        stairs.back().insert(-1);

        for (;; down ^= 1) {
            labels[x][y].emplace_back(i, j++);

            if (down) {
                if (++x == n) break;
            } else {
                if (++y == m) break;
            }
        }

        stairs.back().insert(j);
        ans += j * ll(j - 1) / 2;
    };

    for (int i = m - 1; i >= 0; i--) {
        build(0, i, false);
    }
    for (int i = 0; i < n; i++) {
        build(i, 0, true);
    }

    // count "dot stairs"
    ans += n * m;

    vector<vector<bool>> occ(n, vector<bool>(m));
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        for (auto [i, j] : labels[x][y]) {
            if (!occ[x][y]) {
                auto it_r = stairs[i].upper_bound(j);
                auto it_l = prev(it_r);
                int k = *it_r - *it_l - 1;
                int l = j - *it_l - 1;
                int r = *it_r - j - 1;

                ans -= k * ll(k - 1) / 2;
                ans += l * ll(l - 1) / 2;
                ans += r * ll(r - 1) / 2;

                stairs[i].insert(j);
            } else {
                stairs[i].erase(j);

                auto it_r = stairs[i].upper_bound(j);
                auto it_l = prev(it_r);
                int k = *it_r - *it_l - 1;
                int l = j - *it_l - 1;
                int r = *it_r - j - 1;

                ans += k * ll(k - 1) / 2;
                ans -= l * ll(l - 1) / 2;
                ans -= r * ll(r - 1) / 2;
            }
        }

        ans += occ[x][y] - (occ[x][y] ^ 1);
        occ[x][y].flip();
        cout << ans << "\n";
    }
}