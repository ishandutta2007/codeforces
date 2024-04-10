// #include "debug.h"

#include <bits/stdc++.h>

struct Line {
  int k;
  long long b;

  long long eval(long long x) const { return k * x + b; }
};

// std::ostream &operator<<(std::ostream &out, const Line &l) {
//   return out << "y=" << l.k << "x+" << l.b;
// }

bool check(const Line &u, const Line &v, const Line &w) {
  return __int128(u.b - v.b) * (w.k - v.k) < __int128(v.b - w.b) * (v.k - u.k);
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<long long> s1(n + 1), s2(n + 1);
  for (int i = n; i--;) {
    s1[i] = a[i] + s1[i + 1];
    s2[i] = (i + 1LL) * a[i] + s2[i + 1];
  }
  // [i, j)
  //   sum_{i <= k < j} a[k] * (k - i + 1)
  // = sum_{i <= k < j} a[k] * (k + 1) - i * sum_{i <= k < j} a[k]
  // = s2[i] - s2[j] - i * (s1[i] - s1[j])
  // = (i * s1[j] + (s2[i] - i * s1[i])) - s2[j]
  long long result = 0;
  std::vector<Line> lines;
  for (int j = 1; j <= n; ++j) {
    // for (int i = 0; i < j; ++i) {
    //   result = std::max(result, i * s1[j] + (s2[i] - i * s1[i]) - s2[j]);
    // }
    const Line l{j - 1, s2[j - 1] - (j - 1) * s1[j - 1]};
    while (lines.size() >= 2 &&
           !check(lines[lines.size() - 2], lines[lines.size() - 1], l)) {
      lines.pop_back();
    }
    lines.push_back(l);
    // std::cerr << lines << std::endl;
    // for (size_t i = 1; i < lines.size(); ++i) {
    //   std::cerr << 1.0 * (lines[i - 1].b - lines[i].b) /
    //                    (lines[i].k - lines[i - 1].k) << " ";
    // }
    // std::cerr << std::endl;
    int low = 0;
    int high = lines.size();
    while (low + 1 < high) {
      int middle = (low + high) >> 1;
      if (s1[j] * (lines[middle].k - lines[middle - 1].k) <=
          (lines[middle - 1].b - lines[middle].b)) {
        high = middle;
      } else {
        low = middle;
      }
    }
    // std::cerr << s1[j] << " " << lines[low] << std::endl;
    result = std::max(result, lines[low].eval(s1[j]) - s2[j]);
  }
  printf("%lld\n", result);
}