#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 5, vector<int>(n + 5));
    vector<vector<int>> s(n + 5, vector<int>(n + 5));
    vector<vector<int>> d0(n + 5, vector<int>(n + 5));
    vector<vector<int>> d1(n + 5, vector<int>(n + 5));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
        cin >> a[i][j];
        s[i][j] = s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1] ^ a[i][j];
        d0[i][j] = d0[i - 1][j - 1] ^ a[i][j];
        d1[i][j] = d1[i - 1][j + 1] ^ a[i][j];
      }

    int ans = 0, lastEdge = 0;
    for (int i = 1, ii = n; i < ii; i++, ii--)
    {
      int rect = s[i - 1][i - 1] ^ s[i - 1][ii] ^ s[ii][i - 1] ^ s[ii][ii];
      int edge = rect ^ lastEdge;
      int topLeftBotRight = 0;
      for (int x = i, y = i + 1; x < ii; x++, y++)
        topLeftBotRight ^= d1[x][y] ^ d1[x - i][y + i];
      int topRightBotLeft = 0;
      for (int x = i, y = ii - 1; x < ii; x++, y--)
        topRightBotLeft ^= d0[x][y] ^ d0[x - i][y - i];

      ans ^= edge ^ topLeftBotRight ^ topRightBotLeft;
      lastEdge = edge;
    }

    cout << ans << '\n';
  }
}