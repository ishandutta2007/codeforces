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

int n, m, k;
int p[N], d[N], w[N];
map<int, ll> dp[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 2; i <= n; ++i)
    scanf("%d", &p[i]);
  while (m--) {
    int v;
    scanf("%d", &v);
    scanf("%d%d", &d[v], &w[v]);
  }
  for (int i = 1; i <= n; ++i) {
    dp[i].insert(make_pair(k + 1, 1LL << 60));
  }
  for (int i = n; i > 1; --i) {
    if (w[i]) {
      dp[i][d[i]] += w[i];
      auto it = dp[i].upper_bound(d[i]);
      ll v = w[i];
      while (v >= it->second) {
        v -= it->second;
        dp[i].erase(it++);
      }
      it->second -= v;
    }
    if (dp[p[i]].size() < dp[i].size())
      swap(dp[p[i]], dp[i]);
    for (const auto& pr : dp[i])
      if (pr.first != k + 1)
        dp[p[i]][pr.first] += pr.second;
  }
  ll ans = 0;
  for (const auto& pr : dp[1])
    if (pr.first != k + 1)
      ans += pr.second;
      printf("%lld\n", ans);


#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}

/*
 * 6110620899
 */