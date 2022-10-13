#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  vector<int> len(n), leaf(n, -1), leaves;
  function<void(int, int)> dfs = [&](int x, int par)
  {
    if (size(a[x]) == 1 && par >= 0)
    {
      leaf[x] = x;
      len[x] = 1;
      leaves.push_back(x);
      return;
    }

    for (int y : a[x])
      if (y != par)
      {
        dfs(y, x);
        if (leaf[x] < 0 || len[leaf[y]] > len[leaf[x]])
          leaf[x] = leaf[y];
      }

    len[leaf[x]]++;
  };

  dfs(0, -1);
  long long ans = -oo;
  if (size(leaves) <= k)
  {
    for (int i = size(leaves); i <= k; i++)
      ans = max(ans, 1LL * i * (n - i));
  }
  else
  {
    sort(begin(leaves), end(leaves), [&](int u, int v) { return len[u] > len[v]; });
    int maxBlue = n;
    for (int i = 1; i <= k; i++)
    {
      maxBlue -= len[leaves[i - 1]];
      long long ansBlue = 1LL * (n - i - maxBlue) * (i - maxBlue);
      if (n / 2 <= maxBlue)
        ansBlue = min(ansBlue, 1LL * (n - i - n / 2) * (i - n / 2));
      ans = max(ans, ansBlue);
    }
  }

  cout << ans << endl;
}