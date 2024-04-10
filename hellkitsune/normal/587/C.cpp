#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;
int cur[10], tmp[10];

struct ST {
    int off = 1;
    vector<int> st[10], beg[10];

    ST(int cnt) {
        while (off < cnt) off <<= 1;
        REP(i, 10) st[i].resize(off << 1, INF);
        REP(i, 10) beg[i].resize(off, INF);
    }

    ST() {}

    void update(int pos, int val) {
        pos += off;
        REP(i, 10) if (st[i][pos] > val) {
            for (int j = 9; j > i; --j) st[j][pos] = st[j - 1][pos];
            st[i][pos] = val;
            break;
        }
    }

    void build() {
        REP(i, 10) cur[i] = INF;
        REP(j, off) {
            int v = j + off;
            int a = 0, b = 0;
            REP(i, 10) {
                if (st[a][v] < cur[b]) {
                    tmp[i] = st[a][v];
                    ++a;
                } else {
                    tmp[i] = cur[b];
                    ++b;
                }
            }
            REP(i, 10) cur[i] = tmp[i];
            REP(i, 10) beg[i][j] = cur[i];
        }

        for (int pos = off - 1; pos >= 1; --pos) {
            int a = 0, b = 0;
            int aa = pos << 1;
            int bb = aa | 1;
            REP(i, 10) {
                if (st[a][aa] < st[b][bb]) {
                    st[i][pos] = st[a][aa];
                    ++a;
                } else {
                    st[i][pos] = st[b][bb];
                    ++b;
                }
            }
        }
    }

    void get(int v, int L, int R, int l, int r) {
        if (L == l && R == r) {
            int a = 0, b = 0;
            REP(i, 10) {
                if (st[a][v] < cur[b]) {
                    tmp[i] = st[a][v];
                    ++a;
                } else {
                    tmp[i] = cur[b];
                    ++b;
                }
            }
            REP(i, 10) cur[i] = tmp[i];
            return;
        }
        int mid = (L + R) >> 1;
        if (l <= mid) get(v << 1, L, mid, l, min(r, mid));
        if (r > mid) get((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    }

    void zget(int to) {
        int a = 0, b = 0;
        REP(i, 10) {
            if (beg[a][to] < cur[b]) {
                tmp[i] = beg[a][to];
                ++a;
            } else {
                tmp[i] = cur[b];
                ++b;
            }
        }
        REP(i, 10) cur[i] = tmp[i];
    }
};

int n, m, q;
vector<int> g[100005];
vector<int> p[100005];
vector<ST> vst;
int pnum[100005], pind[100005], sz[100005];
int dep[100005] = {}, uv[100005];
int pc = 1;

void calcSize(int v, int par) {
    sz[v] = 1;
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

inline void query(int path, int from, int to) {
    vst[path].get(1, 0, vst[path].off - 1, from, to);
}

inline void zquery(int path, int to) {
    vst[path].zget(to);
}

void hldQuery(int u, int v) {
    int pu = pnum[u], pv = pnum[v];
    while (pu != pv) {
        if (dep[pu] > dep[pv]) {
            zquery(pu, pind[u]);
            u = uv[pu];
            pu = pnum[u];
        } else {
            zquery(pv, pind[v]);
            v = uv[pv];
            pv = pnum[v];
        }
    }
    int from = pind[u], to = pind[v];
    if (from > to) swap(from, to);
    query(pu, from, to);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    calcSize(0, -1);
    dfs(0, -1, 0);
    REP(i, pc) {
        vst.pb(ST((int)p[i].size()));
    }
    REP(i, m) {
        int x;
        scanf("%d", &x), --x;
        vst[pnum[x]].update(pind[x], i);
    }
    REP(i, pc) {
        vst[i].build();
    }
    REP(i, q) {
        int from, to, a;
        scanf("%d%d%d", &from, &to, &a), --from, --to;
        REP(j, 10) cur[j] = INF;
        hldQuery(from, to);
        REP(j, a) if (cur[j] == INF) {
            a = j;
            break;
        }
        printf("%d", a);
        REP(j, a) printf(" %d", cur[j] + 1);
        printf("\n");
    }
    return 0;
}