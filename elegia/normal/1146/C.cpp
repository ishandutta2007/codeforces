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

int ask(const vector<int>& v1, const vector<int>& v2) {
  if (v1.empty() || v2.empty())
    return 0;
  printf("%d %d", (int)v1.size(), (int)v2.size());
  for (int u : v1)
    printf(" %d", u);
  for (int u : v2)
    printf(" %d", u);
  putchar('\n');
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i <= 6; ++i) {
      vector<int> v1, v2;
      for (int j = 0; j < n; ++j)
        if (j >> i & 1)
          v1.push_back(j + 1);
        else
          v2.push_back(j + 1);
      ans = max(ans, ask(v1, v2));
    }
    printf("-1 %d\n", ans);
    fflush(stdout);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}