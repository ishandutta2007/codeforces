#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

const int L = 20, N = 1 << 20;

int l, n;
int a[N + 10];
ll ans[N + 10];
ll val[L + 3][2];

ll calc(int l1, int r1, int l2, int r2) {
  ll ret = 0;
  while (l1 <= r1 || l2 <= r2) {
    if (l1 <= r1 && (l2 > r2 || a[l1] <= a[l2]))
      ++l1;
    else {
      ++l2;
      ret += r1 - l1 + 1;
    }
  }
  return ret;
}

void dc(int l, int r, int len) {
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  dc(l, mid, len - 1);
  dc(mid + 1, r, len - 1);
  val[len][0] += calc(l, mid, mid + 1, r);
  val[len][1] += calc(mid + 1, r, l, mid);
  static int tmp[N + 10];
  merge(a + l, a + mid + 1, a + mid + 1, a + r + 1, tmp);
  memcpy(a + l, tmp, sizeof(int) * (r - l + 1));
}

int main() {
  scanf("%d", &l);
  n = 1 << l;
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  dc(0, n - 1, l - 1);
  for (int i = 0; i < l; ++i)
    ans[0] += val[i][0];
  for (int j = 1; j < n; ++j) {
    int pos = __builtin_ctz(j);
    ans[j] = ans[j ^ (1 << pos)] + val[pos][1] - val[pos][0];
  }
  int q, s = 0;
  scanf("%d", &q);
  while (q--) {
    int qq;
    scanf("%d", &qq);
    s ^= (1 << qq) - 1;
    printf("%lld\n", ans[s]);
  }
  return 0;
}