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
    int n, m;
    string a;
    cin >> n >> m >> a;
    while (m--)
    {
      int changed = 0;
      string b = a;
      for (int i = 0; i < n; i++)
        if (b[i] == '0')
        {
          int alive = 0;
          if (i && a[i - 1] == '1')
            alive++;
          if (i + 1 < n && a[i + 1] == '1')
            alive++;
          if (alive == 1)
          {
            b[i] = '1';
            changed = 1;
          }
        }

      a = b;
      if (!changed)
        break;
    }
    cout << a << '\n';
  }
}