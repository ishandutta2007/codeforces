#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d", &k);
    // e / (e + w) = k / 100
    // 100 * e = k * (e + w)
    // (100 - k) * e = k * w
    int w = k;
    int e = 100 - w;
    int g = std::__gcd(w, e);
    w /= g;
    e /= g;
    printf("%d\n", w + e);
  }
}