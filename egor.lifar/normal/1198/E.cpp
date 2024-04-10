/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 105;


int n;
int m;
int xl[MAXN], yl[MAXN], xr[MAXN], yr[MAXN];
bool need[MAXN][MAXN];
#define INF 1000000002


struct edge {
    int a, b, cap, flow;
};


int s, t, d[2601], ptr[2601], q[2601];
vector<edge> e;
vector<int> g[2601];


void add_edge(int a, int b, int cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
}


bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, sizeof(d));
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (unsigned int i = 0; i < g[v].size(); i++) {
            int id = g[v][i], to = e[id].b;
            if (d[v] != -1 && d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow) {
    if (!flow) {
        return 0;
    }
    if (v == t) {
        return flow;
    }
    for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
        int id = g[v][ptr[v]], to = e[id].b;
        if (d[to] != d[v] + 1)  {
            continue;
        }
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}


int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs()) {
            break;
        }
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs(s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    vector<int> stx, sty;
    for (int i = 0; i < m; i++) {
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
        stx.pb(xl[i]);
        stx.pb(xr[i] + 1);
        sty.pb(yl[i]);
        sty.pb(yr[i] + 1);
    }
    sort(all(stx));
    stx.resize(distance(stx.begin(), unique(all(stx))));
    sort(all(sty));
    sty.resize(distance(sty.begin(), unique(all(sty))));
    for (int i = 0; i < m; i++) {
        xl[i] = lower_bound(all(stx), xl[i]) - stx.begin();
        xr[i] = upper_bound(all(stx), xr[i]) - stx.begin();
        yl[i] = lower_bound(all(sty), yl[i]) - sty.begin();
        yr[i] = upper_bound(all(sty), yr[i]) - sty.begin();
        for (int j = xl[i]; j < xr[i]; j++) {
            for (int k = yl[i]; k < yr[i]; k++) {
                need[j][k] = true;
            }
        }
    }
    s = 0;
    t = sz(stx) + sz(sty) + 2;
    for (int i = 0; i < sz(stx); i++) {
        for (int j = 0; j < sz(sty); j++) {
            if (need[i][j]) {
                add_edge(i + 1, j + 1 + sz(stx), 1e9);
            }
        }
        if (i != sz(stx) - 1) {
            add_edge(s, i + 1, stx[i + 1] - stx[i]);
        }
    }
    for (int j =0; j < sz(sty) - 1; j++) {
                        add_edge(j + 1 + sz(stx), t, sty[j + 1] - sty[j]);
    }
    cout << dinic() << endl;
    return 0;
}