#include <bits/stdc++.h>
using namespace std;

int d[100100], l[100100], r[100100];

int get(int x)
{
  return x == d[x] ? x : d[x] = get(d[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      d[i] = i;
      r[i] = i + 1;
      l[i] = i - 1;
    }
    r[0] = 1;
    l[n + 1] = n;

    vector<int> ans;
    while (ans.size() < n)
    {
      int x = r[0], found = 0;
      while (x <= n)
      {
        x = get(x);
        int y = r[x];
        if (y > n)
        {
          y = r[0];

          if (__gcd(a[x], a[y]) == 1)
          {
            ans.push_back(y);
            found = 1;
            r[0] = r[y];
            l[r[y]] = 0;
          }

          break;
        }

        if (__gcd(a[x], a[y]) == 1)
        {
          ans.push_back(y);
          found = 1;
          r[x] = r[y];
          l[r[y]] = x;
          x = r[x];
        }
        else
        {
          int dy = get(y);
          x = d[x] = dy;
        }
      }

      if (!found)
        break;
    }

    cout << ans.size() << ' ';
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}