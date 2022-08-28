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

const int N = 200010;

char s[N], b[N], c[N];

void solve() {
  int n;
  scanf("%d%s", &n, s + 1);
  c[n + 1] = 0;
  for (int k = 0; k <= 9; ++k) {
    int cnt = 0, lst = -1;
    for (int i = 1; i <= n; ++i)
      if (s[i] - '0' < k) {
        b[++cnt] = s[i];
        lst = i;
        c[i] = '1';
      }
    for (int i = lst; i <= n; ++i)
      if (s[i] - '0' == k) {
        b[++cnt] = s[i];
        c[i] = '1';
      }
    for (int i = 1; i <= n; ++i)
      if (s[i] - '0' > k || (s[i] - '0' == k && i < lst)) {
        b[++cnt] = s[i];
        c[i] = '2';
      }
    if (is_sorted(b + 1, b + n + 1)) {
      puts(c + 1);
      return;
    }
  }
  puts("-");
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}