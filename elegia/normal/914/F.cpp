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

const int N = 100010;

int n;
char s[N], t[N];
bitset<N> b[26];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    b[s[i] - 'a'].set(i);
  int q;
  scanf("%d", &q);
  while (q--) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      char c;
      scanf(" %c", &c);
      b[s[x] - 'a'].reset(x);
      s[x] = c;
      b[s[x] - 'a'].set(x);
    } else {
      int y;
      scanf("%d%s", &y, t + 1);
      int m = strlen(t + 1);
      bitset<N> cur;
      cur.set();
      cur &= cur << x;
      cur &= cur >> (N - y + m - 2);
      for (int i = 1; i <= m; ++i)
        cur &= b[t[i] - 'a'] >> (i - 1);
      printf("%lu\n", cur.count());
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}