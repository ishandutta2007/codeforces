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
    int n;
    string s;
    cin >> n >> s;
    int i = 0, op = 0;
    while (i < n - 1)
      if (s[i] == '(')
      {
        op++;
        i += 2;
      }
      else
      {
        int j = i + 1;
        while (j < n && s[j] != ')')
          j++;
        if (j == n)
          break;
        op++;
        i = j + 1;
      }

    cout << op << ' ' << n - i << '\n';
  }
}