#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Solution {
  int n;
  std::vector<std::vector<int>> graph;
  std::vector<int> weights;
  std::vector<int64_t> sumSubTree;
  std::vector<int64_t> maxSumSubTree;
  static const int64_t inf = 1LL << 60;
  int64_t ans;
  void dfs(int vertex, int prevVertex) {
    int64_t sum = weights[vertex];
    int64_t maxSum = -inf;
    int64_t maxSum2 = -inf;
    for (int nextVertex : graph[vertex]) {
      if (nextVertex == prevVertex) {
        continue;
      }
      dfs(nextVertex, vertex);
      sum += sumSubTree[nextVertex];
      int64_t childMax = maxSumSubTree[nextVertex];
      if  (childMax >= maxSum) {
        maxSum2 = maxSum;
        maxSum = childMax;
      } else if (childMax >= maxSum2) {
        maxSum2 = childMax;
      }
    }
    if (maxSum2 != -inf && maxSum != -inf) {
      ans = std::max(ans, maxSum + maxSum2);
    }
    maxSum = std::max(maxSum, sum);
    sumSubTree[vertex] = sum;
    maxSumSubTree[vertex] = maxSum;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
      in >> weights[i];
    }
    graph.clear();
    graph.resize(n);
    for (int i = 0; i < n- 1; i++) {
      int from, to;
      in >> from >> to;
      from--;to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    sumSubTree.resize(n);
    maxSumSubTree.resize(n);
    ans = -inf;
    dfs(0, -1);
    if (ans == -inf) {
      out << "Impossible" << std::endl;
    } else {
      out << ans << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}