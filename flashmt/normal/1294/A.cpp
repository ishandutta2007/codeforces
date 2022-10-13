#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, a[3], n;
  cin >> t;
  while (t--)
  {
    for (int i = 0; i < 3; i++)
      cin >> a[i];
    cin >> n;
    sort(a, a + 3);
    n -= a[2] * 2 - a[1] - a[0];
    cout << (n >= 0 && n % 3 == 0 ? "YES\n" : "NO\n");
  }
}