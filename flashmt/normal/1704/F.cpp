#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const string C = "RB";

int g[500500];

int win(int x)
{
  if (x % 34 == 33)
    return g[x] = 7;
  if (x % 34 == 1 && x >= 69)
    return g[x] = 8;
  if (x % 34 == 18 && x >= 86)
    return g[x] = 9;
  if (g[x] >= 0)
    return g[x];

  g[x] = 0;
  vector<int> has(7);
  int cnt = 0;
  for (int i = 1; i * 2 <= min(x, 100); i++)
  {
    int cur = win(i - 1) ^ win(x - i - 1);
    if (cur <= 5 && !has[cur])
    {
      has[cur] = 1;
      cnt++;
      if (cnt == 5)
        break;
    }
  }

  while (has[g[x]])
    g[x]++;
  return g[x];
}

int main()
{
  memset(g, -1, sizeof g);
  g[0] = g[1] = 0;
  for (int i = 2; i <= 500000; i++)
    win(i);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s;
    cin >> n >> s;
    int b = 0, r = 0;
    for (char c : s)
      if (c == 'B') b++;
      else r++;

    int ans = 0;
    for (int i = 0; i < n;)
    {
      int j = i + 1;
      while (j < n && s[j] != s[j - 1])
        j++;
      ans ^= win(j - i);
      i = j;
    }

    if (r != b) cout << (r > b ? "Alice" : "Bob") << '\n';
    else cout << (ans ? "Alice" : "Bob") << '\n';
  }
}