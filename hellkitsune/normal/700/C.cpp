#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Edge {
    int to, w, ind;
    Edge(int to, int w, int ind) : to(to), w(w), ind(ind) {}
    Edge() {}
};

int n, m, s, t;
vector<Edge> g[1005], ng[1005];
int ecost[30005];
bool bad[30005] = {};
bool used[1005] = {};
set<int> se;
int path[1005], pc = 0;
bool pathFound = false;

void dfs(int v, int p) {
    used[v] = true;
    for (Edge &e : g[v]) if (e.ind != p) {
        if (used[e.to]) {
            bad[e.ind] = true;
        } else {
            ng[v].pb(e);
            ng[e.to].pb(Edge(v, e.w, e.ind));
            dfs(e.to, e.ind);
        }
    }
}

void findPath(int v, int p) {
    path[pc++] = v;
    if (v == t) {
        pathFound = true;
        return;
    }
    for (Edge &e : ng[v]) if (e.to != p) {
        findPath(e.to, v);
        if (pathFound) {
            return;
        }
    }
    --pc;
}

const int INF = 2e9 + 111;
int minCost = INF;
int minCount = -1;
int road1, road2;

int tin[1005], fup[1005], timer;
int remInd;

bool go(int v, int p) {
    tin[v] = fup[v] = timer++;
    bool flag = v == t;
    for (Edge e : g[v]) if (e.ind != p && e.ind != remInd) {
        if (tin[e.to] == -1) {
            bool haveT = go(e.to, e.ind);
            fup[v] = min(fup[v], fup[e.to]);
            if (fup[e.to] > tin[v] && haveT) {
                if (ecost[remInd] + ecost[e.ind] < minCost) {
                    minCost = ecost[remInd] + ecost[e.ind];
                    minCount = 2;
                    road1 = remInd;
                    road2 = e.ind;
                }
            }
            flag = flag || haveT;
        } else {
            fup[v] = min(fup[v], tin[e.to]);
        }
    }
    return flag;
}

int pathInd = 0;
void solve(int v, int p) {
    if (v == t) {
        return;
    }
    ++pathInd;
    Edge e = Edge(-1, -1, -1);
    for (Edge &ee : ng[v]) if (ee.to == path[pathInd]) {
        e = ee;
        break;
    }
    assert(e.ind != -1);
    remInd = e.ind;
    REP(i, n) tin[i] = fup[i] = -1;
    timer = 0;
    if (!go(s, -1)) {
        if (e.w < minCost) {
            minCost = e.w;
            minCount = 1;
            road1 = e.ind;
        }
    }
    solve(e.to, v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &t), --s, --t;
    REP(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        ecost[i] = w;
        if (from == to) continue;
        g[from].pb(Edge(to, w, i));
        g[to].pb(Edge(from, w, i));
    }
    dfs(s, -1);
    findPath(s, -1);
    if (!pathFound) {
        printf("0\n0\n");
        return 0;
    }
//    REP(i, pc) cerr << path[i] + 1 << ' ';
//    cerr << endl;
//    REP(i, n) for (Edge e : ng[i]) if (e.to > i) {
//        cerr << i + 1 << ' ' << e.to + 1 << endl;
//    }
//    cerr << "!" << endl;
    solve(s, -1);
    if (minCount == -1) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", minCost, minCount);
        printf("%d", road1 + 1);
        if (minCount == 2) {
            printf(" %d", road2 + 1);
        }
        printf("\n");
    }
    return 0;
}