#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Solution {
    int n;
    std::vector<std::vector<std::pair<int, int>>> graph;
    std::vector<int> prev;
    std::vector<int> prevLength;
    std::vector<bool> flag;
    std::vector<int> dist;
    std::vector<std::pair<int, int>> path;
    int64_t length;
    int shortcut;

    void dfs(int v, int p) {
        for (const auto& edge : graph[v]) {
            if (edge.first != p) {
                prev[edge.first] = v;
                prevLength[edge.first] = edge.second;
                dfs(edge.first, v);
            }
        }
    }

    bool isBadV(int v) {
        int sum = 0;
        for (const auto& edge : graph[v]) {
            if (flag[edge.first]) continue;
            if (graph[edge.first].size() > 1) {
                return true;
            }
            dist[v] = edge.second;
            sum++;
        }
        return sum >= 2;
    }

    void run(std::istream& in, std::ostream& out) {
        int m;
        in >> n >> m;
        graph.assign(n, std::vector<std::pair<int, int>>());
        for (int i = 0; i < n- 1; i++) {
            int from, to, length;
            in >> from >> to >> length;
            from--;to--;
            graph[from].emplace_back(to, length);
            graph[to].emplace_back(from, length);
        }
        prev.assign(n, 0);
        prevLength.assign(n, 0);
        dfs(0, -1);
        flag.assign(n, false);
        path.clear();
        int cur = n - 1;
        while (cur != 0) {
            flag[cur] = true;
            path.emplace_back(cur, prevLength[cur]);
            cur = prev[cur];
        }
        path.emplace_back(0, 0);
        flag[0] = true;
        std::reverse(path.begin(), path.end());
        length = 0;
        for (const auto& edge : path) {
            length += edge.second;
        }
        dist.assign(n, -1);
        bool bad = false;
        for (const auto& edge : path) {
            if (isBadV(edge.first)) {
                bad = true;
            }
        }
        if (bad) {
            shortcut = 0;
        } else {
            shortcut = 2000000000;
            for (size_t i = 1; i + 1 < path.size(); i++) {
                shortcut = std::min(shortcut, path[i].second + path[i + 1].second);
            }
            for (int i = 0; i < path.size(); i++) {
                int d = dist[path[i].first];
                if (d < 0) continue;
                if (i > 0) {
                    shortcut = std::min(shortcut, path[i].second-d);
                }
                if (i + 1 < path.size()) {
                    shortcut = std::min(shortcut, path[i + 1].second - d);
                }
                if (i + 1 < path.size()) {
                    int d1 = dist[path[i + 1].first];
                    if (d1 >= 0) {
                        shortcut = std::min(shortcut, path[i + 1].second - d - d1);
                    }
                }
            }
        }
        if (shortcut < 0) shortcut = 0;
        for (int i = 0; i < m; i++) {
            int x;
            in >> x;
            if (x >= shortcut) {
                out << length << "\n";
            } else {
                out << length - shortcut + x << "\n";
            }
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}