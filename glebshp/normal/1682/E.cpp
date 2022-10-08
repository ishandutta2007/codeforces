#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;

int n, m;

int p[maxn];
int parent[maxn];
int parentedge[maxn];
bool used[maxn];
int depth[maxn];

vector <int> ts;

vector <pair <int, int> > vertex[maxn];
vector <int> dirver[maxn];

int marks[maxn];
int mcnt = 0;

void dfs(int v, int p, int pe) {
    parent[v] = p;
    parentedge[v] = pe;
    if (p == -1) {
        depth[v] = 0;
    } else {
        depth[v] = depth[p] + 1;
    }
    used[v] = true;
    for (auto u : vertex[v]) {
        if (u.fs != p) {
            dfs(u.fs, v, u.sc);        
        }
    }
}

vector <int> getpath(int u, int v) {
//    cerr << "getpath " << u << ' ' << v << endl;
    mcnt++;

    int pu = u;
    int pv = v;
    while (depth[pu] > depth[pv]) {
        pu = parent[pu];
    }
    while (depth[pv] > depth[pu]) {
        pv = parent[pv];
    }
    while (pu != pv) {
        pu = parent[pu];
        pv = parent[pv];
    }
    int mid = pu;
    pu = u;
    pv = v;

    vector <int> path;
    while (pu != mid) {
        path.pb(parentedge[pu]);
        pu = parent[pu];
    }
    int len = path.size();
    while (pv != mid) {
        path.pb(parentedge[pv]);
        pv = parent[pv];
    }
    reverse(path.begin() + len, path.end());

    return path;
}

void topsort(int v) {
    used[v] = true;
    for (auto u : dirver[v]) {
        if (!used[u]) {
            topsort(u);
        }
    }

    ts.pb(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        u--, v--;
        vertex[u].pb(mp(v, i));
        vertex[v].pb(mp(u, i));
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1, -1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] != i) {
            vector <int> path = getpath(i, p[i]);
            for (int j = 0; j < (int) path.size() - 1; j++) {
                dirver[path[j]].pb(path[j + 1]);
            }
        }
    }

  //  cerr << "graph ready" << endl;
    
    for (int i = 0; i < m; i++) {
        used[i] = false;
    }
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            topsort(i);
        }
    }
    reverse(ts.begin(), ts.end());
    for (int i = 0; i < (int) ts.size(); i++) {
        printf("%d ", ts[i] + 1);
    }
    printf("\n");

    return 0;
}