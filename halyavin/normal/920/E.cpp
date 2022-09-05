#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <set>

struct Solution {
    int n;
    std::vector<std::vector<int>> antiGraph;
    std::vector<int> ans;
    std::set<int> nonVisited;

    int dfs(int v) {
        int res = 1;
        nonVisited.erase(v);
        std::vector<int>& antiEdges = antiGraph[v];
        int antiI = 0;
        for (int cur = 0; cur < n; ) {
            auto it = nonVisited.lower_bound(cur);
            if (it == nonVisited.end()) break;
            cur = *it;
            while (antiI < antiEdges.size() && antiEdges[antiI] < cur) antiI++;
            if (antiI < antiEdges.size() && antiEdges[antiI] == cur) {
                cur++;
            } else {
                res += dfs(cur);
            }
        }
        return res;
    }

    void run(std::istream& in, std::ostream& out) {
        int m;
        in >> n >> m;
        antiGraph.assign(n, std::vector<int>());
        for (int i = 0; i < m; i++) {
            int from, to;
            in >> from >> to;
            from--;
            to--;
            antiGraph[from].push_back(to);
            antiGraph[to].push_back(from);
        }
        for (int i = 0; i < n; i++) {
            std::sort(antiGraph[i].begin(), antiGraph[i].end());
        }
        ans.clear();
        nonVisited.clear();
        for (int i = 0; i < n; i++) {
            nonVisited.insert(i);
        }
        for (int i = 0; i < n;) {
            auto it = nonVisited.lower_bound(i);
            if (it == nonVisited.end()) break;
            ans.push_back(dfs(*it));
        }
        std::sort(ans.begin(), ans.end());
        out << ans.size() << "\n";
        for (int v : ans) {
            out << v << " ";
        }
        out << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}