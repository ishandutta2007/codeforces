#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAXN = 100005;
int n;

int a[MAXN];
int _sum_p[MAXN]; int *sum_p = _sum_p + 1;
int _sum_g[MAXN]; int *sum_g = _sum_g + 1;

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);

  REP(i, n) {
    sum_p[i] = sum_p[i - 1];
    sum_g[i] = sum_g[i - 1];

    if (a[i] == 1)
      ++sum_p[i];
    else
      ++sum_g[i];
  }

  vector< pair< int, int > > sol;

  REP(i, n) {
    int maxw = max(sum_p[i], sum_g[i]);
    int lmax = max(sum_p[i - 1], sum_g[i - 1]);
    if (lmax == maxw) continue;

    bool good = true;
    int from = i + 1;
    int t = maxw;

    int last_win_p = 0, win_p = 0;
    int last_win_g = 0, win_g = 0;

    if (sum_p[i] > sum_g[i]) 
      ++win_p;
    else
      ++win_g;

    while (from < n) {
      int lo = from, hi = n - 1, mid;

      while (lo < hi) {
        mid = (lo + hi) / 2;
        int maxw = max(sum_p[mid] - sum_p[from - 1], sum_g[mid] - sum_g[from - 1]);

        if (maxw < t)
          lo = mid + 1;
        else
          hi = mid;
      }

      int cwin_p = sum_p[lo] - sum_p[from - 1];
      int cwin_g = sum_g[lo] - sum_g[from - 1];

      int maxw = max(cwin_p, cwin_g);

      if (maxw != t) {
        good = false;
        break;
      }

      last_win_p = win_p;
      last_win_g = win_g;

      from = lo + 1;
      if (cwin_p > cwin_g)
        ++win_p;
      else
        ++win_g;
    }

    if (max(win_p, win_g) == max(last_win_p, last_win_g))
      good = false;

    int s = max(win_p, win_g);

    if (good)
      sol.push_back({s, t});
  }

  sort(sol.begin(), sol.end());
  sol.resize(unique(sol.begin(), sol.end()) - sol.begin());

  printf("%d\n", (int)sol.size());
  for (auto p : sol)
    printf("%d %d\n", p.first, p.second);

  return 0;
}