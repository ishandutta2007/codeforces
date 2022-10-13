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
    int n, a, b;
    cin >> n >> a >> b;
    int flipped = 0;
    if (a < b)
    {
      swap(a, b);
      flipped = 1;
    }

    if (a == 0)
    {
      for (int i = 1; i <= n; i++)
        cout << i << " \n"[i == n];
      continue;
    }

    int need = a * 2 + 1;
    if (b == a) need++;
    else need += a - 1 - b;
    if (need > n || b < a - 1) cout << -1 << '\n';
    else
    {
      int low = n - need + 1, high = n;
      vector<int> ans;
      if (b == a)
      {
        ans.push_back(high--);
        b--;
      }
      ans.push_back(low++);
      for (int i = 1; i <= a; i++)
      {
        ans.push_back(high--);
        ans.push_back(low++);
      }
      for (int i = n - need; i; i--)
        ans.push_back(i);

      for (int i = 0; i < n; i++)
        if (flipped)
          ans[i] = n + 1 - ans[i];

      for (int x : ans)
        cout << x << ' ';
      cout << '\n';
    }
  }
}