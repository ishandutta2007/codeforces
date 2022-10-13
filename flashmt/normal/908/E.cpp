#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> masks(m);
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] == '1')
        masks[j] |= 1LL << i;
  }

  map<long long, int> cnt;
  for (auto mask : masks)
    cnt[mask]++;

  vector<vector<long long>> f(m + 1, vector<long long>(m + 1));
  vector<long long> bells(m + 1);
  f[0][0] = bells[0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= i; j++)
    {
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j) % BASE;
      bells[i] = (bells[i] + f[i][j]) % BASE;
    }

  long long ans = 1;
  for (auto [_, c] : cnt)
    ans = ans * bells[c] % BASE;
  cout << ans << endl;
}