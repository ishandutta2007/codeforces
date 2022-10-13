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
    int n, costRow, costCol, a[111];
    cin >> n >> costRow >> costCol;
    set<int> allA;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      allA.insert(a[i]);
    }

    if (allA.size() == 1)
    {
      cout << costCol + min(costCol, costRow) << '\n';
      continue;
    }

    int canGo = 0;
    for (int i = 2; i <= n; i++)
      if (abs(a[i] - a[i - 1]) > 1)
      {
        canGo = 1;
        break;
      }

    cout << (canGo ? 0 : min(costCol, costRow)) << '\n';
  }
}