#include <bits/stdc++.h>

using namespace std;

int n, m;
long long sum, a[200000], bi;

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

int main() {
  scanf("%d%d%lld", &n, &m, &a[0]);
  for (int i = 1; i < n; ++i) {
    scanf("%lld", &a[i]);
    sum = gcd(sum, abs(a[i] - a[i - 1]));
  }
  while (m--) {
    scanf("%lld", &bi);
    printf("%lld ", gcd(sum, a[0] + bi));
  }
  return 0;
}