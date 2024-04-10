#include <iostream>

using Long = long long;

// return true -- find an ind set of size n
bool solve(Long s, Long n, Long k) {
  if (s == k) {
    return false;
  }
  if (s < k) {
    return true;
  }
  //   if (s % k != 0) {
  Long count = 0;
  //   for (int r = 0; r < k && r <= s; ++r) {
  //     // r + x * k <= s
  //     // x * k <= s - r
  //     count += (((s - r) / k + 1) + 1) >> 1;
  //   }
  Long q = s % k;
  count += (q + 1) * ((s / k + 2) >> 1);
  count += (k - 1 - q) * ((s / k + 1) >> 1);
  return count >= n + 1;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    Long s, n, k;
    std::cin >> s >> n >> k;
    puts(solve(s, n, k) ? "NO" : "YES");
  }
}