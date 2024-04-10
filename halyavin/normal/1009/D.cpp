#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

template<class T>
T gcd(T x, T y) {
  while (y != T()) {
    T t = y;
    y = x % y;
    x = t;
  }
  return x;
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<std::pair<int, int>> graph;
  if (m < n - 1) {
    out << "Impossible\n";
    return;
  }
  for (int i = 1; i + 1 <= n; i++) {
    graph.emplace_back(i, i + 1);
  }
  m -= n - 1;
  for (int i = 1; i <= n && m > 0; i++) {
    for (int j = i + 2; j <= n && m > 0; j++) {
      if (gcd(i, j) == 1) {
        graph.emplace_back(i, j);
        m--;
      }
    }
  }
  if (m != 0) {
    out << "Impossible\n";
    return;
  }
  out << "Possible\n";
  for (size_t i = 0; i < graph.size(); i++) {
    out << graph[i].first << " " << graph[i].second << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}