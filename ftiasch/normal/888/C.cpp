#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::vector<char> s(100'001);
  scanf("%s", s.data());
  int n = strlen(s.data());
  std::array<std::vector<int>, 26> indices;
  for (int i = 0; i < n; ++i) {
    indices[s[i] - 'a'].push_back(i);
  }
  int result = n;
  for (auto &indices : indices) {
    if (!indices.empty()) {
      int dom = std::max(indices[0] + 1, n - indices.back());
      for (int i = 1; i < indices.size(); ++i) {
        dom = std::max(dom, indices[i] - indices[i - 1]);
      }
      result = std::min(result, dom);
    }
  }
  printf("%d\n", result);
}