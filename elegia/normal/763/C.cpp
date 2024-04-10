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
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

void exGcd(int a, int b, int&x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a, int p) {
  int x, y;
  exGcd(a, p, x, y);
  if (x < 0)
    x += p;
  return x;
}

int n, p;
int a[N];
bool vis[N];

pair<int, int> solve(int n) {
  if (n == 1)
    return make_pair(a[1], 1);
  a[n + 1] = -1;
  sort(a + 1, a + n + 1);
  int d = a[2] - a[1], cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      vis[i] = true;
      ++cnt;
      int cur = 1;
      int x = a[i];
      while (true) {
        if ((x += d) >= p)
          x -= p;
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        if (a[pos] == x) {
          vis[pos] = true;
          ++cur;
        } else
          break;
      }
      x = a[i];
      while (true) {
        if ((x -= d) < 0)
          x += p;
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        if (a[pos] == x) {
          vis[pos] = true;
          ++cur;
        } else
          break;
      }
      LOG("%d %d\n", (x + d) % p, cur);
    }
  d = d * (ll)inv(cnt, p) % p;
  int x = a[1], pans;
  while (true) {
    if ((x -= d) < 0)
      x += p;
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (a[pos] != x)
      break;
  }
  pans = (x + d) % p;
  cnt = n - 1;
  x = pans;
  while (true) {
    if ((x += d) >= p)
      x -= p;
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (a[pos] == x)
      --cnt;
    else
      break;
  }
  if (cnt == 0)
    return make_pair(pans, d);
  return make_pair(-1, -1);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &p, &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  if (n == p) {
    printf("%d 1\n", 0);
  } else {
    pair<int, int> ans;
    if (n * 2 > p) {
      for (int i = 1; i <= n; ++i)
        vis[a[i]] = true;
      int cnt = 0;
      for (int i = 0; i < p; ++i)
        if (!vis[i])
          a[++cnt] = i;
      memset(vis, 0, sizeof(vis));
      ans = solve(p - n);
      if (ans.first >= 0) {
        ans.first = (ans.first - ans.second + p) % p;
        ans.second = p - ans.second;
      }
    } else {
      ans = solve(n);
    }
    if (ans.first >= 0)
      printf("%d %d\n", ans.first, ans.second);
    else
      puts("-1");
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}