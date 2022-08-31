//#include <cassert>
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

const int N = 100010;

int n, res;
int a[N], prv[N], inv[N], rep[N];
bool vis[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
      inv[a[i]] = i;
    memset(vis + 1, 0, sizeof(bool) * n);
    res = n;
    vector<vector<int>> ans;
    while (res) {
      vector<int> stk(1);
      for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
          int pos = lower_bound(stk.begin() + 1, stk.end(), a[i]) - stk.begin();
          prv[i] = inv[stk[pos - 1]];
          if (pos == stk.size()) {
            rep[i] = 0;
            stk.push_back(a[i]);
          } else {
            rep[i] = inv[stk[pos]];
            stk[pos] = a[i];
          }
        } else
          rep[i] = 0;
      if (stk.size() * (stk.size() - 1LL) / 2 < res) {
        for (int j = 1; j < stk.size(); ++j) {
          vector<int> cur;
          int pos = inv[stk[j]];
          while (pos) {
            cur.push_back(a[pos]);
            pos = rep[pos];
          }
          reverse(cur.begin(), cur.end());
          ans.push_back(cur);
        }
        break;
      }
      int pos = inv[stk.back()];
      vector<int> cur;
      while (pos) {
        vis[pos] = true;
        --res;
        cur.push_back(a[pos]);
        pos = prv[pos];
      }
      reverse(cur.begin(), cur.end());
      ans.push_back(cur);
    }
    printf("%lu\n", ans.size());
    for (const auto& v : ans) {
      printf("%lu", v.size());
      for (int x : v)
        printf(" %d", x);
      putchar('\n');
    }
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}