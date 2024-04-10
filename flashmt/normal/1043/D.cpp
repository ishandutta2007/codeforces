#include <bits/stdc++.h>
using namespace std;

int n, m, a[11][100100], id[11][100100];

int isGood(int jj)
{
  int current = a[0][jj], last = a[0][jj - 1];
  for (int i = 0; i < m; i++)
    if (id[i][current] - id[i][last] != 1)
      return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      id[i][a[i][j]] = j;
    }

  long long ans = 0;
  for (int j = 0; j < n;)
  {
    int jj = j + 1;
    while (jj < n && isGood(jj))
      jj++;
    ans += (jj - j) * (jj - j + 1LL) / 2;
    j = jj;
  }
  cout << ans << endl;
}