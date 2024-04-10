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

#define foo first
#define bar second.first
#define baz second.second

int n;
pair<int, pair<int, int>> dp[N];
vector<int> ch[N];

int norm(int x) { return x >= P ? x - P : x; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    ch[p].push_back(i);
  }
  for (int i = n; i; --i) {
    if (ch[i].empty())
      dp[i].foo = 1;
    else {
      dp[i].baz = 1;
      for (int v : ch[i]) {
        dp[i] = make_pair((dp[i].foo * (dp[v].foo + (ll)dp[v].bar + dp[v].foo + dp[v].baz) + dp[i].bar * (ll)(dp[v].bar + dp[v].foo)) % P, make_pair((dp[i].bar * (ll)(dp[v].baz + dp[v].foo) + (dp[v].bar + dp[v].foo) * (ll)dp[i].baz) % P, dp[i].baz * (ll)(dp[v].baz + dp[v].foo) % P));
        //LOG("%d: %d %d %d\n", i, dp[i].foo, dp[i].bar, dp[i].baz);
      }
    }
  }
  printf("%d\n", norm(dp[1].foo + dp[1].baz));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}