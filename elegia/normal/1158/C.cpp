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
#include <stack>
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

const int N = 500010;

int cnt;
int ans[N], ne[N];

vector<int> g[N];

void dfs(int u) {
  for (int v : g[u])
    dfs(v);
  ans[u] = ++cnt;
}

void solve() {
  int n;
  scanf("%d", &n);
  fill(g + 1, g + n + 2, vector<int>());
  for (int i = 1; i <= n; ++i)
    scanf("%d", &ne[i]);
  cnt = 0;
  stack<int> stk;
  stk.push(n + 1);
  for (int i = n; i; --i) {
    if (ne[i] != -1) {
      while (stk.top() < ne[i]) {
        g[i].push_back(stk.top());
        stk.pop();
      }
      if (stk.top() != ne[i]) {
        puts("-1");
        return;
      }
    }
    stk.push(i);
  }
  while (stk.size() > 1) {
    int v = stk.top();
    stk.pop();
    g[stk.top()].push_back(v);
  }
  dfs(n + 1);
  for (int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  putchar('\n');
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--)
    solve();

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}