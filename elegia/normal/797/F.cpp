#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5010;
const ll INF = 1LL << 60;

struct MQue {
  int l, r;
  ll cur[N];
  int cnt[N];
  
  void clr() {
    l = 1;
    r = 0;
  }
  
  void pop() {
    if (--cnt[l] == 0)
      ++l;
  }
  
  void ins(ll x) {
    int cc = 1;
    while (r >= l && cur[r] >= x) {
      cc += cnt[r];
      --r;
    }
    ++r;
    cnt[r] = cc;
    cur[r] = x;
  }
  
  ll top() const {
    return cur[l];
  }
} mq;

int n, m;
int x[N];
pair<int, int> h[N];
ll s[N];
ll dp[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &x[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &h[i].first, &h[i].second);
  }
  sort(x + 1, x + n + 1);
  sort(h + 1, h + m + 1);
  fill(dp + 1, dp + n + 1, INF);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j)
      s[j] = s[j - 1] + abs(x[j] - h[i].first);
    mq.clr();
    mq.ins(0);
    for (int j = 1; j <= n; ++j) {
      if (j > h[i].second)
        mq.pop();
      ll sv = dp[j];
      dp[j] = min(dp[j], s[j] + mq.top());
      mq.ins(sv - s[j]);
    }
  }
  if (dp[n] < INF)
    printf("%lld\n", dp[n]);
  else
    puts("-1");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}