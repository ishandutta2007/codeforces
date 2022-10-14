#include <bits/stdc++.h>

void gen(int k, std::vector<int> &s, int i) {
  if (i + 1 < k) {
    for (int j = k - 1; j > i + 1; --j) {
      s.push_back(j);
      s.push_back(i);
    }
    s.push_back(i + 1);
    gen(k, s, i + 1);
    s.push_back(i);
  }
  s.push_back(i);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> p{};
  gen(k, p, 0);
  putchar('a');
  for (int i = 0; i < n - 1; ++i) {
    putchar('a' + p[i % p.size()]);
  }
  puts("");
  //   for (int i : p) {
  //     putchar('a' + i);
  //   }
  //   puts("");
  //   int len = p.size();
  //   for (int i = 1; i < len; ++i) {
  //     for (int j = i + 1; j < len; ++j) {
  //       if (p[i - 1] == p[j - 1] && p[i] == p[j]) {
  //         std::cerr << i << " " << j << std::endl;
  //       }
  //     }
  //   }
}