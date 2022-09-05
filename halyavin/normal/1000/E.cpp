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

class TarjanBridgeFlags {
    using Graph = std::vector<std::vector<int>>;
    using ComponentNums = std::vector<int>;
    const Graph& graph;
    ComponentNums components;
    std::vector<int> idx;
    std::vector<int> stack;
    int component;

    TarjanBridgeFlags(const Graph& graph) :
        graph(graph),
        components(graph.size(), -1),
        idx(graph.size(), -1),
        stack(),
        component(0) { }

    int dfs(int v, int prev) {
        int curIdx = stack.size();
        stack.push_back(v);
        int res = curIdx;
        idx[v] = curIdx;
        for (int nv : graph[v]) {
            if (nv == prev) {
                continue;
            }
            if (idx[nv] < 0) {
                res = std::min(res, dfs(nv, v));
            } else {
                res = std::min(res, idx[nv]);
            }
        }
        if (res == curIdx) {
            for (size_t i = curIdx; i < stack.size(); i++) {
                components[stack[i]] = component;
                idx[stack[i]] = graph.size();
            }
            stack.resize(curIdx);
            component++;
        }
        return res;
    }

  public:
    static ComponentNums getComponents(const Graph& graph) {
        TarjanBridgeFlags t(graph);
        for (size_t i = 0; i < graph.size(); i++) {
            if (t.idx[i] < 0) {
                t.dfs(i, graph.size());
            }
        }
        return std::move(t.components);
    }
};

struct Solution {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<int> colors;
    int ncolors;
    std::vector<std::vector<int>> compressedGraph;

    std::pair<int, int> dfs(int v, int prev) {
        std::pair<int, int> result = {1, 1};
        int best = 0;
        int best2 = 0;
        for (int nv : compressedGraph[v]) {
            if (nv == prev) continue;
            std::pair<int, int> res = dfs(nv, v);
            result.first = std::max(result.first, res.first + 1);
            result.second = std::max(result.second, res.second);
            if (res.first >= best) {
                best2 = best;
                best = res.first;
            } else if (res.first > best2) {
                best2 = res.first;
            }
        }
        result.second = std::max(result.second, best + best2 + 1);
        return result;
    };
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        graph.assign(n, std::vector<int>());
        int m;
        in >> m;
        for (int i = 0; i < m; i++) {
            int x, y;
            in >> x >> y;
            x--;y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        colors = TarjanBridgeFlags::getComponents(graph);
        ncolors = (*std::max_element(colors.begin(), colors.end())) + 1;
        compressedGraph.assign(ncolors, std::vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                if (colors[i] != colors[j]) {
                    compressedGraph[colors[i]].push_back(colors[j]);
                }
            }
        }
        int result = dfs(0, -1).second;
        out << result - 1 << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}