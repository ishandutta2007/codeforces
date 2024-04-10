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

const int N = 300010;

vector<pair<ll, int>> b[62];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  ll sum = 0;
  while (n--) {
    int a;
    ll mask;
    scanf("%d%lld", &a, &mask);
    sum += a;
    for (int i = 0; i < 62; ++i)
      if (mask >> i & 1) {
        b[i].emplace_back(mask, a);
        break;
      }
  }
  if (sum < 0) {
    for (int i = 0; i < 62; ++i)
      for (auto& pr : b[i])
        pr.second = -pr.second;
  }
  ll s = 0;
  for (int i = 61; i >= 0; --i) {
    ll su = 0;
    for (const auto& pr : b[i])
      if (__builtin_parityll(pr.first & s))
        su -= pr.second;
      else
        su += pr.second;
    if (su > 0)
      s |= 1LL << i;
  }
  printf("%lld\n", s);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}