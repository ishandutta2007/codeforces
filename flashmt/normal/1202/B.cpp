#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int ans[10][10] = {0};
  for (int x = 0; x < 10; x++)
    for (int y = x; y < 10; y++)
    {
      int dist[10][10];
      for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
          dist[i][j] = oo;

      for (int i = 0; i < 10; i++)
        dist[i][(i + x) % 10] = dist[i][(i + y) % 10] = 1;

      for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
          for (int j = 0; j < 10; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

      for (int i = 1; i < s.size(); i++)
        if (dist[s[i - 1] - '0'][s[i] - '0'] == oo)
        {
          ans[x][y] = -1;
          break;
        }
        else ans[x][y] += dist[s[i - 1] - '0'][s[i] - '0'] - 1;
    }

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      cout << (i > j ? ans[j][i] : ans[i][j]) << " \n"[j == 9];
}