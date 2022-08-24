#include <iostream>
#include <vector>
#include <cassert>
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
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

struct TEdge {
    int from, to;
    int c, ocost, cost, w;

    TEdge(int from = 0, int to = 0, int c = 0, int cost = 0)
        : from(from)
        , to(to)
        , c(c)
        , ocost(cost)
        , cost(cost)
        , w(0)
    {
    }
};

const int MAXN = 6500;
const int MAXM = 50000;
const int INF = 1e8;

vi e[MAXN];
TEdge edges[2 * MAXM];
int ec = 0;

void addEdge(int from, int to, int c, int cost) {
    if (c <= 0) return;
    e[from].pb(ec);
    edges[ec++] = TEdge(from, to, c, cost);
    e[to].pb(ec);
    edges[ec++] = TEdge(to, from, 0, -cost);
}

int dist[MAXN], vis[MAXN], par[MAXN], pushed[MAXN];
int pot[MAXN];

void init(int N) {
    forn(i, N) {
        dist[i] = INF;
        vis[i] = 0;
        par[i] = -1;
        pushed[i] = 0;
    }
}

void reduceCost() {
    forn(i, ec) {
        if (edges[i].w < edges[i].c) {
            edges[i].cost += dist[edges[i].from] - dist[edges[i].to];
            edges[i ^ 1].cost = 0;
        }
    }
}

int push(int from, int to, int N) {
    init(N);
    dist[from] = 0;
    pushed[from] = INF;
    forn(it, N) {
        int m = -1;
        forn(i, N) {
            if (vis[i]) continue;
            if (m == -1 || dist[m] > dist[i]) m = i;
        }
        if (m == -1) break;
        vis[m] = 1;
        for (int id: e[m]) {
            if (edges[id].w >= edges[id].c) continue;
            int to = edges[id].to;
            int w = edges[id].cost;
            if (dist[m] + w < dist[to]) {
                dist[to] = dist[m] + w;
                par[to] = id;
                pushed[to] = min(pushed[m], edges[id].c - edges[id].w);
            }
        }
    }
    reduceCost();
    if (!pushed[to]) return 0;
    int pt = pushed[to];
    int v = to;
    while (par[v] != -1) {
        int id = par[v];
        edges[id].w += pt;
        edges[id ^ 1].w -= pt;
        v = edges[id].from;
    }
    return pt;
}

void maxflow_mincost(int from, int to, int N) {
    init(N);
    dist[from] = 0;
    bool changed;
    do {
        changed = false;
        forn(i, ec) {
            if (edges[i].w >= edges[i].c) continue;
            changed |= uin(dist[edges[i].to], dist[edges[i].from] + edges[i].cost);
        }
    } while (changed);
    reduceCost();
    while (push(from, to, N)) {}
}

int f[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif
    
    int H, W;
    cin >> H >> W;
    forn(i, H) forn(j, W) cin >> f[i][j];
    int S = 0, T = 1;
    int offF = 2;
    forn(i, H) forn(j, W) {
        int v = offF + i * W + j;
        if ((i + j) & 1) {  
            addEdge(v, T, 1, 0);
        } else {
            addEdge(S, v, 1, 0);
            forn(d, 4) {
                int ii = i + dx[d], jj = j + dy[d];
                int u = offF + ii * W + jj;
                if (ii < 0 || jj < 0 || ii >= H || jj >= W) continue;
                addEdge(v, u, 1, f[i][j] == f[ii][jj] ? 0 : 1);
            }
        }
    }
    maxflow_mincost(S, T, H * W + 2);
    int ans = 0;
    forn(i, ec) {
        if (!(i & 1)) ans += edges[i].w * edges[i].ocost;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}