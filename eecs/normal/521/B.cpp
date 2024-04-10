#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000009;
int m, ans, x[maxn], y[maxn];
map<pair<int, int>, int> mp;
set<int> S;

int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        mp[{x[i], y[i]}] = i;
    }
    auto test = [&](pair<int, int> p) {
        if (!mp.count(p)) return (size_t)0;
        return mp.count({p.first - 1, p.second - 1}) + mp.count({p.first,
            p.second - 1}) + mp.count({p.first + 1, p.second - 1});
    };
    auto chk = [&](pair<int, int> p) {
        if (!mp.count(p)) return 0;
        if (test({p.first - 1, p.second + 1}) == 1) return 0;
        if (test({p.first, p.second + 1}) == 1) return 0;
        if (test({p.first + 1, p.second + 1}) == 1) return 0;
        return 1;
    };
    for (int i = 0; i < m; i++) {
        if (chk({x[i], y[i]})) S.insert(i);
    }
    for (int turn = 0; !S.empty(); turn ^= 1) {
        int i = !turn ? *S.rbegin() : *S.begin(); S.erase(i);
        ans = (1LL * m * ans + i) % P;
        mp.erase({x[i], y[i]});
        for (int dx : {-2, -1, 0, 1, 2}) for (int dy : {-2, -1, 0, 1, 2}) {
            if (chk({x[i] + dx, y[i] + dy})) {
                S.insert(mp[{x[i] + dx, y[i] + dy}]);
            } else if (mp.count({x[i] + dx, y[i] + dy})) {
                S.erase(mp[{x[i] + dx, y[i] + dy}]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}