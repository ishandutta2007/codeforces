#include <bits/stdc++.h>
using namespace std;

const int maxn = 11000;
int n, m, K, t1, t2, s, pre[maxn], pv[maxn];
int u[maxn], v[maxn], l[maxn], r[maxn], pos[maxn], mark[maxn];
long long d[maxn];
vector<tuple<int, int, int>> G[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair
    <long long, int>>> Q;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    scanf("%d %d %d", &t1, &t2, &s);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[v].emplace_back(u, w, 0);
    }
    for (int i = 1; i <= K; i++) {
        scanf("%d %d %d %d", &u[i], &v[i], &l[i], &r[i]);
        pos[i] = G[v[i]].size(), G[v[i]].emplace_back(u[i], l[i], i);
    }
    auto dijkstra = [&]() {
        memset(d, 0x3f, sizeof(d)), Q.emplace(d[s] = 0, s);
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            if (p.first ^ d[p.second]) continue;
            for (auto e : G[p.second]) if (d[get<0>(e)] > p.first + get<1>(e)) {
                Q.emplace(d[get<0>(e)] = p.first + get<1>(e), get<0>(e));
                pre[get<0>(e)] = get<2>(e), pv[get<0>(e)] = p.second;
            }
        }
    };
    dijkstra();
    for (int i = t1; i ^ s; i = pv[i]) {
        mark[pre[i]] = 1;
    }
    for (int i = 1; i <= K; i++) {
        if (!mark[i]) get<1>(G[v[i]][pos[i]]) = r[i];
    }
    dijkstra();
    if (d[t1] <= d[t2]) {
        puts(d[t1] < d[t2] ? "WIN" : "DRAW");
        for (int i = 1; i <= K; i++) {
            printf("%d ", mark[i] ? l[i] : r[i]);
        }
    } else {
        puts("LOSE");
    }
    return 0;
}