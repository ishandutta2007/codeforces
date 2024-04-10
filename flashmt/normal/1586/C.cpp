#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  vector<int> bad(n);
  for (int j = 1; j < n; j++)
    for (int i = 1; i < m; i++)
      if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X')
        bad[j] = 1;

  for (int i = 1; i < n; i++)
    bad[i] += bad[i - 1];

  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << (bad[--r] == bad[--l] ? "YES" : "NO") << '\n';
  }
}