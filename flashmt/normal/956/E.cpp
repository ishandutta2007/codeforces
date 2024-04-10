#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 10010;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int u, int v) { return b[u] < b[v] || (b[u] == b[v] && a[u] > a[v]); });

  vector<vector<int>> f(A, vector<int>(2, -1));
  f[0][0] = 0;
  int sum = 0;
  for (int i : id)
  {
    for (int j = sum; j >= 0; j--)
      for (int k : {1, 0})
        if (f[j][k] >= 0)
        {
          if (!b[i]) f[j + a[i]][k] = 0;
          else
          {
            f[j + a[i]][k] = max(f[j + a[i]][k], f[j][k] + (l <= j && j <= r));
            if (!k)
              f[j][k + 1] = max(f[j][k + 1], f[j][k]);
          }
        }

    sum += a[i];
  }

  int ans = 0;
  for (int i = 0; i < A; i++)
  {
    ans = max(ans, f[i][0]);
    if (l <= i && i <= r)
      ans = max(ans, f[i][1] + 1);
  }
  cout << ans << endl;
}