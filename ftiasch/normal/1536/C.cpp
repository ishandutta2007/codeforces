#include <bits/stdc++.h>

namespace {

struct Frac {
  int p, q;
};

bool operator<(const Frac &a, const Frac &b) {
  return 1LL * a.p * b.q < 1LL * b.p * a.q;
}

} // namespace

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> buffer(n + 1);
    scanf("%s", buffer.data());
    std::map<Frac, int> opt;
    for (int i = 1, sum = 0; i <= n; ++i) {
      sum += buffer[i - 1] == 'K';
      auto r = Frac{sum, i};
      auto it = opt.find(r);
      int dp = 1;
      if (it != opt.end()) {
        dp = it->second + 1;
      }
      opt[r] = dp;
      printf("%d%c", dp, " \n"[i == n]);
    }
  }
}