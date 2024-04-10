#include <bits/stdc++.h>
using namespace std;

void change(set<string> has, string &b)
{
  for (int i = 0; i < 4; i++)
    for (char c = '0'; c <= '9'; c++)
    {
      char tmp = b[i];
      b[i] = c;
      if (!has.count(b))
        return;
      b[i] = tmp;
    }

  assert(0);
}

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a)
      cin >> s;

    int ans = n;
    vector<string> ansA;
    for (int mask = 1; mask < 1 << n; mask++)
    {
      int isGood = 1;
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
          if ((mask >> i & 1) && (mask >> j & 1) && a[i] == a[j])
            isGood = 0;

      if (!isGood)
        continue;

      int cost = 0;
      vector<string> b(a);
      set<string> has;
      for (int i = 0; i < n; i++)
        if (mask >> i & 1)
          has.insert(a[i]);

      for (int i = 0; i < n; i++)
        if (mask >> i & 1 ^ 1)
        {
          if (has.count(b[i]))
          {
            cost++;
            change(has, b[i]);
          }

          has.insert(b[i]);
        }

      if (cost < ans)
      {
        ans = cost;
        ansA = b;
      }
    }

    cout << ans << endl;
    for (auto s : ansA)
      cout << s << endl;
  }
}