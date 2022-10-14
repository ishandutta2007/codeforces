#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = size(s);
  vector<int> pre(n);
  pre[0] = -1;
  for (int i = 0, j = -1; i < n; i++)
  {
    while (j >= 0 && s[i] != s[j])
      j = j ? pre[j - 1] + 1 : -1;
    pre[i] = j++;
  }

  for (int i = 0; i < 10; i++)
  {
    s += ' ';
    pre.push_back(-1);
  }

  int q;
  cin >> q;
  unordered_map<string, int> cache;
  while (q--)
  {
    string t;
    cin >> t;
    int m = size(t);
    for (int i = 0; i < m; i++)
      s[n + i] = t[i];

    string prefix;
    for (int i = n, j = pre[n - 1] + 1; i < n + m; i++)
    {
      prefix += s[i];
      if (cache.contains(prefix))
      {
        pre[i] = cache[prefix];
        j = pre[i] + 1;
      }
      else
      {
        while (j >= 0 && s[i] != s[j])
          j = j ? pre[j - 1] + 1 : -1;
        pre[i] = j++;
        cache[prefix] = pre[i];
      }

      cout << j << ' ';
    }
    cout << '\n';
  }
}