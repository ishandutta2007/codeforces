#include <cstdio>
#include <cstring>

using namespace std;

int A, B, C, D;
long long n, l, r, ans;

inline long long sum(long long x) { return x * (x + 1) / 2; }

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &D);
  n = B - A + 1;
  for (int i = C; i <= D; ++i) {
    l = i - C + 1;
    r = i - B + 1;
    if (l < A && B < r)
      ans += sum(n) + (A - l) * n; else
    if (A <= l && l <= B && B < r)
      ans += sum((B + 1) - l); else
    if (l < A && A <= r && r <= B)
      ans += sum(n) - sum(B - r) + (A - l) * n; else
    if (A <= l && l <= B && A <= r && r <= B)
      ans += sum((B + 1) - l) - sum(B - r); else
    if (r < A) ans += (r - l + 1) * n;
  }
  printf("%lld\n", ans);
  return 0;
}