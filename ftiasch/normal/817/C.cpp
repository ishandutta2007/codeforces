#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int LIM = 200;

int digit_sum(Long x) {
  int result = 0;
  while (x) {
    result += x % 10;
    x /= 10;
  }
  return result;
}

int main() {
  Long n, s;
  std::cin >> n >> s;
  Long result = 0;
  for (Long x = s; x < s + LIM && x <= n; ++x) {
    result += std::abs(x - digit_sum(x)) >= s;
  }
  if (s + LIM <= n) {
    result += n - (s + LIM) + 1;
  }
  std::cout << result << std::endl;
}