#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 100000;

int n, color[N];
std::vector <int> graph[N];

long long bipartite()
{
    long long result = 0;
    memset(color, -1, sizeof(color));
    for (int s = 0; s < n; ++ s) {
        if (color[s] == -1) {
            color[s] = 0;
            std::queue <int> queue;
            queue.push(s);
            int count[2] = {0, 0};
            while (!queue.empty()) {
                int u = queue.front();
                count[color[u]] ++;
                queue.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        queue.push(v);
                    }
                    if (color[u] == color[v]) {
                        return -1;
                    }
                }
            }
            for (int i = 0; i < 2; ++ i) {
                result += (long long)count[i] * (count[i] - 1) / 2;
            }
        }
    }
    return result;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long cnt = bipartite();
    if (cnt == -1) {
        puts("0 1");
        return 0;
    }
    bool path2 = 0;
    for (int i = 0; i < n; ++ i) {
        path2 |= graph[i].size() >= 2;
    }
    if (path2 > 0) {
        std::cout << 1 << " " << cnt << std::endl;
        return 0;
    }
    if (m > 0) {
        std::cout << 2 << " " << (long long)m * (n - 2) << std::endl;
        return 0;
    }
    std::cout << 3 << " " << (long long)n * (n - 1) * (n - 2) / 6 << std::endl;
    return 0;
}