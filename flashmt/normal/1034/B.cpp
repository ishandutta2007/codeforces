#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n;
  cin >> m >> n;
  if (m > n)
    swap(m, n);

  if (m >= 3) cout << 1LL * m * n - (m % 2 * n % 2) << endl;
  else if (m == 2)
  {
    if (n == 2) cout << 0 << endl;
    else if (n == 3 || n == 7) cout << 1LL * m * n - 2 << endl;
    else cout << 1LL * m * n << endl;
  }
  else cout << n / 6 * 6 + max(0, n % 6 - 3) * 2 << endl;
}