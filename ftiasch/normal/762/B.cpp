#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int a, b, c, n;
  scanf("%d%d%d%d", &a, &b, &c, &n);
  std::vector<int> usb, ps;
  char buffer[5];
  for (int i = 0, v; i < n; ++i) {
    scanf("%d%s", &v, buffer);
    if (*buffer == 'U') {
      usb.push_back(v);
    } else {
      ps.push_back(v);
    }
  }
  std::sort(usb.begin(), usb.end());
  std::sort(ps.begin(), ps.end());
  std::pair<int, long long> best{0, 0};
  std::vector<long long> sum_ps(ps.size() + 1);
  for (size_t i = 0; i < ps.size(); ++i) {
    sum_ps[i + 1] = sum_ps[i] + ps[i];
  }
  long long sum_usb = 0;
  for (int i = 0; i <= usb.size() && i <= a + c; ++i) {
    int j = std::min(b + c - std::max(i - a, 0), static_cast<int>(ps.size()));
    best = std::max(best, {i + j, -(sum_usb + sum_ps[j])});
    if (i < usb.size()) {
      sum_usb += usb[i];
    }
  }
  printf("%d %lld\n", best.first, -best.second);
}