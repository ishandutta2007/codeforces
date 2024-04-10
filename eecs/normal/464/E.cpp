#include <bits/stdc++.h>
using namespace std;

const int maxn = 110000, P = 1000000007;
int n, m, U, tot, pw[maxn], pre[maxn], rt[maxn];
bool vis[maxn];
vector<array<int, 2>> G[maxn];

#define mid ((l + r) >> 1)
struct node { int l, r, s; } t[maxn * 150];

bool comp(int k1, int k2, int l, int r) {
    if (l == r) return t[k1].s > t[k2].s;
    if (t[t[k1].r].s == t[t[k2].r].s) return comp(t[k1].l, t[k2].l, l, mid);
    return comp(t[k1].r, t[k2].r, mid + 1, r);
}

int modify(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2];
    if (l == r) { t[k1].s = !t[k2].s; return t[k2].s; }
    int res;
    if (mid < p || (res = modify(t[k1].l, t[k2].l, l, mid, p))) {
        res = modify(t[k1].r, t[k2].r, mid + 1, r, p);
    }
    t[k1].s = (t[t[k1].l].s + 1LL * t[t[k1].r].s * pw[mid - l + 1]) % P;
    return res;
}

struct state {
    int x, rt;
    bool operator < (const state &o) const { return comp(rt, o.rt, 0, U); };
};
priority_queue<state> Q;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
        U = max(U, w);
    }
    U += 20;
    for (int i = pw[0] = 1; i <= U; i++) {
        pw[i] = 2 * pw[i - 1] % P;
    }
    int s, t;
    scanf("%d %d", &s, &t);
    Q.push((state){s, rt[s]});
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (p.rt != rt[p.x]) continue;
        if (p.x == t) {
            vector<int> V;
            for (int i = t; i ^ s; i = pre[i]) V.push_back(i);
            reverse(V.begin(), V.end());
            printf("%d\n%d\n%d", ::t[p.rt].s, V.size() + 1, s);
            for (int x : V) printf(" %d", x);
            exit(0);
        }
        for (auto &e : G[p.x]) {
            int k; modify(k, p.rt, 0, U, e[1]);
            if (!rt[e[0]] || comp(rt[e[0]], k, 0, U)) {
                Q.push((state){e[0], rt[e[0]] = k}), pre[e[0]] = p.x;
            }
        }
    }
    puts("-1");
    return 0;
}