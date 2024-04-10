// test if clause precedence

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
    vector<string> a(n);
    map<string, int> minId, maxId;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (!minId.count(a[i]))
        minId[a[i]] = i;
      maxId[a[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      string t = a[i];
      reverse(begin(t), end(t));
      if (maxId.count(t) && maxId[t] >= i)
        ans = 1;

      if (size(a[i]) == 3)
      {
        string u;
        u += a[i][1];
        u += a[i][0];
        if (maxId.count(u))
          if (maxId[u] >= i)
            ans = 1;

        u[0] = a[i][2];
        u[1] = a[i][1];
        if (minId.count(u) && minId[u] <= i)
          ans = 1;
      }
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}