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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, k, a, b;
  scanf("%d%d%d%d", &n, &k, &a, &b);
  ll x = numeric_limits<ll>::max(), y = 0;
  for (int i = 1; i <= n; ++i) {
    ll step = i * (ll)k + b - a;
    ll v = n * (ll)k / gcd(step, n * (ll)k);
    x = min(x, v);
    y = max(y, v);
    step = i * (ll)k + a + b;
    v = n * (ll)k / gcd(step, n * (ll)k);
    x = min(x, v);
    y = max(y, v);
  }
  printf("%lld %lld\n", x, y);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}