#include <cstdio>
#include <cstring>

using namespace std;

int T, N, e, s, ans, a[200010];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    memset(a, 0, sizeof(int) * (N + 10));
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &e);
      ++a[e];
    }
    ans = s = 0;
    for (int i = 1; i <= N; ++i) {
      s += a[i];
      while (s >= i) {
        ++ans;
        s -= i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}