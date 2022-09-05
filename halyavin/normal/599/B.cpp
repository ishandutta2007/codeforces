#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<int> fs(n);
  for (int i = 0; i < n; i++) {
    in >> fs[i];
    fs[i]--;
  }
  std::vector<int> bs(m);
  for (int i = 0; i < m; i++) {
    in >> bs[i];
    bs[i]--;
  }
  std::vector<int> count(n);
  std::vector<int> inv(n);
  for (int i = 0; i < n; i++) {
    count[fs[i]]++;
    inv[fs[i]] = i;
  }
  std::vector<int> as;
  bool ambiguity = false;
  for (int i = 0; i < m; i++) {
    if (count[bs[i]] == 0) {
      out << "Impossible" << std::endl;
      return;
    }
    if (count[bs[i]] > 1) {
      ambiguity = true;
      continue;
    }
    as.push_back(inv[bs[i]]);
  }
  if (ambiguity) {
    out << "Ambiguity" << std::endl;
    return;
  }
  out << "Possible" << std::endl;
  for (int i = 0; i < m; i++) {
    out << (as[i] + 1) << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}