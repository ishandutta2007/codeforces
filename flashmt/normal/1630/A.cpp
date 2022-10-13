#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
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
    vector<int> flag(n);

    auto write = [&](int x, int y)
    {
      cout << x << ' ' << y << '\n';
      flag[x] = flag[y] = 1;
    };

    if (k < n - 1)
    {
      write(k, n - 1);
      if (k)
        write(0, n - 1 - k);
      for (int i = 0; i < n / 2; i++)
        if (!flag[i])
          write(i, n - 1 - i);
    }
    else if (n == 4) cout << "-1\n";
    else
    {
      write(n - 2, n - 1);
      write(1, 3);
      write(0, n - 4);
      for (int i = 2; i < n / 2; i++)
        if (!flag[i])
          write(i, n - 1 - i);
    }
  }
}