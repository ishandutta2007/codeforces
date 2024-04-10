#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


class UnionFind
{
public:
    std::vector<int> parent;
    UnionFind(int n);
    int find(int x);
    void link(int a, int b);
};


class Biconnected
{
    int intime;
    int cc;
    std::vector<int> vis;

public:
    std::vector< std::pair<int, int> > bridges;
    std::vector<int> comp;
    UnionFind dsu;
    Biconnected(const std::vector<int>* G, int n);
    int biponte(const std::vector<int>* G, int v, int pai);
};


class LCA
{
public:
    int logn;
    std::vector<int> height;
    std::vector< std::vector<int> > parent;

    LCA(const std::vector<int>* adj, int n, int root = 0);
    void dfsInit(const std::vector<int>* G, int v, int p);
    int goup(int a, int dist);
    int query(int a, int b);
};


using namespace std;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int n, m, q;

vector<int> G[210000];
vector<int> temp[210000];

int rise[210000]; // RISE FROM YOUR GRAVE
int lower[210000];
bool ok;

void dfs_riselow(int v, int p) {
    for (int ch : G[v]) if (ch != p) {
        dfs_riselow(ch, v);

        rise[v] += rise[ch];
        lower[v] += lower[ch];
    }

    if (rise[v] && lower[v]) {
        ok = false;
    }
}

void solve() {
    ok = true;

    scanf("%d %d %d", &n, &m, &q);
    REP(i, n) G[i].clear();
    memset(rise, 0, sizeof(rise));
    memset(lower, 0, sizeof(lower));

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    Biconnected biconn(G, n);

    REP(i, n) temp[i] = G[i];
    for (int i = 0; i < n; i++) G[i].clear();
    
    REP(i, n) {
        int v1 = i;
        for (int v2 : temp[i]) {
            int x = biconn.dsu.find(v1);
            int y = biconn.dsu.find(v2);
            if (x != y) {
                G[x].push_back(y);
            }
        }
    }

    LCA lca(G, n);

    ok = true;
    for (int i = 0; i < q; i++) {
        int s, d;
        scanf("%d %d", &s, &d); s--; d--;

        int x = biconn.dsu.find(s), y = biconn.dsu.find(d);
        if (x == y) continue;
        if (biconn.comp[x] != biconn.comp[y]) {
            ok = false;
            continue;
        }

        int kk = lca.query(x, y);
        rise[x]++;
        rise[kk]--;
        lower[y]++;
        lower[kk]--;
    }

    int nxt = 0;
    for (int i = 0; i < n; i++) {
        if (biconn.comp[i] == nxt) {
            dfs_riselow(biconn.dsu.find(i), -1);
            nxt++;
        }
    }

    printf("%s\n", ok ? "Yes" : "No");
}
int main() {
    solve();
}


UnionFind::UnionFind(int n)
{
    parent = std::vector<int>(n);
    for (int i = 0; i < n; i++) parent[i] = i;
}

int UnionFind::find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void UnionFind::link(int a, int b) {
    int x = find(a), y = find(b);
    parent[y] = x;
}


LCA::LCA(const std::vector<int> *adj, int n, int root) {
    logn = 0;
    while ((1 << (logn + 1)) <= n) logn++;

    height = std::vector<int>(n, -1);
    parent = std::vector< std::vector<int> >(n, std::vector<int>(logn+1, 0));

    height[root] = 0;
    parent[root][0] = root;
    dfsInit(adj, root, -1);

    for (int i = 0; i < n; i++) {
        if (height[i] == -1) {
            height[i] = 0;
            parent[i][0] = i;
            dfsInit(adj, i, -1);
        }
    }
}

void LCA::dfsInit(const std::vector<int> *G, int v, int p) {
    for (int l = 1; l <= logn; l++) {
        parent[v][l] = parent[parent[v][l - 1]][l - 1];
    }

    for (int v2 : G[v]) {
        if (v2 == p) continue;
        height[v2] = height[v] + 1;
        parent[v2][0] = v;
        dfsInit(G, v2, v);
    }
}

int LCA::goup(int a, int dist) {
    for (int l = 0; dist; l++)
        if (dist & (1 << l)) {
            a = parent[a][l];
            dist -= (1 << l);
        }
    return a;
}

int LCA::query(int a, int b) {
    if (height[a] < height[b]) std::swap(a, b);
    a = goup(a, height[a] - height[b]);
    if (a == b) return a;
    for (int l = logn; l >= 0; l--) {
        if (parent[a][l] != parent[b][l])
            a = parent[a][l], b = parent[b][l];
    }
    return parent[a][0];
}


int Biconnected::biponte(const std::vector<int>* G, int v, int pai){
    if (vis[v]) return vis[v];
    comp[v] = cc;
    int R = vis[v] = intime++;
    bool ignored_back_edge = false;
    for (int a : G[v]) {
        if (a == pai && !ignored_back_edge) {
            ignored_back_edge = true;
            continue;
        }
        int r = biponte(G, a, v);
        if (r < R){
            dsu.link(v, a);
            R = r;
        }
    }
    if (R >= vis[v] && pai != -1) {
        bridges.push_back({ v, pai });
    }
    
    return R;
}

Biconnected::Biconnected(const std::vector<int>* G, int n) : dsu(n) {
    vis = std::vector<int>(n, 0);
    comp = std::vector<int>(n, 0);
    intime = 1;
    cc = 0;
    for (int i = 0; i<n; i++) {
        biponte(G, i, -1);
        cc++;
    }
    vis.clear();
}