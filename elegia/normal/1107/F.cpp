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

const int N = 510;

int n;
pair<int, pair<int, int>> o[N];
ll dp[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    o[i] = make_pair(b, make_pair(a, k));
  }
  sort(o + 1, o + n + 1);
  reverse(o + 1, o + n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int k = i; k >= 0; --k) {
      for (int j = i - k; j >= 0; --j) {
        if (j)
          dp[j][k] = max(dp[j][k], dp[j - 1][k] + o[i].second.first - o[i].first * (ll)(j - 1));
        if (k)
          dp[j][k] = max(dp[j][k], dp[j][k - 1] + o[i].second.first - o[i].first * (ll)o[i].second.second);
      }
    }
  }/*
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j)
      LOG("%lld ", dp[i][j]);
    LOG("\n");
  }*/
  printf("%lld\n", *max_element(dp[0], dp[n] + n + 1));

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}