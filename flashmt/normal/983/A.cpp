#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  long long p, q, b;
  cin >> n;
  while (n--)
  {
    cin >> p >> q >> b;
    q /= __gcd(p, q);
    while (1)
    {
      long long g = __gcd(q, b);
      if (g == 1)
        break;
      while (q % g == 0)
        q /= g;
      b = g;
    }
    cout << (q == 1 ? "Finite" : "Infinite") << '\n';
  }
}