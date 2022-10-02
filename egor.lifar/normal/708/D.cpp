#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;

const long long INF = (long long)1e9;
const int MAXN = 200;

struct edge {
    int a, b;
    long long weight, flow, cap;
};
int n, m;
int ff[MAXN];
vector<edge> edges;
vector<int> graph[MAXN];
long long dd[MAXN];
long long en[MAXN];
long long gg[MAXN];
int s, t;


void make_edge(int a, int b, long long cap, long long weight) {
    edge x;
    x.a = a, x.b = b, x.cap = cap, x.weight = weight, x.flow = 0;
    graph[a].push_back(edges.size());
    edges.push_back(x);
    swap(x.a, x.b);
    x.cap = 0;
    x.weight = -x.weight;
    graph[b].push_back(edges.size());
    edges.push_back(x);
}


long long flow(int k) {
    long long nowc = 0;
    while (k > 0) {
        fill(dd, dd + t + 1, INF);
        fill(gg, gg + t + 1, -1);
        dd[s] = 0;
        fill(en, en + t + 1, 0);
        queue<int> q;
        q.push(s);
        en[s] = 1;
        while (!q.empty()) {
            int x = q.front();
            en[x] = 0;
            q.pop();
            for (auto e: graph[x]) {
                int u = edges[e].b;
                long long w = edges[e].weight;
                long long fr = edges[e].cap - edges[e].flow;
                if (fr == 0) {
                    continue;
                }
                if (dd[u] > dd[x] + w) {
                    dd[u] = dd[x] + w;
                    gg[u] = e;
                    if (!en[u]) {
                        q.push(u), en[u] = 1;
                    }
                }
            }
        }
        int now = t;
        long long minFlow = k;
        while (now != s) {
            int e = gg[now];
            minFlow = min(minFlow, edges[e].cap - edges[e].flow);
            now = edges[e].a;
        }
        nowc += dd[t] * minFlow;
        now = t;
        while (now != s) {
            int e = gg[now];
            edges[e].flow += minFlow;
            edges[e ^ 1].flow -= minFlow;
            now = edges[e].a;
        }
        k -= minFlow;
    }
    return nowc;
}




int main() {
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        --u;
        --v;
        ff[u] -= f;
        ff[v] += f;
        if (f <= c) {
            make_edge(u, v, c - f, 1);
            make_edge(u, v, INF, 2);
            make_edge(v, u, f, 1);
        } else {
            ans += f - c;
            make_edge(u, v, INF, 2);
            make_edge(v, u, f - c, 0);
            make_edge(v, u, c, 1);
        }
    }
    long long go = 0;
    s = n;
    t = n + 1;
    for (int i = 1; i < n - 1; ++i) {
        go += abs(ff[i]);
        if (ff[i] < 0) {
            make_edge(i, t, -ff[i], -INF);
        } else {
            make_edge(s, i, ff[i], -INF);
        }
    }
    make_edge(s, 0, INF, 0);
    make_edge(s, n - 1, INF, 0);
    make_edge(0, t, INF, 0);
    make_edge(n - 1, t, INF, 0);
    cout << ans + go * INF + flow(go) << "\n";
    return 0;
}