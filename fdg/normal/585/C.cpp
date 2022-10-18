#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  long long x, y;
  cin >> x >> y;
  if (gcd(x, y) > 1) {
    cout << "Impossible\n";
    return 0;
  }
  while (x > 1 || y > 1) {
    if (x > y) {
      printf("%lldA", x / y - (x % y == 0));
      x %= y;
    } else {
      printf("%lldB", y / x - (y % x == 0));
      y %= x;
    }
  }
  printf("\n");
  return 0;
}