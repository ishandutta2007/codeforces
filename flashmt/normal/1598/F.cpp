#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int Z = 400000;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n), minV(n, oo);
  vector<vector<int>> cnt(n, vector<int>(Z * 2 + 5));
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (char c : s)
    {
      if (c == '(') v[i]++;
      else v[i]--;
      minV[i] = min(minV[i], v[i]);
      if (v[i] <= minV[i])
        cnt[i][v[i] + Z]++;
    }
  }

  int ans = 0;
  vector<int> f(1 << n, -1), sumV(1 << n);
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, cnt[i][Z]);
    if (minV[i] >= 0)
    {
      f[1 << i] = cnt[i][Z];
      sumV[1 << i] = v[i];
    }
  }

  for (int mask = 1; mask < 1 << n; mask++)
    if (f[mask] >= 0)
      for (int i = 0; i < n; i++)
        if ((mask >> i & 1) == 0)
        {
          ans = max(ans, f[mask] + cnt[i][-sumV[mask] + Z]);
          if (sumV[mask] + minV[i] < 0)
            continue;

          int newMask = mask | 1 << i;
          f[newMask] = max(f[newMask], f[mask] + cnt[i][-sumV[mask] + Z]);
          sumV[newMask] = sumV[mask] + v[i];
        }

  cout << ans << endl;
}