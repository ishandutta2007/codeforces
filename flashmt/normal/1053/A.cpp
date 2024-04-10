#include <bits/stdc++.h>
using namespace std;

void answer(int x, int y)
{
  cout << "YES" << endl;
  cout << 0 << ' ' << 0 << endl;
  cout << 0 << ' ' << y << endl;
  cout << x << ' ' << 0 << endl;
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n, m, k;
  cin >> m >> n >> k;

  long long g = __gcd(n * m, k);
  k /= g;
  if (k > 2)
  {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 1; i * i <= g; i++)
    if (g % i == 0)
    {
      int j = g / i;
      if (m % i == 0 && n % j == 0)
      {
        int x = m / i, y = n / j;
        if (x * 2 / k <= m) answer(x * 2 / k, y);
        else if (y * 2 / k <= n) answer(x, y * 2 / k);
      }
      if (m % j == 0 && n % i == 0)
      {
        int x = m / j, y = n / i;
        if (x * 2 / k <= m) answer(x * 2 / k, y);
        else if (y * 2 / k <= n) answer(x, y * 2 / k);
      }
    }

  assert(0);
}