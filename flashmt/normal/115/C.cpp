#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e6 + 3;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> row(n), col(m);
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] != '.')
      {
        int x = (s[j] <= '2') ^ (j % 2);
        row[i] |= 1 << x;
        int y = (s[j] == '1' || s[j] == '4') ^ (i % 2);
        col[j] |= 1 << y;
      }
  }

  int ans = 1;
  for (int x : row)
    if (x == 3) ans = 0;
    else if (!x) ans = ans * 2 % BASE;
  for (int x : col)
    if (x == 3) ans = 0;
    else if (!x) ans = ans * 2 % BASE;
  cout << ans << endl;
}