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
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    int cntA = 0, cntB = 0;
    for (char c : s)
      if (c == 'A') cntA++;
      else cntB++;

    if (cntA != a + c + d || cntB != b + c + d)
    {
      cout << "NO\n";
      continue;
    }

    vector<vector<vector<int>>> seg(2, vector<vector<int>>(2));
    int n = size(s), free = 0;
    vector<int> ab, ba;
    for (int i = 0; i < n;)
    {
      int j = i + 1;
      while (j < n && s[j] != s[j - 1])
        j++;

      int len = j - i;
      if (len > 1)
      {
        if (s[i] == s[j - 1]) free += len / 2;
        else if (s[i] == 'A') ab.push_back(len / 2);
        else ba.push_back(len / 2);
      }

      i = j;
    }

    sort(begin(ab), end(ab));
    for (int x : ab)
      if (x <= c) c -= x;
      else
      {
        x -= c;
        c = 0;
        d -= x - 1;
      }

    int use = min(free, c);
    c -= use;
    free -= use;

    sort(rbegin(ba), rend(ba));
    for (int x : ba)
      if (x == 1) d--;
      else if (c <= 0) d -= x;
      else if (x - 1 <= c) c -= x - 1;
      else
      {
        x -= c;
        c = 0;
        d -= x - 1;
      }

    c = max(c, 0);
    d = max(d, 0);
    cout << (c + d <= free ? "YES\n" : "NO\n");
  }
}