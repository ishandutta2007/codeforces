#include <cstdio>

#include <algorithm>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);

    int g = gcd(x, y);
    x /= g; y /= g;
    if (x > y) swap(x, y);
    puts((max((y - 2) / x, 0) + 1) >= k ? "REBEL" : "OBEY");
  }

  return 0;
}