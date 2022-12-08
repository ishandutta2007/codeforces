#include <cstdio>
#include <algorithm>

using namespace std;

int t;
long long a1, a2, K;

long long minDigit(long long a) {
  long long ans = 9;
  while (a) {
    ans = min(ans, a % 10);
    a /= 10;
  }
  return ans;
}

long long maxDigit(long long a) {
  long long ans = 0;
  while (a) {
    ans = max(ans, a % 10);
    a /= 10;
  }
  return ans;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &a1, &K);
    while (minDigit(a1) && --K) {
      a2 = a1 + minDigit(a1) * maxDigit(a1);
      a1 = a2;
    }
    printf("%lld\n", a1);
  }
  return 0;
}