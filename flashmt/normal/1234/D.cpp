#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  set<int> a[26];
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    a[s[i] - 'a'].insert(i);

  int q;
  cin >> q;
  while (q--)
  {
    int op, x, y;
    char c;
    cin >> op;
    if (op == 1)
    {
      cin >> x >> c;
      --x;
      a[s[x] - 'a'].erase(x);
      s[x] = c;
      a[s[x] - 'a'].insert(x);
    }
    else
    {
      cin >> x >> y;
      --x;
      --y;
      int ans = 0;
      for (int c = 0; c < 26; c++)
      {
        auto it = a[c].lower_bound(x);
        if (it != a[c].end())
          ans += *it <= y;
      }
      cout << ans << '\n';
    }
  }
}