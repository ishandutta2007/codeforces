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
    vector<int> a(n + 1);
    int oddZero = -1;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      a[i] ^= a[i - 1];
      if (i % 2 && !a[i] && oddZero < 0)
        oddZero = i;
    }

    if (a[n] || oddZero < 0) cout << "NO\n";
    else
    {
      vector<int> ans;
      int curOdd = oddZero;
      for (int i = 0; i + 2 < n; i += 2)
      {
        if (i + 1 == curOdd)
        {
          if (curOdd + 2 <= n && a[curOdd + 2])
          {
            a[curOdd + 2] = 0;
            a[curOdd + 1] = a[curOdd + 3];
            ans.push_back(curOdd + 1);
          }
          curOdd += 2;
        }
        if (a[i + 2])
        {
          a[i + 2] = 0;
          a[i + 1] = a[i + 3];
          ans.push_back(i + 1);
        }
      }
      for (int i = oddZero; i > 2; i -= 2)
        if (a[i - 2])
        {
          a[i - 2] = 0;
          ans.push_back(i - 2);
        }

      cout << "YES\n";
      cout << size(ans) << '\n';
      for (int x : ans)
        cout << x << ' ';
      if (!empty(ans))
        cout << '\n';
    }
  }
}