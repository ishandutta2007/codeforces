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

const int N = 200010, P = 998244353;

int n;
int sub[N];
vector<int> g[N];

int dfs(int u) {
  int ret = 1;
  int cnt = 0;
  sub[u] = 1;
  for (int v : g[u])
    if (!sub[v]) {
      ret = ret * (ll)dfs(v) % P * ++cnt % P;
    }
  if (u != 1)
    ret = ret * (ll)++cnt % P;
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  printf("%d\n", int(dfs(1) * (ll)n % P));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}