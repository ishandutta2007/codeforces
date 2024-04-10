#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 2;
int a[maxn][maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    LL ans = n * m;
    map<int, set<int>> mp;
    map<pair<int, int>, vector<int>> mps;
    for (int i = -n; i <= m; i += 1) {
        int x = 0, y = i, t = 1;
        while (true) {
            if (x <= 0 or x > n or y <= 0 or y > m) mp[i].insert(x + y - i);
            else mps[{x, y}].push_back(i);
            if (x > n or y > m) break;
            if (t) x += 1;
            else y += 1;
            t ^= 1;
        }
    }
    for (int i = 1; i <= n; i += 1)
        for (int j = 1; j <= m; j += 1) {
            ans += min((n - i) * 2, (m - j) * 2 + 1);
            ans += min((n - i) * 2 + 1, (m - j) * 2);
        }
    auto f = [&](LL L, LL R) {
        LL n = R - L - 1;
        return n * (n - 1) / 2;
    };
    for (int i = 0; i < q; i += 1) {
        int x, y;
        cin >> x >> y;
        if (a[x][y]) {
            a[x][y] = 0;
            ans += 1;
            for (int s : mps[{x, y}]) {
                int c = x + y - s;
                int pre = *prev(mp[s].lower_bound(c));
                int nxt = *next(mp[s].lower_bound(c));
                mp[s].erase(c);
                ans -= f(pre, c) + f(c, nxt);
                ans += f(pre, nxt);
            }
        }
        else {
            a[x][y] = 1;
            ans -= 1;
            for (int s : mps[{x, y}]) {
                int c = x + y - s;
                mp[s].insert(c);
                int pre = *prev(mp[s].lower_bound(c));
                int nxt = *next(mp[s].lower_bound(c));
                ans += f(pre, c) + f(c, nxt);
                ans -= f(pre, nxt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}