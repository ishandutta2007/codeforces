#include <cstdio>

using namespace std;

int T, p1, p2, k;

void ans(bool flag) { puts(flag ? "OBEY" : "REBEL"); }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &p1, &p2, &k);
    if (p1 < p2) p1 ^= p2 ^= p1 ^= p2;
    if (p1 == p2) ans(k > 1); else
    if (p1 % p2 == 0) ans(k > p1 / p2 - 1); else {
      int g = gcd(p1, p2);
      p1 /= g;
      p2 /= g;
      ans(k > (p1 - 2) / p2 + 1);
    }
  }
  return 0;
}