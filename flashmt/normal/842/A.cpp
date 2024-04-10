#include <bits/stdc++.h>
using namespace std;

int main()
{
  int l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  for (int i = x; i <= y; i++)
    if (1LL * i * k >= l && 1LL * i * k <= r)
    {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
}