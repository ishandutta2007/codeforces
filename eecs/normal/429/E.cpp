#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 200010;
int n, cnt = 1, l[maxn], r[maxn], head[maxn], d[maxn], ans[maxn], vis[maxn * 2];
bool mark[maxn];
struct edge { int to, nxt, id; } e[maxn * 4];
 
int main() {
    scanf("%d", &n);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        l[i] = 2 * l[i], r[i] = 2 * r[i] + 1;
        V.push_back(l[i]), V.push_back(r[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(V.begin(), V.end(), l[i]) - V.begin();
        r[i] = lower_bound(V.begin(), V.end(), r[i]) - V.begin();
        e[++cnt] = (edge){r[i], head[l[i]], i}, head[l[i]] = cnt;
        e[++cnt] = (edge){l[i], head[r[i]], i + n}, head[r[i]] = cnt;
        d[l[i]]++, d[r[i]]++;
    }
    for (int i = 0, lst = -1; i < V.size(); i++) if (d[i] % 2) {
        if (~lst) {
            e[++cnt] = (edge){i, head[lst], 0}, head[lst] = cnt;
            e[++cnt] = (edge){lst, head[i], 0}, head[i] = cnt;
            lst = -1;
        } else {
            lst = i;
        }
    }
    function<void(int)> dfs = [&](int u) {
        mark[u] = 1;
        for (int &i = head[u]; i; i = e[i].nxt) if (!vis[i / 2]) {
            int o = e[i].id;
            if (e[i].id <= n) ans[e[i].id] = 1;
            vis[i / 2] = 1, dfs(e[i].to);
        }
    };
    for (int i = 0; i < V.size(); i++) {
        if (!mark[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}