#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a;
  if (m)
  {
    a = {1, 2};
    for (int i = 3; i <= n; i++)
      if (m > (i - 1) / 2)
      {
        m -= (i - 1) / 2;
        a.push_back(i);
      }
      else
      {
        a.push_back(i + ((i - 1) / 2 - m) * 2);
        n -= i;
        m = 0;
        break;
      }

    if (m)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  int maxA = empty(a) ? 1 : a.back() + 1;
  for (int i = 0; i < n; i++)
    a.push_back(27081993 + i * maxA);

  for (int x : a)
    cout << x << ' ';
}