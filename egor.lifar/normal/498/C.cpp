#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <bitset>


using namespace std;



#define INF 1000000002


struct edge {
    int a, b, cap, flow;
};


int n, s, t, d[2601], ptr[2601], q[2601];
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


set<int> ss;
int N, M;
int a[110], b[110];
int x[110];


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)  {
        cin >> x[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--; 
        b[i]--;
        if (a[i] % 2 == 1) {
            swap(a[i], b[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        int y = x[i];
        for (int d = 2; d * d <= y; d++) {
            if (y % d == 0) {
                ss.insert(d);
                while (y % d == 0) {
                    y /= d;
                }
            }
        }
        if (y > 1) {
            ss.insert(y);
        }
    }
    int ans = 0;
    for (auto p: ss) {
        s = N;
        t = N + 1;
        e.clear();
        for (int i = 0; i <= N + 1; i++) {
            g[i].clear();
            d[i] = 0;
            ptr[i] = 0;
            q[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            int y = x[i], cnt = 0;
            while(y % p == 0) {
                y /= p;
                cnt++;
            }
            if (i % 2 == 0) {
                add_edge(s, i, cnt);
            } else {
                add_edge(i, t, cnt);
            }
        }
        for (int i = 0; i < M; i++) {
            add_edge(a[i], b[i], 100);
        }
        n = N + 2;
        ans += dinic();
    }
    cout << ans << endl;
    return 0;
}