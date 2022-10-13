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
    int n;
    cin >> n;
    vector<vector<int>> a(2);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[x % 2].push_back(i);
    }

    auto calc = [&](int x)
    {
      long long res = 0;
      int cur[2] = {0};
      for (int i = 0; i < n; i++)
      {
        int id = a[x][cur[x]++];
        if (id > i)
          res += id - i;
        x ^= 1;
      }
      return res;
    };

    if (n % 2 == 0)
    {
      if (size(a[0]) != size(a[1])) cout << -1 << '\n';
      else cout << min(calc(0), calc(1)) << '\n';
    }
    else
    {
      if (size(a[0]) == n / 2) cout << calc(1) << '\n';
      else if (size(a[1]) == n / 2) cout << calc(0) << '\n';
      else cout << -1 << '\n';
    }
  }
}