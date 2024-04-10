#include <bits/stdc++.h>

using Long = long long;

bool check(Long a, Long b, Long x) {
  if (a < b) {
    std::swap(a, b);
  }
  if (b == x) {
    return true;
  }
  while (a >= x && b != 0) {
    if ((a - x) % b == 0) {
      return true;
    }
    a %= b;
    std::swap(a, b);
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    long long a, b, x;
    std::cin >> a >> b >> x;
    std::cout << (check(a, b, x) ? "YES" : "NO") << std::endl;
  }
}