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

const int N = 100010, L = 60;

int n, m;
ll a[N];
int relabel[N], dis[L * 2 + 5];
vector<int> ver[L];
vector<pair<int, int>> e;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i) {
    while (a[i]) {
      int j = __builtin_ctzll(a[i]);
      a[i] ^= 1LL << j;
      ver[j].push_back(i);
      if (ver[j].size() > 2) {
        puts("3");
        return 0;
      }
    }
  }
  int ans = 1000;
  for (int i = 0; i < L; ++i)
    if (ver[i].size() == 2) {
      for (int x : ver[i])
        if (!relabel[x]) relabel[x] = ++m;
      sort(ver[i].begin(), ver[i].end());
      e.emplace_back(relabel[ver[i][0]], relabel[ver[i][1]]);
    }
  for (int i = 0; i < e.size(); ++i) {
    fill(begin(dis), end(dis), 1000);
    dis[e[i].first] = 0;
    for (int rep = 1; rep < m; ++rep)
      for (int j = 0; j < e.size(); ++j)
        if (e[i] != e[j]) {
          dis[e[j].first] = min(dis[e[j].first], dis[e[j].second] + 1);
          dis[e[j].second] = min(dis[e[j].second], dis[e[j].first] + 1);
        }
    ans = min(ans, dis[e[i].second] + 1);
  }
  printf("%d\n", ans < 1000 ? ans : -1);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}