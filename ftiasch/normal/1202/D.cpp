#line 1 "sol.cpp"
#include <bits/stdc++.h>

const char *P = "1337";

long long count(const std::string &s) {
  long long dp[5]{1};
  for (char c : s) {
    for (int i = 3; i >= 0; --i) {
      if (c == P[i]) {
        dp[i + 1] += dp[i];
      }
    }
  }
  return dp[4];
}

int binom2(int n) { return n * (n - 1) / 2; }

std::string solve(int n) {
  std::string s;
  int t = 2;
  while (binom2(t + 1) <= n) {
    t++;
  }
  while (t > 1) {
    while (binom2(t) <= n) {
      s += "1";
      n -= binom2(t);
    }
    s += "3";
    t--;
  }
  //   printf("cnt=%d\n", cnt);
  assert(n == 0);
  return s + "37";
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    puts(solve(n).c_str());
  }
}