#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Edge {
    int to;
    int id;
    int sign;
    Edge(int to, int id, int sign) : to(to), id(id), sign(sign) {}
};

struct Solution {
    int n;
    std::vector<int> ss;
    std::vector<bool> visited;
    std::vector<std::vector<Edge>> graph;
    std::vector<int> flow;

    int rec(int v) {
        visited[v] = true;
        int res = ss[v];
        for (const Edge& edge : graph[v]) {
            if (visited[edge.to]) continue;
            int sum = rec(edge.to);
            res += sum;
            flow[edge.id] += edge.sign * sum;
        }
        return res;
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        ss.resize(n);
        for (int i = 0; i < n; i++) {
            in >> ss[i];
        }
        visited.assign(n, false);
        int m;
        in >> m;
        flow.assign(m, 0);
        graph.assign(n, std::vector<Edge>());
        for (int i = 0; i < m; i++) {
            int x, y;
            in >> x >> y;
            x--;y--;
            graph[x].emplace_back(y, i, 1);
            graph[y].emplace_back(x, i, -1);
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            int flow = rec(i);
            if (flow != 0) {
                out << "Impossible\n";
                return;
            }
        }
        out << "Possible\n";
        for (int i = 0; i < m; i++) {
            out << flow[i] << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}