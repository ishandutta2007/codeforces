#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, a[100100], g = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    g = __gcd(g, a[i]);
  }  

  for (int i = 0; i < n; i++)
  {
    a[i] /= g;
    for (int j = 2; j <= 3; j++)
      while (a[i] % j == 0)
        a[i] /= j;

    if (a[i] > 1)
    {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
}