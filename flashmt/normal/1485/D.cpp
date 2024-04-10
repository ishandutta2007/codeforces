#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int lcm = 1;
  for (int i = 2; i <= 16; i++)
    lcm = lcm / __gcd(lcm, i) * i;

  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int x, p = 1;
      cin >> x;
      for (int k = 0; k < 4; k++)
        p *= x;
      cout << lcm + (i + j) % 2 * p << " \n"[j == n - 1];
    }
}