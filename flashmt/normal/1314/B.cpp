#include <bits/stdc++.h>
using namespace std;

int f[17][1 << 17][2][2];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (!k)
  {
    cout << 0 << endl;
    return 0;
  }

  vector<int> has(1 << n);
  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    has[x - 1] = 1;
  }

  memset(f, -1, sizeof f);
  for (int i = 0; i < 1 << n - 1; i++)
    if (has[i * 2] && has[i * 2 + 1]) f[n - 1][i][1][1] = 1;
    else if (has[i * 2] || has[i * 2 + 1]) f[n - 1][i][0][1] = f[n - 1][i][1][0] = 1;
    else f[n - 1][i][0][0] = 0;

  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j < 1 << i; j++)
    {
      int x = j * 2, y = x + 1;
      for (int ux = 0; ux < 2; ux++) // upper x
        for (int lx = 0; lx < 2; lx++) // lower x
          for (int uy = 0; uy < 2; uy++) // upper y
            for (int ly = 0; ly < 2; ly++) // lower y
            {
              if (f[i + 1][x][ux][lx] < 0 || f[i + 1][y][uy][ly] < 0)
                continue;

              int curF = f[i + 1][x][ux][lx] + f[i + 1][y][uy][ly] + (ux | uy) + (lx | ly);

              // ux wins upper
              int maxLower = max({uy, lx, ly});
              f[i][j][ux][maxLower] = max(f[i][j][ux][maxLower], curF + maxLower);

              // uy wins upper
              maxLower = max({ux, lx, ly});
              f[i][j][uy][maxLower] = max(f[i][j][uy][maxLower], curF + maxLower);
            }
    }

  int ans = 0;
  for (int u = 0; u < 2; u++)
    for (int l = 0; l < 2; l++)
      ans = max(ans, f[0][0][u][l] + (u | l));
  cout << ans << endl;
}