#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::array<int, 6> p{4, 8, 15, 16, 23, 42};
  std::map<std::array<int, 4>, std::array<int, 6>> remap;
  do {
    std::array<int, 4> hash;
    for (int i = 0; i < 4; ++i) {
      hash[i] = p[0] * p[i + 1];
    }
    remap[hash] = p;
  } while (std::next_permutation(p.begin(), p.end()));
  std::array<int, 4> hash;
  for (int i = 0; i < 4; ++i) {
    printf("? 1 %d\n", i + 2);
    fflush(stdout);
    scanf("%d", &hash[i]);
  }
  p = remap[hash];
  printf("!");
  for (int i = 0; i < 6; ++ i) {
      printf(" %d", p[i]);
  }
  puts("");
  fflush(stdout);
}