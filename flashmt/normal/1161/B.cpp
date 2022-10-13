#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set <int> a[100100];

int isGood(int k)
{
  for (int dif = 1; dif <= n / 2; dif++)
    for (int x : a[dif])
      if (!a[dif].count((x + k) % n))
        return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  int m, x, y;
  cin >> n >> m;
  while (m--)
  {
    cin >> x >> y;
    x--;
    y--;
    int dif = (y + n - x) % n;
    if (dif > n / 2) a[n - dif].insert(y);
    else 
    {
      a[dif].insert(x);
      if (dif * 2 == n)
        a[dif].insert(y);
    }
  }

  for (int k = 1; k * k <= n; k++)
    if (n % k == 0)
      if (isGood(k) || (k > 1 && isGood(n / k)))
      {
        cout << "Yes" << endl;
        return 0;
      }

  cout << "No" << endl;
}