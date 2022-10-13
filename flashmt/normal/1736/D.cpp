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
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s;
    cin >> n >> s;

    int sum = 0;
    for (char c : s)
      sum += c - '0';
    if (sum % 2)
    {
      cout << "-1\n";
      continue;
    }

    vector<int> rotatedIds;
    for (int i = 0, cur = 0; i < n * 2; i += 2)
      if (s[i] != s[i + 1])
      {
        if (s[i] - '0' == cur) rotatedIds.push_back(i);
        else rotatedIds.push_back(i + 1);
        cur ^= 1;
      }

    cout << size(rotatedIds);
    for (int x : rotatedIds)
      cout << ' ' << x + 1;
    cout << '\n';
    for (int i = 1; i <= n; i++)
      cout << i * 2 << ' ';
    cout << '\n';
  }
}