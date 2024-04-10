#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int mu[N + 1];
std::vector<int> divisors[N + 1];

long long count(long long n, int p) {
  // [1, n] p
  long long result = 0;
  for (int d : divisors[p]) {
    result += mu[d] * (n / d);
  }
  return result;
}

int main() {
  mu[1] = 1;
  for (int i = 1; i <= N; ++i) {
    if (mu[i]) {
      for (int j = i; j <= N; j += i) {
        divisors[j].push_back(i);
      }
    }
    for (int j = i + i; j <= N; j += i) {
      mu[j] -= mu[i];
    }
  }
  //   int max = 0;
  //   for (int i = 1; i <= N; ++ i) {
  //       max = std::max(max, static_cast<int>(divisors[i].size()));
  //   }
  //   printf("%d\n", max);
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, p, k;
    scanf("%d%d%d", &x, &p, &k);
    int sub = count(x, p);
    long long low = x + 1;
    long long high = x + 1LL * k * p;
    while (low < high) {
      long long middle = (low + high) >> 1;
      if (count(middle, p) - sub >= k) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    printf("%lld\n", high);
  }
}