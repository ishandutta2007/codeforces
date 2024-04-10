#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int a, b, c, d, k, found = 0;
    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i <= k; i++)
      if (i * c >= a && (k - i) * d >= b)
      {
        cout << i << ' ' << k - i << endl;
        found = 1;
        break;
      }
    if (!found)
      cout << -1 << endl;
  }
}