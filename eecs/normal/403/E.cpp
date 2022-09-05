#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct SEG {
    vector<pair<int, int>> S[maxn << 2];
    int pl[maxn << 2], pr[maxn << 2];
    bool vis[maxn];

    void ins(int k, int l, int r, int p, pair<int, int> v) {
        S[k].push_back(v);
        if (l == r) return;
        mid >= p ? ins(ls, l, mid, p, v) : ins(rs, mid + 1, r, p, v);
    }
    void build(int k, int l, int r) {
        pr[k] = (int)S[k].size() - 1;
        if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
    }
    int get(int k, int l, int r, int ql, int qr) {
        while (pl[k] < S[k].size() && vis[S[k][pl[k]].second]) pl[k]++;
        while (~pr[k] && vis[S[k][pr[k]].second]) pr[k]--;
        if (pl[k] > pr[k]) return 0;
        if (l >= ql && r <= qr) {
            if (S[k][pl[k]].first < ql) return S[k][pl[k]].second;
            if (S[k][pr[k]].first > qr) return S[k][pr[k]].second;
            return 0;
        }
        int s = 0;
        if (mid >= ql) s = get(ls, l, mid, ql, qr);
        if (mid < qr && !s) s = get(rs, mid + 1, r, ql, qr);
        return s;
    }
};

struct Tree {
    int tim, fa[maxn], tid[maxn], sz[maxn];
    vector<int> G[maxn];
    SEG T;

    void dfs(int u) {
        tid[u] = ++tim, sz[u] = 1;
        for (int v : G[u]) dfs(v), sz[u] += sz[v];
    }
    void init() {
        for (int i = 2; i <= n; i++) {
            scanf("%d", &fa[i]), G[fa[i]].push_back(i);
        }
        dfs(1);
    }
    int del(int i) {
        return T.get(1, 1, n, tid[i], tid[i] + sz[i] - 1);
    }
} T[2];

int main() {
    scanf("%d", &n);
    T[0].init(), T[1].init();
    for (int i : {0, 1}) {
        vector<pair<pair<int, int>, int>> V;
        for (int j = 2; j <= n; j++) {
            V.push_back({{T[i].tid[T[!i].fa[j]], j}, T[i].tid[j]});
            V.push_back({{T[i].tid[j], j}, T[i].tid[T[!i].fa[j]]});
        }
        sort(V.begin(), V.end());
        for (auto &p : V) T[i].T.ins(1, 1, n, p.second, p.first);
        T[i].T.build(1, 1, n);
    }
    int id;
    scanf("%d", &id);
    vector<int> V = {++id};
    T[1].T.vis[id] = 1;
    for (int t = 0; !V.empty(); t ^= 1) {
        puts(t ? "Red" : "Blue"), sort(V.begin(), V.end());
        vector<int> _V;
        for (int x : V) {
            printf("%d ", x - 1);
            while (1) {
                int y = T[t].del(x);
                if (!y) break;
                _V.push_back(y), T[t].T.vis[y] = 1;
            }
        }
        putchar('\n'), swap(V, _V);
    }
    return 0;
}