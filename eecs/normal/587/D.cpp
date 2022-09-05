#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, m, tot, u[maxn], v[maxn], c[maxn], t[maxn], num[maxn];
int cnt, tp, tim, st[maxn], dfn[maxn], low[maxn], bel[maxn];
vector<int> G[maxn], H[maxn];
unordered_map<int, int> mp;

int main() {
    scanf("%d %d", &n, &m);
    vector<int> V = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &u[i], &v[i], &c[i], &t[i]);
        G[--u[i]].push_back(i), G[--v[i]].push_back(i);
        V.push_back(t[i]);
    }
    auto implie = [&](int u, int v) {
        H[u].push_back(v), H[v ^ 1].push_back(u ^ 1);
    };
    function<void(int)> dfs = [&](int v) {
        dfn[v] = low[v] = ++tim, st[++tp] = v;
        for (int u : H[v]) {
            if (!dfn[u]) dfs(u), low[v] = min(low[v], low[u]);
            else if (!bel[u]) low[v] = min(low[v], dfn[u]);
        }
        if (dfn[v] == low[v]) {
            cnt++;
            while (1) {
                int u = st[tp--];
                bel[u] = cnt;
                if (u == v) break;
            }
        }
    };
    auto chk = [&](int T) {
        for (int i = 0; i < tot * 2; i++) {
            H[i].clear(), dfn[i] = bel[i] = num[i] = 0;
        }
        cnt = tim = 0, tot = m;
        for (int i = 0; i < n; i++) {
            mp.clear();
            int lst = -1;
            for (int j : G[i]) {
                if (!~lst) {
                    lst = j;
                } else {
                    implie(2 * lst, 2 * j + 1), implie(2 * lst, 2 * tot);
                    implie(2 * j, 2 * tot), lst = tot++;
                }
                if (!mp.count(c[j])) mp[c[j]] = j;
                else if (!~mp[c[j]]) return 0;
                else implie(2 * mp[c[j]] + 1, 2 * j), mp[c[j]] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] > T) H[2 * i].push_back(2 * i + 1);
        }
        for (int i = 0; i < tot * 2; i++) {
            if (!dfn[i]) dfs(i);
        }
        for (int i = 0; i < tot * 2; i += 2) {
            if (bel[i] == bel[i + 1]) return 0;
            if (bel[i] < bel[i + 1]) num[i / 2] = 1;
        }
        return 1;
    };
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    int l = 0, r = V.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(V[mid]) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    if (!~ans) puts("No"), exit(0);
    V.clear(), chk(V[ans]);
    for (int i = 0; i < m; i++) {
        if (num[i]) V.push_back(i + 1);
    }
    printf("Yes\n%d %d\n", V[ans], V.size());
    for (int i : V) printf("%d ", i);
    return 0;
}