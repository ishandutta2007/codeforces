#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  pair<int, int> antennas[88];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> antennas[i].first >> antennas[i].second;

  sort(antennas, antennas + n);
  vector<int> f(m + 1, m);
  f[0] = 0;
  for (int i = 0; i < n; i++)
  {
    auto [x, s] = antennas[i];
    for (int j = m - 1; j >= 0; j--)
    {
      int inc = max(0, x - s - j - 1);
      int jj = min(x + s + inc, m);
      f[jj] = min(f[jj], f[j] + inc);
    }
  }

  int ans = m;
  for (int i = 0; i <= m; i++)
    ans = min(ans, f[i] + m - i);
  cout << ans << endl;
}