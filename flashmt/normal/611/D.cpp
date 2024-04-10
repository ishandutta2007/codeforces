#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n;
string s;
int f[5050][5050], lcp[5050][5050];

int find(int x, int y)
{
  int len = y - x + 1, u = y + 1, v = u + len - 1;
  if (v >= n || s[u] == '0')
    return -1;
  return lcp[x][u] < len && s[x + lcp[x][u]] < s[u + lcp[x][u]] ? v : v + 1;
}

int main()
{
  cin >> n >> s;

  for (int i = n - 1; i >= 0; i--)
    for (int j = i + 1; j < n; j++)
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      else lcp[i][j] = 0;

  f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
    {
      if (j)
        f[i][j] = (f[i][j] + f[i][j - 1]) % BASE;
      int k = find(i, j);
      if (k >= 0 && k < n)
        f[j + 1][k] = (f[j + 1][k] + f[i][j]) % BASE;
    }

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans = (ans + f[i][n - 1]) % BASE;
  cout << ans << endl;
}