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
    vector<string> a(m, string(n, '0'));
    for (int j = 0; j < n; j += 2)
      a[0][j] = '1';
    for (int i = 2; i < m; i += 2)
      a[i][0] = a[i][n - 1] = '1';
    for (int j = 2; j < n - 2; j += 2)
      a[m - 1][j] = '1';

    for (int i = 0; i < m; i++)
      cout << a[i] << '\n';
    cout << '\n';
  }
}