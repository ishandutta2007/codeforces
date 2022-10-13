#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)1e18;

long long f[11][66][1 << 10][11];

long long calc(int b, long long n)
{
  if (!n)
    return 0;
  int digits[66], len = 0;
  while (n)
  {
    digits[++len] = n % b;
    n /= b;
  }

  long long res = 0;
  int mask = 0;
  for (int i = 1; i < len; i++)
    for (int x = 1; x < b; x++)
      res += f[b][i][0][x];

  for (int i = len; i; i--)
  {
    for (int x = (i == len ? 1 : 0); x < digits[i]; x++)
      res += f[b][i][mask][x];
    mask ^= 1 << digits[i];
  }

  if (!mask)
    res++;
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int b = 2; b <= 10; b++)
  {
    for (int i = 0; i < b; i++)
      f[b][1][1 << i][i] = 1;
    long long maxVal = b;
    for (int i = 2; maxVal < MAX; i++)
    {
      maxVal *= b;
      for (int mask = 0; mask < 1 << b; mask++)
        for (int x = 0; x < b; x++)
          for (int y = 0; y < b; y++)
            f[b][i][mask ^ 1 << x][x] += f[b][i - 1][mask][y];
    }

  }

  int q, b;
  long long x, y;
  cin >> q;
  while (q--)
  {
    cin >> b >> x >> y;
    cout << calc(b, y) - calc(b, x - 1) << '\n';
  }
}