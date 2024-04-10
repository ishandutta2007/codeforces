#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 5e5 + 5;

int n, sz[N], cnt[N][2];
vector<pair<int, int>> a[N];
long long ans;

void dfs(int x, int par = -1)
{
  sz[x] = 1;
  for (auto [y, v] : a[x])
    if (y != par)
    {
      int curCnt0 = cnt[v][0], curCnt1 = cnt[v][1];
      dfs(y, x);
      ans += 1LL * (sz[y] - (cnt[v][0] - curCnt0)) * ((cnt[v][0] - curCnt0) - (cnt[v][1] - curCnt1));
      cnt[v][1] = curCnt1 + cnt[v][0] - curCnt0;
      cnt[v][0] = curCnt0 + sz[y];
      sz[x] += sz[y];
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int x, y, v;
    cin >> x >> y >> v;
    a[--x].push_back({--y, --v});
    a[y].push_back({x, v});
  }

  dfs(0);
  for (int i = 0; i < n; i++)
    ans += 1LL * (n - cnt[i][0]) * (cnt[i][0] - cnt[i][1]);
  cout << ans << endl;
}