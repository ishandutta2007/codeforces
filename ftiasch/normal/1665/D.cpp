#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Mock {
  int ask(int a, int b) const {
    assert(a > 0 && b > 0 && a != b);
    return std::__gcd(hidden + a, hidden + b);
  }

  void report(int x) const { assert(x == hidden); }

  int hidden;
};

struct IO {
  int ask(int a, int b) const {
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int result;
    scanf("%d", &result);
    return result;
  }

  void report(int x) const {
    printf("! %d\n", x);
    fflush(stdout);
  }
};

template <typename IO> void solve(IO &&io) {
  int r = 0;
  for (int k = 1; k <= 30; ++k) {
    // x mod 2^{k - 1} = r
    // (x - r) mod 2^k = 0 or 2^{k - 1}
    // gcd(x - r + 2^{k - 1}, 2^k) = 2^{k - 1} or 2^k
    int delta = (1 << (k - 1)) - r;
    if (io.ask(delta, delta + (1 << k)) == (1 << k)) {
      r |= 1 << (k - 1);
    }
  }
  io.report(r);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T --) {
    solve(IO{});
  }
}