#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    cin >> m >> n;
    vector<int> a(m * n);
    for (int i = 0; i < m * n; i++)
      cin >> a[i];

    vector<int> id(m * n);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int u, int v) { return make_pair(a[u], u) < make_pair(a[v], v); });

    vector<int> atSeat(m * n);
    int curSeat = 0;
    for (int i = 0; i < m * n;)
    {
      int ii = i + 1;
      while (ii < m * n && a[id[ii]] == a[id[i]])
        ii++;
      int sz = ii - i;
      int lastSeat = curSeat + sz - 1;
      int firstRow = curSeat / n, lastRow = lastSeat / n;
      for (int row = firstRow; row <= lastRow; row++)
      {
        int numSeat = min(row * n + n - 1, lastSeat) - curSeat + 1;
        for (int j = numSeat - 1; j >= 0; j--)
          atSeat[curSeat++] = id[i + j];
        i += numSeat;
      }
      i = ii;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (int jj = j + 1; jj < n; jj++)
          ans += atSeat[i * n + j] < atSeat[i * n + jj];

    cout << ans << '\n';
  }
}