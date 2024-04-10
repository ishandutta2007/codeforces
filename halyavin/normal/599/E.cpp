#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
//#include <chrono>

bool buildLcaMap(const std::vector<std::tuple<int, int, int>>& lca,
    std::vector<std::vector<int>>* lcaMap) {
  for (const std::tuple<int, int, int>& query : lca) {
    if (std::get < 0 > (query) == std::get < 1 > (query)) {
      if (std::get < 2 > (query) != std::get < 0 > (query)) {
        return false;
      }
      continue;
    }
    int& v = (*lcaMap)[std::get < 0 > (query)][std::get < 1 > (query)];
    if (v == -1) {
      v = std::get < 2 > (query);
      (*lcaMap)[std::get < 1 > (query)][std::get < 0 > (query)] = std::get < 2
          > (query);
    } else if (v == std::get < 2 > (query)) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

bool isBit(int mask, int i) {
  return mask & (1 << i);
}

void run2(std::istream &in, std::ostream &out) {
  int n, m, q;
  in >> n >> m >> q;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));
  std::vector<std::tuple<int, int, int>> lca(q);
  std::vector<std::vector<int>> lcaMap(n, std::vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    int x, y;
    in >> x >> y;
    x--;
    y--;
    g[x][y] = 1;
    g[y][x] = 1;
  }
  for (int i = 0; i < q; i++) {
    int a, b, c;
    in >> a >> b >> c;
    a--;
    b--;
    c--;
    lca.emplace_back(a, b, c);
  }
//  auto time1 = std::chrono::steady_clock::now();
  if (!buildLcaMap(lca, &lcaMap)) {
    out << "0" << std::endl;
    return;
  }
  if (n == 1) {
    out << "1" << std::endl;
    return;
  }
  std::vector<std::vector<int>> onlyEdge(n, std::vector<int>(1 << n, n));
  for (int root = 0; root < n; root++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (isBit(mask, root))
        continue;
      int res = n;
      for (int i = 0; i < n; i++) {
        if (isBit(mask, i) && g[i][root]) {
          if (res == n) {
            res = i;
          } else {
            res = -1;
          }
        }
      }
      onlyEdge[root][mask] = res;
    }
  }
  std::vector<std::vector<int64_t>> dyn(n, std::vector<int64_t>(1 << n, 0));
  for (int root = 0; root < n; root++) {
    dyn[root][0] = 1;
  }
  std::vector<std::vector<int>> subMasks(1 << n);
  for (int m = 0; m < 1 << n; m++) {
    for (int m1 = 0; m1 <= m; m1++) {
      if ((m1 & m) == m1) {
        subMasks[m].push_back(m1);
      }
    }
  }
  std::vector<std::vector<int>> lcaForbidden(n, std::vector<int>(1 << n, n));
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (isBit(mask, i))
        continue;
      int res = n;
      for (int j = 0; j < n; j++) {
        if (isBit(mask, j) && lcaMap[i][j] != -1) {
          if (res == n) {
            res = lcaMap[i][j];
          } else if (res != lcaMap[i][j]) {
            res = -1;
          }
        }
      }
      lcaForbidden[i][mask] = res;
    }
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int root = 0; root < n; root++) {
      if (isBit(mask, root))
        continue;
      if (lcaForbidden[root][mask] != n && lcaForbidden[root][mask] != root) {
        continue;
      }
      int minBit = mask & (~(mask - 1));
      int64_t res = 0;
      for (int subMaskOther : subMasks[mask - minBit]) {
        int subMask = mask - subMaskOther;
        bool bad = false;
        for (int i = 0; i < n; i++) {
          if (isBit(subMask, i)) {
            int lcaF = lcaForbidden[i][subMaskOther];
            if (lcaF < 0 || (lcaF < n && lcaF != root)) {
              bad = true;
              break;
            }
          }
        }
        for (int i = 0; i < n; i++) {
          if (isBit(subMaskOther, i)) {
            if (onlyEdge[i][subMask] != n) {
              bad = true;
              break;
            }
          }
        }
        if (bad) continue;
        int onlyE = onlyEdge[root][subMask];
        if (onlyE < 0) continue;
        int64_t sub = 0;
        if (onlyE == n) {
          for (int i = 0; i < n; i++) {
            if (isBit(subMask, i)) {
              sub += dyn[i][subMask - (1 << i)];
            }
          }
        } else {
          sub = dyn[onlyE][subMask - (1 << onlyE)];
        }
        res += sub * dyn[root][subMaskOther];
      }
      dyn[root][mask] = res;
    }
  }
  int64_t answer = dyn[0][(1 << n) - 2];
  out << answer << std::endl;
//  auto diff = std::chrono::steady_clock::now() - time1;
//  std::cout << std::chrono::duration_cast < std::chrono::milliseconds
//      > (diff).count() << " msec" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run2(std::cin, std::cout);
  return 0;
}