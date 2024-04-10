#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const Long INF = 1'000'000'000'000'000'001;

Long mul(Long a, Long b) { return a <= INF / b ? a * b : INF; }

int main() {
  Long x, y, l, r;
  std::cin >> x >> y >> l >> r;
  std::vector<Long> values{l - 1, r + 1};
  for (Long px = 1; px <= r; px = mul(px, x)) {
    for (Long py = 1; px + py <= r; py = mul(py, y)) {
      if (px + py >= l) {
        values.push_back(px + py);
      }
    }
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  Long result = 0;
  for (size_t i = 1; i < values.size(); ++i) {
    result = std::max(result, values[i] - values[i - 1] - 1);
  }
  printf("%lld\n", result);
}