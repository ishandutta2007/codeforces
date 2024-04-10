#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, tim, a[maxn], b[maxn], l[maxn], r[maxn];
vector<int> G[maxn], H[maxn];
set<pair<int, int>> S;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear(), H[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &a[i]), G[a[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &b[i]), H[b[i]].push_back(i);
        }
        function<void(int, int)> init = [&](int v, int fa) {
            l[v] = ++tim;
            for (int u : H[v]) if (u ^ fa) init(u, v);
            r[v] = tim;
        };
        tim = 0, init(1, 0);
        int ans = 0;
        function<void(int, int)> dfs = [&](int v, int fa) {
            pair<int, int> p = {-1, -1};
            bool flag = 0;
            auto it = S.lower_bound(make_pair(r[v], 0));
            if (it == S.begin() || l[v] > prev(it)->first) {
                flag = 1, S.emplace(r[v], l[v]);
                if (it != S.end() && r[v] >= it->second) p = *it, S.erase(it);
            }
            ans = max(ans, (int)S.size());
            for (int u : G[v]) if (u ^ fa) dfs(u, v);
            if (~p.first) S.insert(p);
            if (flag) S.erase(make_pair(r[v], l[v]));
        };
        dfs(1, 0);
        printf("%d\n", ans);
    }   
    return 0;
}