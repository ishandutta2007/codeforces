#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b)
      swap(a, b);
    if (c - r >= b || c + r <= a) cout << b - a << endl;
    else cout << min(max(0, c - r - a), b - a) + max(0, b - c - r) << endl;
  }
}