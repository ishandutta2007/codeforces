#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, c[111], b[111], q, x[100100], sumB[111];
long long f[111][10100];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n - 1; i++)
  {
    cin >> b[i];
    if (i)
      b[i] += b[i - 1];
    sumB[i] = b[i];
    if (i)
      sumB[i] += sumB[i - 1];
  }
  cin >> q;
  for (int i = 0; i < q; i++)
    cin >> x[i];

  for (int i = max(0, x[0]); i <= c[0]; i++)
    f[0][i] = 1;

  for (int i = 1; i < n; i++)
    for (int sum = 0 ; sum <= i * 100; sum++)
      if (f[i - 1][sum])
        for (int j = 0; j <= c[i]; j++)
        {
          int newSum = sum + j;
          if (newSum >= x[0] * (i + 1) + sumB[i - 1])
            f[i][newSum] = (f[i][newSum] + f[i - 1][sum]) % BASE;
        }

  long long ans = 0;
  for (int i = 0; i <= n * 100; i++)
    ans = (ans + f[n - 1][i]) % BASE;
  cout << ans << endl;
}