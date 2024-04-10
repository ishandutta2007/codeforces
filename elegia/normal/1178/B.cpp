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

const int N = 1000010;

int cnt[N];
char s[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    cnt[i] = cnt[i - 1] + (s[i] == 'v' && s[i - 1] == 'v');
  int c2 = 0;
  ll ans = 0;
  for (int i = n; i; --i) {
    c2 += (s[i] == 'v' && s[i + 1] == 'v');
    if (s[i] == 'o')
      ans += c2 * (ll)cnt[i];
  }
  printf("%lld\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}