#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  long long n, m, a, b;
  std::cin >> n >> m >> a >> b;
  long long r = n % m;
  std::cout << std::min(r * b, (m - r) * a) << std::endl;
}