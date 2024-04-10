#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 100010, INF = 1 << 30;

int n, m;
int a[N], x[N], dp[N], tak[N];
bool vis[N];

vector<pair<int, int>> good[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &x[i]);
  sort(x + 1, x + m + 1);
  fill(dp + 1, dp + n + 1, INF);
  int lis = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      int p = m;
      for (int j = lis; j >= 0; --j)
        while (p && x[p] > dp[j])
          dp[j + 1] = x[p--];
    } else {
      int j = lower_bound(dp, dp + lis + 1, a[i]) - dp;
      dp[j] = a[i];
      good[j].emplace_back(a[i], i);
    }

    if (dp[lis + 1] != INF)
      ++lis;
  }
  int j = m;
  int v = INF, id = n + 1;
  for (int i = lis; i; --i) {
    while (!good[i].empty() && (good[i].back().second > id || good[i].back().first >= v)) good[i].pop_back();
    if (good[i].empty()) {
      while (a[--id] != -1);
      while (x[j] >= v) --j;
      v = a[id] = x[j];
      vis[j--] = true;
    } else {
      id = good[i].back().second;
      v = good[i].back().first;
    }
  }
  int p = 1;
  for (int i = 1; i <= n; ++i)
    if (a[i] == -1) {
      while (vis[p]) ++p;
      a[i] = x[p];
      vis[p] = true;
    }
  for (int i = 1; i <= n; ++i)
    printf("%d%c", a[i], " \n"[i == n]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}