#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, y = 1;
  cin >> n;
  while (n--)
  {
    int x;
    cin >> x;
    if (x % 2 == 0) cout << x / 2 << '\n';
    else
    {
      cout << (x + y) / 2 << '\n';
      y = -y;
    }
  }
}