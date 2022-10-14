// Codeforces Testing Round #2
// Problem E -- MST Company
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 5555;
const int M = 222222;
const int INF = 1000000000;

int a[M], b[M], c[M], order[M], 
    parent[N], best[N], candidate[N],
    firstEdge[N], to[M], nextEdge[M],
    adj[N];
bool choose[M];

bool compare(int i, int j) {
    return c[i] < c[j];
}

int findRoot(int i) {
    if (parent[i] != i) {
        parent[i] = findRoot(parent[i]);
    }
    return parent[i];
}

void addEdge(int i, int u, int v) {
    to[i] = v;
    nextEdge[i] = firstEdge[u];
    firstEdge[u] = i;
}

void dfs(int p, int u) {
    for (int iter = firstEdge[u]; iter != -1; iter = nextEdge[iter]) {
        if (!choose[iter >> 1]) {
            continue;
        }
        int v = to[iter];     
        if (p == v) {
            continue;
        }
        if (u) {
            best[v] = c[iter >> 1];
            candidate[v] = iter >> 1;
            if (best[u] > best[v]) {
                best[v] = best[u];
                candidate[v] = candidate[u];
            }
        } else {
            best[v] = -INF;
        }
        dfs(u, v);
    }
}

void myAddEdge(int i) {
    addEdge(i + i, a[i], b[i]);
    addEdge(i + i + 1, b[i], a[i]);
}

vector <int> mst(int n, int limit, vector <pair <pair <int, int>, int> > &edges) { 
    int m = (int)edges.size();
    for (int i = 0; i < m; ++ i) {
        a[i] = edges[i].first.first;
        b[i] = edges[i].first.second;
        c[i] = edges[i].second;
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        order[i] = i;
    }
    sort(order, order + m, compare);
    for (int i = 0; i < n; ++ i) {
        parent[i] = i;
    }
    memset(choose, 0, sizeof(choose));
    for (int i = 0; i < m; ++ i) {
        int e = order[i];
        if (!a[e] || findRoot(a[e]) == findRoot(b[e])) {
            continue;
        }
        choose[e] = true;
        parent[findRoot(a[e])] = findRoot(b[e]);
    }    
    int component = 0;
    for (int i = 1; i < n; ++ i) {
        if (findRoot(i) == i) {
            component ++;
            best[i] = INF;
        }
    }
    if (component > limit) {
        return vector <int>(1, -1);
    }
    memset(adj, -1, sizeof(adj));
    for (int i = 0; i < m; ++ i) {
        if (a[i]) {
            continue;
        }
        adj[b[i]] = i;
        int r = findRoot(b[i]); 
        if (c[i] < best[r]) {
            best[r] = c[i];
            candidate[r] = i;
        }
    }
    for (int i = 1; i < n; ++ i) {
        if (findRoot(i) == i) {
            if (best[i] == INF) {
                return vector <int>(1, -1);
            }
            choose[candidate[i]] = true;
        }
    }
    memset(firstEdge, -1, sizeof(firstEdge));
    for (int i = 0; i < m; ++ i) {
        if (choose[i]) {
            myAddEdge(i);
        }
    }
    while (component < limit) {
        dfs(-1, 0);
        int tmpBest = INF,
            tmpCandidate;
        for (int i = 1; i < n; ++ i) {
            if (adj[i] == -1 || best[i] == -INF) {
                continue;
            }
            if (c[adj[i]] - best[i] < tmpBest) {
                tmpBest = c[adj[i]] - best[i];
                tmpCandidate = i;
            }
        }
        if (tmpBest == INF) {
            return vector <int>(1, -1);
        }
        choose[candidate[tmpCandidate]] = false;
        choose[adj[tmpCandidate]] = true;
        myAddEdge(adj[tmpCandidate]);
        component ++;
    }
    vector <int> result;
    for (int i = 0; i < m; ++ i) {
        if (choose[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int n, m, limit;

int main() {
    scanf("%d%d%d", &n, &m, &limit);
    vector <pair <pair <int, int>, int> > edges;
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back(make_pair(make_pair(a - 1, b - 1), c));
    }
    vector <int> ret = mst(n, limit, edges);
    if (ret.size() && ret[0] == -1) {
        puts("-1");
    } else {
        printf("%d\n", (int)ret.size());
        for (int i = 0; i < (int)ret.size(); ++ i) {
            printf("%d%c", ret[i] + 1, i + 1 == (int)ret.size()? '\n': ' ');
        }
    }     
    return 0;
}