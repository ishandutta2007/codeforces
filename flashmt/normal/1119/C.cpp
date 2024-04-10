#include <bits/stdc++.h>
using namespace std;

int a[555][555], b[555][555];

int main()
{
  ios::sync_with_stdio(0);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      if (a[i][j] != b[i][j])
      {
        a[i][j] ^= 1;
        a[i][0] ^= 1;
        a[0][j] ^= 1;
        a[0][0] ^= 1;
      }

  int ans = 1;
  for (int i = 0; i < m; i++)
    ans &= (a[i][0] == b[i][0]);
  for (int j = 0; j < n; j++)
    ans &= (a[0][j] == b[0][j]);
  cout << (ans ? "Yes" : "No") << endl;
}