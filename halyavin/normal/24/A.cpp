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

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::vector<std::pair<int, int>>> graph(n);
  for (int i = 0; i < n; i++) {
    int from, to, cost;
    in >> from >> to >> cost;
    from--;to--;
    graph[from].emplace_back(to, 0);
    graph[to].emplace_back(from, cost);
  }
  int v = graph[0][0].first;
  int cost1 = graph[0][0].second;
  int prevv = 0;
  while (v != 0) {
    int ind = 0;
    if (graph[v][0].first == prevv) {
      ind++;
    }
    cost1 += graph[v][ind].second;
    int nextv = graph[v][ind].first;
    prevv = v;
    v = nextv;
  }
  v = graph[0][1].first;
  int cost2 = graph[0][1].second;
  prevv = 0;
  while (v != 0) {
    int ind = 0;
    if (graph[v][0].first == prevv) {
      ind++;
    }
    cost2 += graph[v][ind].second;
    int nextv = graph[v][ind].first;
    prevv = v;
    v = nextv;
  }
  out << std::min(cost1, cost2) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}