#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct edge {
    int a, b, cost, idx;
    bool operator<(const edge& rhs) const {
        return cost < rhs.cost;
    }
} e[100105];

int n, parent[100105], sz[100105], rnk[100105];
ll ans[100105];
int total;
int u[100105], ses;
vector<pii> g[100105];

int dsu_get(int v) {
    if (parent[v] != v)
        parent[v] = dsu_get(parent[v]);
    return parent[v];
}

void dsu_unite(int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        if (rnk[a] == rnk[b]) ++rnk[a];
    }
}

void dfs1(int x, int p = -1) {
    total += sz[x];
    for (pii& to : g[x])
        if (to.first != p)
            dfs1(to.first, x);
}

int dfs2(int x, int p = -1) {
    u[x] = ses;
    int ret = sz[x];
    for (pii& to : g[x]) {
        if (to.first == p) continue;
        int ret2 = dfs2(to.first, x);
        ans[to.second] = 2 * ll(total - ret2) * ret2;
        ret += ret2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> e[i].a >> e[i].b >> e[i].cost;
        e[i].idx = i;
    }
    iota(parent + 1, parent + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    sort(e, e + n - 1);
    for (int i = 0; i < n - 1; ) {
        int nxt = i;
        while (nxt < n - 1 && e[nxt].cost == e[i].cost)
            ++nxt;
        for (int j = i; j < nxt; ++j) {
            int a = dsu_get(e[j].a);
            int b = dsu_get(e[j].b);
            g[a].clear();
            g[b].clear();
        }
        vector<int> vertices;
        for (int j = i; j < nxt; ++j) {
            int a = dsu_get(e[j].a);
            int b = dsu_get(e[j].b);
            g[a].emplace_back(b, e[j].idx);
            g[b].emplace_back(a, e[j].idx);
            vertices.push_back(a);
            vertices.push_back(b);
        }
        sort(vertices.begin(), vertices.end());
        vertices.resize(unique(vertices.begin(), vertices.end()) - vertices.begin());
        ses += 2;
        for (int x : vertices) {
            if (u[x] != ses) {
                total = 0;
                dfs1(x);
                dfs2(x);
            }
        }
        while (i < nxt)
            dsu_unite(e[i].a, e[i].b), ++i;
    }
    ll mx = *max_element(ans, ans + n - 1);
    vector<int> v;
    for (int i = 0; i < n - 1; ++i)
        if (ans[i] == mx)
            v.push_back(i + 1);
    cout << mx << " " << v.size() << "\n";
    for (int x : v)
        cout << x << " ";
}