#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  vector<ll> ans;
  function<void(int)> d = [&](int x) {
    int cnt = n / x;
    ans.push_back(cnt * (ll)(cnt - 1) / 2 * x + cnt);
  };
  for (int x = 1; x * x <= n; ++x)
    if (n % x == 0) {
      d(x);
      if (x * x != n)
        d(n / x);
    }
  sort(ans.begin(), ans.end());
  for (ll a : ans)
    printf("%lld ", a);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}