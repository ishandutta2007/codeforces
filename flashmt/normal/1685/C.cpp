#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int isGood(string s)
{
  int x = 0;
  for (char c : s)
  {
    if (c == '(') x++;
    else x--;
    if (x < 0)
      return 0;
  }
  return 1;
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
    string s;
    cin >> n >> s;
    vector<int> a(n * 2 + 1);
    for (int i = 0; i < n * 2; i++)
      a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);

    int minA = *min_element(begin(a), end(a));
    int maxId = max_element(begin(a), end(a)) - begin(a);

    if (!minA) cout << "0\n";
    else if (!a[maxId])
    {
      cout << "1\n";
      cout << 1 << ' ' << n * 2 << '\n';
    }
    else
    {
      // check if we can do 1 op
      {
        int l = 0;
        for (int i = 1; i < n * 2; i++)
          if (a[i] < 0) break;
          else if (a[i] > a[l]) l = i;
        int r = n * 2;
        for (int i = n * 2 - 1; i >= 0; i--)
          if (a[i] < 0) break;
          else if (a[i] > a[r]) r = i;

        string t = s;
        reverse(t.begin() + l, t.begin() + r);
        if (isGood(t))
        {
          cout << "1\n";
          cout << l + 1 << ' ' << r << '\n';
          continue;
        }
      }

      // 2 ops
      vector<pair<int, int>> ans;
      for (int i = 0; i < maxId; i++)
        if (a[i] < 0)
        {
          ans.push_back({0, maxId});
          break;
        }

      for (int i = maxId + 1; i < n * 2; i++)
        if (a[i] < 0)
        {
          ans.push_back({maxId, n * 2});
          break;
        }

      for (auto [l, r] : ans)
        reverse(s.begin() + l, s.begin() + r);
      assert(isGood(s));

      cout << size(ans) << '\n';
      for (auto [l, r] : ans)
        cout << l + 1 << ' ' << r << '\n';
    }
  }
}