#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[500005];
vector<int> p[500005];
int pnum[500005], pind[500005], sz[500005];
int dep[500005] = {}, uv[500005];
int pc = 1;
int z[500005];
vector<int> vz[500005];
int vp[500005];

void calcSize(int v, int par) {
    sz[v] = 1;
    if (par == -1) {
        z[v] = 0;
    } else {
        z[v] = z[par] + 1;
    }
    vp[v] = par;
    for (int to : g[v]) if (to != par) {
        calcSize(to, v);
        sz[v] += sz[to];
    }
}

void dfs(int v, int par, int path) {
    pnum[v] = path;
    pind[v] = (int)p[path].size();
    p[path].pb(v);
    for (int to : g[v]) if (to != par) {
        if (sz[to] * 2 >= sz[v]) {
            dfs(to, v, path);
        } else {
            dep[pc] = dep[path] + 1;
            uv[pc] = v;
            dfs(to, v, pc++);
        }
    }
}

vector<int> a[500005];
vector<LL> b[500005];

void aAdd(vector<int> &fen, int ind, int val) {
    for (; ind < (int)fen.size(); ind |= ind + 1) {
        fen[ind] += val;
    }
}

void bAdd(vector<LL> &fen, int ind, LL val) {
    for (; ind < (int)fen.size(); ind |= ind + 1) {
        fen[ind] += val;
    }
}

int aGet(vector<int> &fen, int ind) {
    int res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res += fen[ind];
    }
    return res;
}

LL bGet(vector<LL> &fen, int ind) {
    LL res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res += fen[ind];
    }
    return res;
}

void add(int ind, int to) {
    aAdd(a[ind], 0, 1);
    if (to < (int)a[ind].size() - 1) {
        aAdd(a[ind], to + 1, -1);
        bAdd(b[ind], to + 1, to + 1);
    }
}

LL calc(int ind, int to) {
    int aa = aGet(a[ind], to);
    LL bb = bGet(b[ind], to);
    return (LL)aa * (to + 1) + bb;
}

void hldUpdate(int v) {
    int pv = pnum[v];
    while (true) {
        add(pv, pind[v]);
        v = uv[pv];
        if (v == -1) {
            break;
        }
        pv = pnum[v];
    }
}

LL hldQuery(int v) {
    int pv = pnum[v];
    LL res = 0;
    while (true) {
        res += calc(pv, pind[v]);
        v = uv[pv];
        if (v == -1) {
            break;
        }
        pv = pnum[v];
    }
    return res;
}

int dist(int u, int v) {
    int pu = pnum[u], pv = pnum[v], ret = 0;
    while (pu != pv) {
        if (dep[pu] > dep[pv]) {
            ret += pind[u] + 1;
            u = uv[pu];
            pu = pnum[u];
        } else {
            ret += pind[v] + 1;
            v = uv[pv];
            pv = pnum[v];
        }
    }
    return ret + abs(pind[u] - pind[v]);
}

LL ans[500005];

int main() {
//    freopen("input.txt", "r", stdin);
    int root = -1;
    memset(uv, -1, sizeof uv);
    if (0) {
        n = 500000;
        mt19937 mt(123);
        for (int i = 0; i < n; ++i) {
            int from = i, to;
            if (i == 0) {
                to = -1;
            } else {
                to = mt() % i;
            }
            if (to == -1) {
                root = i;
            } else {
                g[from].pb(to);
                g[to].pb(from);
            }
        }
    } else {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int from = i, to;
            scanf("%d", &to), --to;
            if (to == -1) {
                root = i;
            } else {
                g[from].pb(to);
                g[to].pb(from);
            }
        }
    }
    calcSize(root, -1);
    dfs(root, -1, 0);
    forn(i, n) vz[z[i]].pb(i);
    forn(i, pc) {
        a[i].assign(p[i].size(), 0);
        b[i].assign(p[i].size(), 0ll);
    }
    for (int i = 1; i < n; ++i) if (!vz[i].empty()) {
        for (int x : vz[i]) {
            hldUpdate(vp[x]);
        }
        for (int x : vz[i]) {
            ans[x] = hldQuery(vp[x]);
        }
    }
    forn(i, n) printf("%I64d ", ans[i]);
    puts("");
	return 0;
}