#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 16;
const Long INF = 1'000'000'000'000'000'001;

std::string fib[N];

int count(const std::string &s, const std::string &p) {
  int result = 0;
  for (int i = 0; i + p.size() <= s.size(); ++i) {
    result += s.substr(i, p.size()) == p;
  }
  return result;
}

Long count(int n, const std::string &s) {
  if (n < N) {
    return count(fib[n], s);
  }
  int occ_12 = count(fib[12], s);
  int occ_13 = count(fib[13], s);
  int occ_14 = count(fib[14], s);
  int occ_15 = count(fib[15], s);
  int cross_odd = occ_14 - occ_12 - occ_13;
  int cross_even = occ_15 - occ_13 - occ_14;
  // F_n is a prefix of F_{n + 2}
  // F_n is a suffix of F_{n + 1}
  // |F_{11}| = 144
  // |F_{12}| = 233
  // |F_{13}| = 377
  // F_14 = F_12 + F_13 (suffix + odd prefix)
  // F_15 = F_13 + F_14 (suffix + even prefix)
  Long a = occ_14;
  Long b = occ_15;
  for (int i = N; i <= n; ++i) {
    std::swap(a, b);
    b = std::min(b + a + (i & 1 ? cross_even : cross_odd), INF);
  }
  return b;
}

int main() {
  fib[0] = "0";
  fib[1] = "1";
  for (int n = 2; n < N; ++n) {
    fib[n] = fib[n - 2] + fib[n - 1];
  }
  int n, m;
  Long k;
  scanf("%d%lld%d", &n, &k, &m);
  std::string result;
  while (m--) {
    Long subtotal = count(n, result + "0");
    if (subtotal >= k) {
      result += "0";
    } else {
      k -= subtotal;
      result += "1";
    }
    if (fib[N - 1].substr(fib[N - 1].size() - result.size(), result.size()) ==
        result) {
      k--;
    }
    if (k == 0) {
      break;
    }
  }
  std::cout << result << std::endl;
}