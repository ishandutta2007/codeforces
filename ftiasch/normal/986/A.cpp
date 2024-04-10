#include <bits/stdc++.h>

const int N = 100000;
const int K = 100;

int n, m, k, s, ans[N], cnt[N], dist[N][K];
std::vector<int> graph[N];

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &s);
    memset(dist, -1, sizeof(dist));
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < n; ++ i) {
        int c;
        scanf("%d", &c);
        c --;
        dist[i][c] = 0;
        queue.emplace(i, c);
    }
    for (int i = 0; i < m; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while (!queue.empty()) {
        int u = queue.front().first;
        int c = queue.front().second;
        queue.pop();
        cnt[u] ++;
        if (cnt[u] <= s) {
            ans[u] += dist[u][c];
        }
        for (int v : graph[u]) {
            if (dist[v][c] == -1) {
                dist[v][c] = dist[u][c] + 1;
                queue.emplace(v, c);
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
}