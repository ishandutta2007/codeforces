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
#include <queue>
#include <array>

struct Edge {
    int from;
    int to;
    int capacity;
    int flow;
    int cost;
};

template<class E = Edge>
struct MinCostFlow2 {
    std::vector<std::vector<E*>>* pGraph = nullptr;
    int vFrom = 0;
    int vTo = 0;
    int n = 0;
    int64_t totalCost = 0;

    std::vector<E*> prev;
    std::vector<int64_t> potential;
    std::vector<int64_t> dist;

    static int capacity(int v, E* edge) {
        if (edge->from == v) {
            return edge->capacity - edge->flow;
        } else {
            return edge->flow;
        }
    }

    static decltype(std::declval<E>().cost) cost(int v, E* edge) {
        if (edge->from == v) {
            return edge->cost;
        } else {
            return -edge->cost;
        }
    }

    static void addCapacity(int v, E* edge, int flow) {
        if (edge->from == v) {
            edge->flow += flow;
        } else {
            edge->flow -= flow;
        }
    }

    void updateDist2() {
        dist.assign(n, int64_t(1) << 61);
        std::vector<bool> found(n);
        std::queue<int> queue;
        dist[vFrom] = 0;
        queue.push(vFrom);
        found[vFrom] = true;
        while (!queue.empty()) {
            int v = queue.front();
            queue.pop();
            if (v == vTo) {
                continue;
            }
            for (auto& edge : (*pGraph)[v]) {
                if (edge->from != v) {
                    continue;
                }
                int nv = edge->to;
                int64_t newDist = dist[v] + edge->cost;
                if (dist[nv] > newDist) {
                    dist[nv] = newDist;
                    if (!found[nv]) {
                        queue.push(nv);
                        found[nv] = true;
                    }
                }
            }
            found[v] = false;
        }
    }

    bool updateDist() {
        std::swap(potential, dist);
        prev.assign(n, nullptr);
        dist.assign(n, int64_t(1) << 61);
        dist[vFrom] = 0;
        std::priority_queue<std::pair<int64_t, int>> queue;
        queue.emplace(0, vFrom);
        while (!queue.empty()) {
            int64_t value = -queue.top().first;
            int v = queue.top().second;
            queue.pop();
            if (value + potential[v] != dist[v]) {
                continue;
            }
            value = dist[v];
            for (auto& edge : (*pGraph)[v]) {
                if (capacity(v, edge) == 0) {
                    continue;
                }
                int nv = edge->from ^ edge->to ^ v;
                int64_t newDist = value + cost(v, edge);
                if (dist[nv] > newDist) {
                    prev[nv] = edge;
                    dist[nv] = newDist;
                    queue.emplace(potential[nv] - newDist, nv);
                }
            }
        }
        return prev[vTo] != nullptr;
    }

    int dfs() {
        int node = prev[vTo]->to ^ prev[vTo]->from ^ vTo;
        int flow = capacity(node, prev[vTo]);
        while (node != vFrom) {
            int prevNode = prev[node]->to ^ prev[node]->from ^ node;
            flow = std::min(flow, capacity(prevNode, prev[node]));
            node = prevNode;
        }
        node = vTo;
        while (node != vFrom) {
            int prevNode = prev[node]->to ^ prev[node]->from ^ node;
            addCapacity(prevNode, prev[node], flow);
            node = prevNode;
        }
        return flow;
    }

    int64_t solve(std::vector<std::vector<E*>>& graph, int from, int to, bool clear = true) {
        totalCost = 0;
        pGraph = &graph;
        vFrom = from;
        vTo = to;
        if (clear) {
            for (auto& vArray : graph) {
                for (auto& edge : vArray) {
                    edge->flow = 0;
                }
            }
        }
        n = graph.size();
        updateDist2();
        while (updateDist()) {
            int flow = dfs();
            totalCost += dist[vTo] * flow;
        }

        return totalCost;
    }
};

void clearGraph(std::vector<std::vector<Edge*>>& graph) {
    for (size_t v = 0; v < graph.size(); v++) {
        auto& edges = graph[v];
        auto it = std::partition(edges.begin(), edges.end(), [v](Edge* e) { return e->from == v; });
        edges.erase(it, edges.end());
    }
    for (auto& v : graph) {
        for (Edge* edge : v) {
            delete edge;
        }
    }
    graph.clear();
}

struct Solution {
    int n;
    std::string s;
    std::vector<int> bs;
    void run(std::istream& in, std::ostream& out) {
        in >> n;
        in >> s;
        bs.resize(n);
        for (int i = 0; i < n; i++) {
            in >> bs[i];
        }
        std::vector<std::vector<Edge*>> graph(1 + 26 + n / 2 + 1);
        int source = 0;
        int letterStart = source + 1;
        int pairStart = letterStart + 26;
        int target = pairStart + n / 2;
        std::array<int, 26> stat = {};
        for (char c : s) {
            stat[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            Edge* e = new Edge;
            e->from = source;
            e->to = letterStart + i;
            e->capacity = stat[i];
            e->cost = 0;
            e->flow = 0;
            graph[e->from].push_back(e);
            graph[e->to].push_back(e);
        }
        for (int i = 0; i < n/2; i++) {
            int l1 = s[i] - 'a';
            int l2 = s[n - i - 1] - 'a';
            int c1 = bs[i];
            int c2 = bs[n - i - 1];
            for (int j = 0; j < 26; j++) {
                Edge* e = new Edge;
                e->from = letterStart + j;
                e->to = pairStart + i;
                e->capacity = 1;
                e->cost = 0;
                if (j == l1) {
                    e->cost = -c1;
                }
                if (j == l2) {
                    e->cost = std::min(e->cost, -c2);
                }
                e->flow = 0;
                graph[e->from].push_back(e);
                graph[e->to].push_back(e);
            }
            Edge* e = new Edge;
            e->from = pairStart + i;
            e->to = target;
            e->capacity = 2;
            e->cost = 0;
            e->flow = 0;
            graph[e->from].push_back(e);
            graph[e->to].push_back(e);
        }
        MinCostFlow2<Edge> algorithm;
        int64_t cost = algorithm.solve(graph, source, target);
        clearGraph(graph);
        out << -cost << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}