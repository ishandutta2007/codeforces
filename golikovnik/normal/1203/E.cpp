#include <bits/stdc++.h>

int main() {
  unsigned n;
  std::cin >> n;
  std::vector<unsigned> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());
  std::set<unsigned> answer;
  for (auto x : a) {
    if (x != 1 && answer.insert(x - 1).second) {
      continue;
    }
    if (answer.insert(x).second) {
      continue;
    }
    answer.insert(x + 1);
  }
  std::cout << answer.size() << '\n';
  return 0;
}