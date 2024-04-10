#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
const int maxn = 100010, P = 1000000007;
int n, m, ans, tot, dep[maxn], f[380], g[380], comb[380][380];
int sxor[maxn], circ[maxn], chk[maxn], mark[maxn];
ui lb[maxn], state[maxn];
vector<pair<int, int>> G[maxn];
unordered_map<ui, int> mp;

ui merge(ui a, ui b) {
    if (!a || !b || (a & b) > 1) return 0;
    ui c = 0;
    for (int i = 0; i < 32; i++) if (a >> i & 1) {
        for (int j = 0; j < 32; j++) if (b >> j & 1) c |= 1u << (i ^ j);
    }
    return c;
}

void red(int &x) { x += x >> 31 & P; }

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    auto get = [&](int x) {
        return !x ? 0 : (1u << x) | 1;
    };
    function<void(int, int, int)> dfs = [&](int v, int fa, int bel) {
        if (fa == 1) mark[v] = 1;
        dep[v] = dep[fa] + 1;
        for (auto e : G[v]) if (e.first ^ fa) {
            int u = e.first, w = e.second;
            if (!dep[u]) {
                sxor[u] = sxor[v] ^ w, dfs(u, v, v == 1 ? u : bel);
            } else if (dep[u] < dep[v]) {
                if (u == 1) chk[bel] |= fa == bel, circ[bel] = sxor[v] ^ w;
                else lb[bel] = merge(lb[bel], get(sxor[v] ^ sxor[u] ^ w));
            }
        }
    };
    fill(lb + 1, lb + n + 1, 1), dfs(1, 0, 0);
    function<void(ui)> init = [&](ui S) {
        if (mp.count(S)) return;
        state[mp[S] = ++tot] = S;
        for (int i = 1; i < 32; i++) if (!(S >> i & 1)) {
            ui nS = S;
            for (int j = 0; j < 32; j++) if (S >> j & 1) nS |= 1u << (i ^ j);
            init(nS);
        }
    };
    init(1), f[1] = 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= tot; j++) {
            comb[i][j] = mp[merge(state[i], state[j])];
        }
    }
    for (auto e : G[1]) if (mark[e.first]) {
        memset(g, 0, sizeof(g));
        int v = e.first;
        if (chk[v]) {
            ui tmp = merge(lb[v], get(circ[v]));
            lb[v] = mp[lb[v]], tmp = mp[tmp];
            for (int i = 1; i <= tot; i++) if (f[i]) {
                red(g[i] += f[i] - P);
                red(g[comb[i][lb[v]]] += 2 * f[i] % P - P);
                red(g[comb[i][tmp]] += f[i] - P);
            }
        } else {
            lb[v] = mp[lb[v]];
            for (int i = 1; i <= tot; i++) if (f[i]) {
                red(g[i] += f[i] - P);
                red(g[comb[i][lb[v]]] += f[i] - P);
            }
        }
        swap(f, g);
    }
    for (int i = 1; i <= tot; i++) {
        red(ans += f[i] - P);
    }
    printf("%d\n", ans);
    return 0;
}