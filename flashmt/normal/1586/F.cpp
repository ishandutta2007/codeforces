#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  int maxC = 1;

  function<void(int, int, int)> go = [&](int l, int r, int c)
  {
    if (r - l <= 1)
      return;

    maxC = max(maxC, c);
    int block = (r - l) / k, rem = (r - l) % k;
    for (int i = 0; i < k; i++)
    {
      int ll = l + block;
      if (i < rem)
        ll++;

      for (int j = l; j < ll; j++)
        for (int jj = ll; jj < r; jj++)
          a[j][jj] = c;

      go(l, ll, c + 1);
      l = ll;
    }
  };

  go(0, n, 1);
  cout << maxC << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      cout << a[i][j] << ' ';
}