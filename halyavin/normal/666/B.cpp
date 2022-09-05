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
#include <array>

const int INF = 100000;

std::vector<std::vector<int>> getDist(std::vector<std::vector<int>>& graph) {
  int n = graph.size();
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
  std::vector<int> queue(n);
  for (int i = 0; i < n; i++) {
    int bque = 0;
    int eque = 1;
    queue[0] = i;
    dist[i][i] = 0;
    while (eque > bque) {
      int v = queue[bque];
      bque++;
      int d = dist[i][v];
      for (int nv : graph[v]) {
        if (dist[i][nv] == INF) {
          dist[i][nv] = d + 1;
          queue[eque] = nv;
          eque++;
        }
      }
    }
  }
  return dist;
}

struct dyn1Max {
  int max;
  int optD;
  dyn1Max() : max(-INF), optD(0) {
  }
};

using dyn1 = std::array<dyn1Max, 3>;

struct dyn2Max {
  int max;
  int optC;
  int optD;
  dyn2Max() : max(-INF), optC(0), optD(0) {
  }
};

using dyn2 = std::array<dyn2Max, 3>;


void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int u;
    int v;
    in >> u >> v;
    u--;
    v--;
    if (u != v) {
      graph[u].push_back(v);
    }
  }
  for (int i = 0; i < n; i++) {
    std::vector<int>& next = graph[i];
    std::sort(next.begin(), next.end());
    auto it = std::unique(next.begin(), next.end());
    next.erase(it, next.end());
  }
  std::vector<std::vector<int>> dist = getDist(graph);
  std::vector<dyn1> dynC(n);
  for (int c = 0; c < n; c++) {
    dyn1& dyn = dynC[c];
    for (int d = 0; d < n; d++) {
      if (d == c || dist[c][d] == INF) continue;
      for (int k = 0; k < 3; k++) {
        if (dist[c][d] >= dyn[k].max) {
          for (int l = 2; l > k; l--) {
            dyn[l] = dyn[l - 1];
          }
          dyn[k].max = dist[c][d];
          dyn[k].optD = d;
          break;
        }
      }
    }
  }
  std::vector<dyn2> dynB(n);
  for (int b = 0; b < n; b++) {
    for (int c = 0; c < n; c++) {
      if (c == b || dist[b][c] == INF) continue;
      if (dynC[c][0].max == -INF) continue;
      int cur = dist[b][c];
      int d;
      if (dynC[c][0].optD == b) {
        if (dynC[c][1].max == -INF) continue;
        cur += dynC[c][1].max;
        d = dynC[c][1].optD;
      } else {
        cur += dynC[c][0].max;
        d = dynC[c][0].optD;
      }
      if (cur > dynB[b][0].max) {
        dynB[b][0].max = cur;
        dynB[b][0].optC = c;
        dynB[b][0].optD = d;
      }
    }
    if (dynB[b][0].max == -INF) continue;
    int opt[2];
    opt[0] = dynB[b][0].optC;
    opt[1] = dynB[b][0].optD;
    for (int k = 1; k < 3; k++) {
      int avoid = opt[k - 1];
      for (int c = 0; c < n; c++) {
        if (c == b || c == avoid || dist[b][c] == INF) continue;
        int cur = dist[b][c];
        int d;
        for (int t = 0; t < 3; t++) {
          if (dynC[c][t].max == -INF) {
            cur = -INF;
            break;
          }
          d = dynC[c][t].optD;
          if (d == b || d == avoid) continue;
          cur += dynC[c][t].max;
          break;
        }
        if (cur == -INF) continue;
        if (cur > dynB[b][k].max) {
          dynB[b][k].max = cur;
          dynB[b][k].optC = c;
          dynB[b][k].optD = d;
        }
      }
    }
    if (dynB[b][1].max < dynB[b][2].max) {
      std::swap(dynB[b][1], dynB[b][2]);
    }
  }
  int opt = -INF;
  int optA = 0;
  int optB = 0;
  int optC = 0;
  int optD = 0;
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      if (b == a || dist[a][b] == INF) continue;
      int cur = dist[a][b];
      int c, d;
      for (int t = 0; t < 3; t++) {
        if (dynB[b][t].max == -INF) {
          cur = -INF;
          break;
        }
        if (dynB[b][t].optC == a || dynB[b][t].optD == a) continue;
        cur += dynB[b][t].max;
        c = dynB[b][t].optC;
        d = dynB[b][t].optD;
        break;
      }
      if (cur == -INF) continue;
      if (cur > opt) {
        opt = cur;
        optA = a;
        optB = b;
        optC = c;
        optD = d;
      }
    }
  }
  out << (optA + 1) << " " << (optB + 1) << " " << (optC + 1) << " " << (optD + 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}