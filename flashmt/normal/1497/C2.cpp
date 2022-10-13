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
    int n, k;
    cin >> n >> k;
    while (k > 3)
    {
      cout << 1 << ' ';
      k--;
      n--;
    }
    int x = n / 4;
    if (n % 4 == 0) cout << x * 2 << ' ' << x << ' ' << x << '\n';
    else if (n % 4 == 1) cout << x * 2 << ' ' << x * 2 << ' ' << 1 << '\n';
    else if (n % 4 == 2) cout << x * 2 << ' ' << x * 2 << ' ' << 2 << '\n';
    else cout << (x * 2 + 1) << ' ' << (x * 2 + 1) << ' ' << 1 << '\n';
  }
}