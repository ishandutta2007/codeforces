#include <bits/stdc++.h>

struct Num {
  int rank() const {
    if (sign < 0) {
      return -(exp + 1);
    }
    if (sign == 0) {
      return 0;
    }
    return exp + 1;
  }

  Num mul(int a) const {
    int s = sign;
    if (a < 0) {
      s = -s;
    } else if (a == 0) {
      s = 0;
    }
    int e = exp;
    if (std::abs(a) == 2) {
      e++;
    }
    return Num{s, e};
  }

  int sign, exp;
};

bool operator<(const Num &a, const Num &b) { return a.rank() < b.rank(); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    Num one{1, 0};
    std::pair<Num, int> mi{one, 0}, ma{one, 0};
    std::tuple<Num, int, int> result{one, 0, n};
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      mi.first = mi.first.mul(a);
      ma.first = ma.first.mul(a);
      if (ma.first < mi.first) {
        std::swap(mi, ma);
      }
      mi = std::min(mi, {one, i + 1});
      ma = std::max(ma, {one, i + 1});
      result = std::max(result, {ma.first, ma.second, n - 1 - i});
    }
    auto [_, a, b] = result;
    printf("%d %d\n", a, b);
  }
}