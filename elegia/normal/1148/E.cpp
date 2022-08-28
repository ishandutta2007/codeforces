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
#include <stack>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300010;

int n;
int t[N];
pair<int, int> s[N];
vector<pair<pair<int, int>, int>> ans;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i].first);
    s[i].second = i;
  }
  for (int i = 1; i <= n; ++i)
    scanf("%d", &t[i]);
  sort(s + 1, s + n + 1);
  sort(t + 1, t + n + 1);
  for (int i = 1; i <= n; ++i)
    s[i].first -= t[i];
  stack<pair<int, int>> stk;
  for (int i = 1; i <= n; ++i) {
    if (s[i].first < 0)
      stk.push(s[i]);
    else {
      while (s[i].first > 0) {
        if (stk.empty()) {
          puts("NO");
          return 0;
        }
        if (-stk.top().first >= s[i].first) {
          ans.emplace_back(make_pair(stk.top().second, s[i].second), s[i].first);
          stk.top().first += s[i].first;
          s[i].first = 0;
        } else {
          ans.emplace_back(make_pair(stk.top().second, s[i].second), -stk.top().first);
          s[i].first += stk.top().first;
          stk.pop();
        }
      }
    }
  }
  while (!stk.empty()) {
    if (stk.top().first != 0) {
      puts("NO");
      return 0;
    }
    stk.pop();
  }
  puts("YES");
  printf("%lu\n", ans.size());
  for (const auto& pr : ans)
    printf("%d %d %d\n", pr.first.first ,pr.first.second, pr.second);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}