#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, a[5050];
long long f[5050][5050], sumF[5050][5050];

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);

  for (int i = 1, bound = 0; i <= n; i++)
  {
    while (a[bound + 1] * 2 <= a[i])
      bound++;
    f[i][1] = 1;
    sumF[i][1] = i;
    for (int j = 2; j <= bound + 1; j++)
    {
      int choices = bound + 1 - (j - 1);
      f[i][j] = (f[i][j - 1] * choices + sumF[bound][j - 1]) % BASE;
      sumF[i][j] = (sumF[i - 1][j] + f[i][j]) % BASE;
    }
  }

  cout << f[n][n] << endl;
}