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

struct Solution {
  int n;
  std::vector<std::vector<int>> graph;
  std::vector<std::vector<int>> matrix;
  int counter;
  std::vector<int> dirtyFlags;
  std::vector<double> maxProbs;

  double checkFirst(int a) {
    double res = 0;
    for (int dist = 0; dist < n; dist++) {
      std::vector<int> group;
      for (int i = 0; i < n; i++) {
        if (matrix[a][i] == dist) {
          group.push_back(i);
        }
      }
      if (group.size() == 0) continue;
      double caseProb = group.size() / (double) n;
      double c = 1.0 / group.size();
      double ans = c;
      std::vector<double> t(n);
      for (int v : group) {
        for (int nv : graph[v]) {
          t[nv] += c / graph[v].size();
        }
      }
      std::vector<int> groupT;
      std::vector<double> groupTD;
      for (int i = 0; i < n; i++) {
        if (t[i] > 1e-20) {
          groupT.push_back(i);
          groupTD.push_back(t[i]);
        }
      }
      for (int b = 0; b < n; b++) {
        counter++;
        double cur = 0;
        for (size_t i = 0; i < groupT.size(); i++) {
          int v = groupT[i];
          double tv = groupTD[i];
          int d = matrix[b][v];
          if (dirtyFlags[d] == counter) {
            if (tv > maxProbs[d]) {
              cur += tv - maxProbs[d];
              maxProbs[d] = tv;
            }
          } else {
            dirtyFlags[d] = counter;
            maxProbs[d] = tv;
            cur += tv;
          }
        }
        ans = std::max(ans, cur);
      }
      res += caseProb * ans;
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    int m;
    in >> n >> m;
    graph.clear();
    graph.resize(n);
    matrix.clear();
    matrix.resize(n, std::vector<int>(n, 1000000));
    for (int i = 0; i < n; i++) {
      matrix[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      in >> a >> b;
      a--;b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
      matrix[a][b] = 1;
      matrix[b][a] = 1;
    }
    for(int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          matrix[j][k] = std::min(matrix[j][k], matrix[j][i] + matrix[i][k]);
        }
      }
    }

    counter = 0;
    dirtyFlags.resize(n);
    maxProbs.resize(n);

    double ans = 0;
    for (int a = 0; a < n; a++) {
      ans = std::max(ans, checkFirst(a));
    }
    out.precision(12);
    out << ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}