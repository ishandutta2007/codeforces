#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x, a[111][111];
  string s;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    for (int j = 1; j <= n; j++)
      if (s[j - 1] == '1') a[i][j] = 1;
      else a[i][j] = i == j ? 0 : oo;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

  cin >> m;
  vector<int> ans;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    int len = ans.size();
    while (len >= 2 && a[ans[len - 2]][x] == a[ans[len - 2]][ans[len - 1]] + a[ans[len - 1]][x])
    {
      len--;
      ans.pop_back();
    }
    ans.push_back(x);
  }

  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x << ' ';
}