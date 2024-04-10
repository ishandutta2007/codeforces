#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int V = 600;
const int INF = 1000000000;

int a[N], dist[N][V];
std::vector<std::pair<int, int>> graph[V];
vector< tuple<int , int , int> > edge;
vector< int> E[V];
int v, e, n, k;

bool vis[N];
int match[N];

bool find(int x) {
    for (auto &y : E[x]) {
        if (!vis[y]) {
            vis[y] = 1;
            if (!~match[y] || find(match[y])) {
                match[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

bool check(int val) {
    for (int i = 0 ; i < v ; ++ i) {
        E[i].clear();
    }
    for (auto it : edge) {
        if (get<0>(it) > val) break;
        E[get<1>(it)].emplace_back(get<2>(it));
    }
    memset(match , -1 , sizeof(match));
    int res = 0;
    for (int i = 0 ; i < v ; ++ i) {
        memset(vis , 0 , sizeof(vis));
        if ((res += find(i)) >= k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d%d%d", &v, &e, &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        a[i] --;
    }
    for (int i = 0; i < e; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --;
        b --;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < v; ++ j) {
            dist[i][j] = INF;
        }
        dist[i][a[i]] = 0;
        queue.emplace(0, std::make_pair(i, a[i]));
    }
    while (!queue.empty()) {
        auto top = queue.top();
        queue.pop();
        int s = top.second.first;
        int u = top.second.second;
        if (-top.first > 1731311) break;
        if (-top.first == dist[s][u]) {
            edge.emplace_back(-top.first, u , s);
            for (auto e : graph[u]) {
                int v = e.first;
                if (dist[s][u] + e.second < dist[s][v]) {
                    dist[s][v] = dist[s][u] + e.second;
                    queue.emplace(-dist[s][v], std::make_pair(s, v));
                }
            }
        }
    }
    int l = 0 , r = 1731312;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (r > 1731311) {
        puts("-1");
    } else {
        printf("%d\n" , r);
    }
}