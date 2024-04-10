#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, fa[maxn], nxt[maxn], mark[maxn], foo[maxn];
long long ans, xors;
bool flag;
vector<int> G[maxn], bel[maxn];
vector<tuple<int, int, int>> E;
vector<pair<int, int>> baz;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y, flag = 1;
}

int main() {
    scanf("%d %d", &n, &m);
    int oldm = m;
    while (m--) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        xors ^= w, E.emplace_back(w, u, v);
        G[u].push_back(v), G[v].push_back(u);
        baz.emplace_back(min(u, v), max(u, v));
    }
    sort(baz.begin(), baz.end());
    iota(fa + 1, fa + n + 1, 1);
    while (1) {
        flag = 0;
        for (int i = n; i; i--) {
            nxt[i] = i + 1;
            if (i < n && find(i) == find(i + 1)) nxt[i] = nxt[i + 1];
        }
        for (int i = 1; i <= n; i++) {
            foo[i] = 0;
            for (int j : G[i]) mark[j] = 1;
            int cur = 1;
            while (cur <= n) {
                if (mark[cur]) cur++;
                else if (find(i) == find(cur)) cur = nxt[cur];
                else { foo[i] = cur; break; }
            }
            for (int j : G[i]) mark[j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (foo[i]) unite(i, foo[i]);
        }
        if (!flag) break;
    }
    sort(E.begin(), E.end());
    for (auto e : E) {
        int u = find(get<1>(e)), v = find(get<2>(e));
        if (u ^ v) ans += get<0>(e), unite(u, v);
    }
    if (1LL * n * (n - 1) / 2 - oldm <= n) {
        vector<pair<int, int>> useful;
        ans += xors;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (binary_search(baz.begin(), baz.end(), make_pair(i, j))) continue;
                useful.emplace_back(i, j);
            }
        }
        if (useful.size() >= n) {
            ans -= xors;
        } else {
            for (auto ban : useful) {
                long long sum = 0;
                iota(fa + 1, fa + n + 1, 1);
                for (auto e : useful) if (e != ban) {
                    unite(get<0>(e), get<1>(e));
                }
                for (auto e : E) {
                    int u = find(get<1>(e)), v = find(get<2>(e));
                    if (u ^ v) sum += get<0>(e), unite(u, v);
                }
                bool con = 1;
                for (int i = 2; i <= n; i++) {
                    if (find(1) ^ find(i)) { con = 0; break; }
                }
                if (con) ans = min(ans, sum);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}