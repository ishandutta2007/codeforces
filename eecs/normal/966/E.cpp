#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 80;
int n, m, tim, ans, fa[maxn], t[maxn], bel[maxn], bl[maxn], br[maxn];
int sz[maxn], son[maxn], top[maxn], tid[maxn], dep[maxn], tag[maxn], a[maxn];
char cnt[maxn / SZ + 1][maxn << 1];
bool on[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]), G[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    function<void(int)> dfs1 = [&](int v) {
        dep[v] = dep[fa[v]] + 1, sz[v] = 1;
        for (int u : G[v]) {
            dfs1(u), sz[v] += sz[u];
            if (sz[u] > sz[son[v]]) son[v] = u;
        }
    };
    function<void(int, int)> dfs2 = [&](int v, int rt) {
        tid[v] = ++tim, top[v] = rt;
        if (son[v]) dfs2(son[v], rt);
        for (int u : G[v]) if (u ^ son[v]) dfs2(u, u);
    };
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        a[tid[i]] = t[i];
    }
    for (int i = 1; i <= n; i++) {
        br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
        cnt[bel[i]][a[i] + n]++;
    }
    auto inc = [&](int k) {
        ans -= cnt[k][-tag[k] - 1 + n], tag[k]++;
    };
    auto dec = [&](int k) {
        ans += cnt[k][-tag[k] + n], tag[k]--;
    };
    auto inc2 = [&](int k, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (!on[i] && a[i] + tag[k] < 0) ans--;
            if (!on[i]) cnt[k][a[i] + n]--;
            a[i]++;
            if (!on[i]) cnt[k][a[i] + n]++;
            if (!on[i] && a[i] + tag[k] < 0) ans++;
        }
    };
    auto dec2 = [&](int k, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (!on[i] && a[i] + tag[k] < 0) ans--;
            if (!on[i]) cnt[k][a[i] + n]--;
            a[i]--;
            if (!on[i]) cnt[k][a[i] + n]++;
            if (!on[i] && a[i] + tag[k] < 0) ans++;
        }
    };
    auto range_inc = [&](int l, int r) {
        if (bel[l] == bel[r]) {
            inc2(bel[l], l, r);
        } else {
            inc2(bel[l], l, br[bel[l]]);
            inc2(bel[r], bl[bel[r]], r);
            for (int i = bel[l] + 1; i < bel[r]; i++) inc(i);
        }
    };
    auto range_dec = [&](int l, int r) {
        if (bel[l] == bel[r]) {
            dec2(bel[l], l, r);
        } else {
            dec2(bel[l], l, br[bel[l]]);
            dec2(bel[r], bl[bel[r]], r);
            for (int i = bel[l] + 1; i < bel[r]; i++) dec(i);
        }
    };
    while (m--) {
        int q; scanf("%d", &q);
        q = abs(q);
        int o = q;
        if (!on[tid[q]]) {
            for (; top[q] ^ 1; q = fa[top[q]]) range_dec(tid[top[q]], tid[q]);
            range_dec(1, tid[q]);
            if (tag[bel[tid[o]]] + a[tid[o]] < 0) ans--;
            cnt[bel[tid[o]]][a[tid[o]] + n]--;
        } else {
            for (; top[q] ^ 1; q = fa[top[q]]) range_inc(tid[top[q]], tid[q]);
            range_inc(1, tid[q]);
            if (tag[bel[tid[o]]] + a[tid[o]] < 0) ans++;
            cnt[bel[tid[o]]][a[tid[o]] + n]++;
        }
        on[tid[o]] ^= 1, printf("%d ", ans);
    }
    return 0;
}