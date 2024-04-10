#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll calc(ll n) {
  ll i = 10, ret = 0;
  int k = 1;
  while (i - 1 <= n) {
    ret += k * (i / 10 * 9);
    ++k;
    i *= 10;
  }
  return ret + k * (n - i / 10 + 1);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  ll k;
  scanf("%lld\n", &k);
  ll l = 0, r = 1e12;
  while (l < r) {
    ll mid = (l + r + 1) >> 1;
    if (calc(mid) >= k)
      r = mid - 1;
    else
      l = mid;
  }
  string s = to_string(l + 1);
  reverse(s.begin(), s.end());
  putchar(to_string(l + 1)[k - calc(l) - 1]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}