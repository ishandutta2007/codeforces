#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    long long x, y;
    cin >> x >> y;
    if (x > y) cout << x + y << '\n';
    else
    {
      x = y / x * x;
      cout << (x + y) / 2 << '\n';
    }
  }
}