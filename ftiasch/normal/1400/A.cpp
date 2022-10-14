#line 1 "sol.cpp"
#include <bits/stdc++.h>

using u64 = uint64_t;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> s(n << 1);
    scanf("%s", s.data());
    u64 mask = (1ULL << n) - 1;
    u64 cur = 0;
    std::set<u64> ban;
    for (int i = 0; i < 2 * n - 1; ++i) {
      cur = (cur << 1 | (s[i] - '0')) & mask;
      if (i >= n - 1) {
        ban.insert((~cur) & mask);
      }
    }
    u64 res = 0;
    while (ban.count(res)) {
        res ++;
    }
    for (int i = n; i --; ) {
        putchar("01"[res >> i & 1]);
    }
    puts("");
  }
}