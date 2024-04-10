#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

bitset<840 * 8 * 2> s;
ll l[10], r[10];

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  ll w;
  scanf("%lld", &w);
  for (int i = 1; i <= 8; ++i)
    scanf("%lld", &r[i]);
  ll sum = 0;
  for (int i = 1; i <= 8; ++i) {
    sum += r[i] * i;
    l[i] = -r[i];
    r[i] = 0;
  }
  if (sum <= w) {
    printf("%lld\n", sum);
    return 0;
  }
  for (int i = 8; i; --i) {
    ll off = 0;
    if (sum + l[i] * i >= w) {
      off = l[i];
    } else {
      off = -(sum - w + i - 1) / i;
    }
    sum += off * i;
    l[i] -= off;
    r[i] -= off;
    if (sum <= w)
      break;
  }
  s.set(840 * 8);
  for (int i = 1; i <= 8; ++i) {
    bitset<840 * 8 * 2> tmp;
    l[i] = max(l[i], -840LL * 8 / i);
    r[i] = min(r[i], 840LL * 8 / i);
    //LOG("%lld~%lld\n", l[i], r[i]);
    for (int j = l[i]; j <= r[i]; ++j)
      if (j < 0)
        tmp |= s >> (-j * i);
      else
        tmp |= s << (j * i);
    swap(tmp, s);
  }
  for (int i = w - sum; i >= 0; --i)
    if (s[i + 840 * 8]) {
      printf("%lld\n", sum + i);
      break;
    }

  return 0;
}