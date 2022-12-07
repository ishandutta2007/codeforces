#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Edge {
    int to, rev, cap, f = 0;
    Edge(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

vector<Edge> g[100];
int dist[100], q[100], pos[100];
int nodes, src, dest;

void addEdge(int from, int to, int cap) {
    g[from].pb(Edge(to, (int)g[to].size(), cap));
    g[to].pb(Edge(from, (int)g[from].size() - 1, 0));
}

bool bfs() {
    REP(i, nodes) dist[i] = -1;
    dist[src] = 0;
    q[0] = src;
    for (int qh = 0, qt = 1; qh != qt; ++qh) {
        int v = q[qh];
        for (Edge e : g[v]) if (e.f < e.cap && dist[e.to] == -1) {
            dist[e.to] = dist[v] + 1;
            q[qt++] = e.to;
        }
    }
    return dist[dest] != -1;
}

int dfs(int v, int flow) {
    if (v == dest) return flow;
    for (int &i = pos[v]; i < (int)g[v].size(); ++i) {
        Edge &e = g[v][i];
        if (e.f < e.cap && dist[e.to] == dist[v] + 1) {
            int df = dfs(e.to, min(flow, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[e.to][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int flow = 0;
    while (bfs()) {
        REP(i, nodes) pos[i] = 0;
        while (int df = dfs(src, 12341234)) {
            flow += df;
        }
    }
    return flow;
}

int n, cnt;
int c[6][6] = {}, rem[6][6];
vector<int> nums[6];
int ord[6], pre[6];
bool used[6] = {};
PII pairs[22];

void go(int pos) {
    if (pos == cnt) {
        REP(i, cnt) REP(j, cnt) rem[i][j] = c[i][j];
        for (int i = 1; i < cnt; ++i) {
            int a = ord[i];
            int b = ord[pre[i]];
            if (a > b) swap(a, b);
            if (rem[a][b] == 0) return;
            --rem[a][b];
        }
        pos = 0;
        REP(i, nodes) g[i].clear();
        REP(i, cnt) for (int j = i; j < cnt; ++j) {
            addEdge(i, cnt + pos, 12341234);
            if (i != j) addEdge(j, cnt + pos, 12341234);
            addEdge(cnt + pos, dest, rem[i][j]);
            pairs[pos] = mp(i, j);
            ++pos;
        }
        REP(i, cnt) addEdge(src, i, (int)nums[i].size() - 1);
        if (maxFlow() != n - cnt) return;
        for (int i = 1; i < cnt; ++i) {
            int a = ord[i];
            int b = ord[pre[i]];
            printf("%d %d\n", nums[a].back(), nums[b].back());
        }
        int x[cnt];
        REP(i, cnt) x[i] = nums[i].back();
        REP(i, cnt) nums[i].pop_back();
        REP(i, cnt) for (Edge e : g[i]) if (e.f > 0) {
            int tmp = e.to - cnt;
            int from = pairs[tmp].first == i ? pairs[tmp].second : pairs[tmp].first;
            REP(times, e.f) {
                printf("%d %d\n", x[from], nums[i].back());
                nums[i].pop_back();
            }
        }
        exit(0);
    }
    REP(i, cnt) if (!used[i]) REP(j, pos) {
        ord[pos] = i;
        pre[pos] = j;
        used[i] = true;
        go(pos + 1);
        used[i] = false;
    }
}

int proc() {
    char s[10];
    scanf("%s", s);
    return strlen(s) - 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n - 1) {
        int a = proc(), b = proc();
        if (a > b) swap(a, b);
        ++c[a][b];
    }
    cnt = 0;
    for (int m = n; m; m /= 10) ++cnt;
    int cap = 10, cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == cap) ++cur, cap *= 10;
        nums[cur].pb(i);
    }
    src = cnt;
    for (int i = 1; i <= cnt; ++i) src += i;
    dest = src + 1;
    nodes = dest + 1;
    ord[0] = 0;
    used[0] = true;
    go(1);
    printf("-1\n");
    return 0;
}