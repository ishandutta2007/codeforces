#include <bits/stdc++.h>

const int N = 300'000;

int n, k;
long long s[N + 1];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    s[i] = a;
  }
  for (int i = n; i--;) {
    s[i] += s[i + 1];
  }
  std::sort(s + 1, s + n, std::greater<long long>());
  std::cout << std::accumulate(s, s + k, 0LL) << std::endl;
}