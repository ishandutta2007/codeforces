#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>

std::vector<std::vector<int>> apsp(const std::vector<std::vector<int>>& graph)
{
    int n = graph.size();
    std::vector<std::vector<int>> distance(n, std::vector<int>(n, -1));
    for (int s = 0; s < n; ++ s) {
        auto& d = distance[s];
        std::queue<int> queue;
        queue.push(s);
        d[s] = 0;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (int v : graph[u]) {
                if (!~d[v]) {
                    d[v] = d[u] + 1;
                    queue.push(v);
                }
            }
        }
    }
    return distance;
}

std::vector<std::vector<int>> sorted(const std::vector<std::vector<int>>& distance)
{
    int n = distance.size();
    std::vector<std::vector<int>> result(n);
    for (int i = 0; i < n; ++ i) {
        std::vector<std::pair<int, int>> v;
        for (int j = 0; j < n; ++ j) {
            if (i != j && ~distance[i][j]) {
                v.emplace_back(distance[i][j], j);
            }
        }
        std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
        if ((int)v.size() >= 3) {
            v.resize(3);
        }
        for (auto&& iterator : v) {
            result[i].push_back(iterator.second);
        }
    }
    return result;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> graph(n), rgraph(n);
    for (int i = 0; i < m; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        graph.at(a).push_back(b);
        rgraph.at(b).push_back(a);
    }
    auto d = apsp(graph);
    auto rd = apsp(rgraph);
    auto sd = sorted(d);
    auto srd = sorted(rd);
    int best = 0;
    int aa, bb, cc, dd;
    for (int a = 0; a < n; ++ a) {
        for (int b = 0; b < n; ++ b) {
            if (a != b && ~d[a][b]) {
                for (int x : srd[a]) {
                    for (int y : sd[b]) {
                        if (x != y && x != b && y != a) {
                            int l = d[x][a] + d[a][b] + d[b][y];
                            if (l > best) {
                                best = l;
                                aa = x;
                                bb = a;
                                cc = b;
                                dd = y;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n", 1 + aa, 1 + bb, 1 + cc, 1 + dd);
}