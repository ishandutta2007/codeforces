#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 20, P = 1000000007;

int n;
int f[1 << N], pw[1 << N];

int norm(int x) { return x >= P ? (x - P) : x; }

int main() {
  int m, mx = 0;
  scanf("%d", &m);
  pw[0] = 1;
  for (int rep = 1; rep <= m; ++rep) {
    pw[rep] = norm(pw[rep - 1] << 1);
    int a;
    scanf("%d", &a);
    ++f[a];
    mx = max(mx, a);
  }
  while ((1 << n) <= mx)
    ++n;
  for (int i = 0; i < n; ++i)
    for (int s = (1 << n) - 1; s >= 0; --s)
      if (!(s >> i & 1))
        f[s] += f[s | 1 << i];
  int ans = 0;
  for (int s = 0; s < 1 << n; ++s)
    if (__builtin_parity(s))
      ans = norm(ans + P - pw[f[s]]);
    else
      ans = norm(ans + pw[f[s]]);
  if (n == 0)
    --ans;
  printf("%d\n", ans);
  return 0;
}