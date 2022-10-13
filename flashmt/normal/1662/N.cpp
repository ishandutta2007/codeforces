#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> pos(n * n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      pos[--x] = {i, j};
    }

  long long ans = 0;
  vector<int> row(n), col(n);
  for (auto [i, j] : pos)
  {
    ans += row[i] * (n - 1 - col[j]) + col[j] * (n - 1 - row[i]);
    row[i]++;
    col[j]++;
  }
  cout << ans / 2 << endl;
}