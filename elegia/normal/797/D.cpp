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

const int N = 100010;

int n;
int a[N];
int ch[N][2];
map<int, int> cnt, cost;
bool vis[N];

int ans;

void dfs(int u, int l, int r) {
  ++cost[a[u]];
  if (!(a[u] < l || a[u] > r))
    ++cnt[a[u]];
  if (ch[u][0] != -1)
    dfs(ch[u][0], l, min(r, a[u] - 1));
  if (ch[u][1] != -1)
    dfs(ch[u][1], max(l, a[u] + 1), r);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &a[i], &ch[i][0], &ch[i][1]);
    for (int j = 0; j < 2; ++j)
      if (ch[i][j] != -1)
        vis[ch[i][j]] = true;
  }
  int rt = 1;
  while (vis[rt])
    ++rt;
  dfs(rt, 0, 1e9);
  for (const auto& pr : cost)
    if (!cnt[pr.first])
      ans += pr.second;
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}