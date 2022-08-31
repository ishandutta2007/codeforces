#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 100010;
const int maxk = 17;

struct TNode {
    int L, R;
    int lc, rc;
    int sum;
    bool sw;

    TNode(int L = 0, int R = 0)
        : L(L)
        , R(R)
        , lc(-1)
        , rc(-1)
        , sum(0)
        , sw(false)
    {
    }
};

TNode t[3 * maxn];
int tc = 0;

int build(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L > 1) {
        int M = (L + R) / 2;
        t[node].lc = build(L, M);
        t[node].rc = build(M, R);
    }
    return node;
}

void relax(int node) {
    if (t[node].sw) {
        t[node].sw = false;
        t[node].sum = t[node].R - t[node].L - t[node].sum;
        if (t[node].R - t[node].L > 1) {
            t[t[node].lc].sw ^= true;
            t[t[node].rc].sw ^= true;
        }
    }
}

void combine(int node) {
    t[node].sum = t[t[node].lc].sum + t[t[node].rc].sum;
}

int getsum(int node, int L, int R) {
    relax(node);
    if (R <= t[node].L || t[node].R <= L) {
        return 0;
    }
    if (L <= t[node].L && t[node].R <= R) {
        return t[node].sum;
    }
    return getsum(t[node].lc, L, R) + getsum(t[node].rc, L, R);
}

void swapseg(int node, int L, int R) {
    relax(node);
    if (R <= t[node].L || t[node].R <= L) {
        return;
    }
    if (L <= t[node].L && t[node].R <= R) {
        t[node].sw = true;
        relax(node);
        return;
    }
    swapseg(t[node].lc, L, R);
    swapseg(t[node].rc, L, R);
    combine(node);
}

int N, M;

vi e[maxn];
int par[maxn], d[maxn], w[maxn];
int root[maxn], len[maxn], sky[maxn], tr[maxn];
int up[maxk + 1][maxn];

int A, B;
bool enabled;

void dfs_build(int v, int p) {
    par[v] = p;
    d[v] = (p == -1 ? 0 : d[p] + 1);
    w[v] = 1;
    root[v] = v;
    len[v] = 1;
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) {
            continue;
        }
        if (d[u] == -1) {
            dfs_build(u, v);
            w[v] += w[u];
        } else {
            A = u;
            B = v;
        }
    }
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) {
            continue;
        }
        if (d[u] == d[v] + 1 && 2 * w[u] >= w[v]) {
            root[v] = root[u];
            ++len[root[v]];
        }
    }
}

void build_up() {
    forn(i, N) {
        up[0][i] = par[i];
    }
    forn(j, maxk) {
        forn(i, N) {
            up[j + 1][i] = (up[j][i] == -1 ? -1 : up[j][up[j][i]]);
        }
    }
}

int get_up(int v, int d) {
    for (int j = maxk; j >= 0; --j) {
        if ((1 << j) <= d) {
            d -= 1 << j;
            v = up[j][v];
        }
    }
    return v;
}

int lca(int v, int u) {
    if (d[v] < d[u]) {
        swap(v, u);
    }
    v = get_up(v, d[v] - d[u]);
    if (v == u) {
        return v;
    }
    for (int j = maxk; j >= 0; --j) {
        if (up[j][v] != up[j][u]) {
            v = up[j][v];
            u = up[j][u];
        }
    }
    return par[v];
}

int dist(int v, int u) {
    int w = lca(u, v);
    return d[u] + d[v] - 2 * d[w];
}

int total;

void swap_up(int v, int x) {
    int r = root[v];
    int p = d[r] - d[v];
    total += getsum(tr[r], 0, len[r]);
    if (p + x <= len[r]) {
        swapseg(tr[r], p, p + x);
    } else {
        swapseg(tr[r], p, len[r]);
        swap_up(sky[r], x - (len[r] - p));
    }
    total -= getsum(tr[r], 0, len[r]);
}

void swap_path(int x, int y) {
    int w = lca(x, y);
    swap_up(x, d[x] - d[w]);
    swap_up(y, d[y] - d[w]);
}

int sum_up(int v, int x) {
    int r = root[v];
    int p = d[r] - d[v];
    if (p + x <= len[r]) {
        return getsum(tr[r], p, p + x);
    } else {
        return getsum(tr[r], p, len[r]) + sum_up(sky[r], x - (len[r] - p));
    }
}

int onpath(int x, int y, int z) {
    int w = lca(x, y), l = dist(x, y);
    if (z <= d[x] - d[w]) {
        return get_up(x, z);
    } else {
        return get_up(y, l - z);
    }
}

int fork(int x) {
    int d1 = dist(x, A), d2 = dist(x, B), d3 = dist(A, B);
    return onpath(x, A, (d1 + d2 - d3) / 2);
}

int bonus() {
    if (!enabled) {
        return 0;
    }
    int w = lca(A, B);
    if (sum_up(A, d[A] - d[w]) + sum_up(B, d[B] - d[w]) == dist(A, B)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d%d", &N, &M);
    forn(i, N) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, N) {
        d[i] = -1;
    }
    dfs_build(0, -1);
    build_up();
    forn(i, N) {
        if (root[i] == i) {
            tr[i] = build(0, len[i]);
            sky[i] = get_up(i, len[i]);
        }
    }
    if (d[A] > d[B]) {
        swap(A, B);
    }
//    cerr << A << ' ' << B << '\n';
    
    total = N;
    enabled = false;

    forn(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;

        int p = fork(x), q = fork(y);
        if (p == q) {
            swap_path(x, y);
        } else {
            swap_path(x, p);
            swap_path(y, q);
            int lup = d[q] < d[p] ? d[p] - d[q] : d[p] - d[A] + 1 + d[B] - d[q];
            int ldown = d[q] > d[p] ? d[q] - d[p] : d[B] - d[p] + 1 + d[q] - d[A];
            if (lup == ldown) {
                int vup = p == A ? B : par[p];
                int vdown = p == B ? A : get_up(B, d[B] - d[p] - 1);
                if (vup < vdown) {
                    --lup;
                } else {
                    --ldown;
                }
            }
            if (lup < ldown) {
                if (d[q] < d[p]) {
                    swap_path(p, q);
                } else {
                    swap_path(p, A);
                    enabled ^= true;
                    swap_path(B, q);
                }
            } else {
                if (d[q] > d[p]) {
                    swap_path(p, q);
                } else {
                    swap_path(p, B);
                    enabled ^= true;
                    swap_path(q, A);
                }
            }
        }

        cout << total - bonus() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}