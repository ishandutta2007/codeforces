#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, a[200200];
long long f[200200][2][3][2];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 3; k++)
        for (int p = 0; p < 2; p++)
          f[i][j][k][p] = -oo;

  f[0][0][0][0] = -a[0];
  f[0][1][1][0] = a[0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < 2; j++) // last sign
      for (int mod = 0; mod < 3; mod++) // positive count % 3
        for (int hasEqual = 0; hasEqual < 2; hasEqual++) // has equal consecutive signs
        {
          f[i][0][mod][hasEqual | (!j)] = max(f[i][0][mod][hasEqual | (!j)], f[i - 1][j][mod][hasEqual] - a[i]);
          f[i][1][(mod + 1) % 3][hasEqual | j] = max(f[i][1][(mod + 1) % 3][hasEqual | j], f[i - 1][j][mod][hasEqual] + a[i]);
        }

  int mod = (5 - n % 3) % 3;
  cout << max(f[n - 1][0][mod][n > 1], f[n - 1][1][mod][n > 1]) << endl;
}