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

void remove_element(std::vector<int>& v, int elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  if (it != v.end()) {
    v.erase(it);
  }
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<int> rs(n);
  for (int i = 0; i < n; i++) {
    in >> rs[i];
    rs[i] ^= 1;
  }
  std::vector<std::set<int>> eqs(m);
  std::vector<std::vector<int>> reqs(n);
  for (int i = 0; i < m; i++) {
    int num;
    in >> num;
    for (int j = 0; j < num; j++) {
      int v;
      in >> v;
      v--;
      eqs[i].insert(v);
      reqs[v].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (reqs[i].empty()) {
      if (rs[i] != 0) {
        out << "NO" << std::endl;
        return;
      } else {
        continue;
      }
    }
    if (reqs[i].size() == 1) {
      int eq = reqs[i][0];
      if (rs[i] != 0) {
        for (int t : eqs[eq]) {
          rs[t] ^= 1;
        }
      }
      for (int t : eqs[eq]) {
        remove_element(reqs[t], eq);
      }
      continue;
    }
    int eq1 = reqs[i][0];
    int eq2 = reqs[i][1];
    if (eqs[eq1].size() > eqs[eq2].size()) {
      std::swap(eq1, eq2);
    }
    if (rs[i] != 0) {
      for (int t : eqs[eq1]) {
        rs[t] ^= 1;
      }
    }
    for (int t : eqs[eq1]) {
      remove_element(reqs[t], eq1);
      auto it = eqs[eq2].find(t);
      if (it != eqs[eq2].end()) {
        remove_element(reqs[t], eq2);
        eqs[eq2].erase(it);
      } else {
        eqs[eq2].insert(t);
        reqs[t].push_back(eq2);
      }
    }
  }
  out << "YES" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}