#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  ll ans = 0;
  int r = 0;
  while (n--) {
    int a;
    scanf("%d", &a);
    int y = min(a / 2, r);
    a -= y * 2;
    r -= y;
    ans += y;
    ans += a / 3;
    r += a % 3;
  }
  printf("%lld\n", ans);
  return 0;
}