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
    int ans = 1;
    for (int i = 1; i < n * 2; i++)
      if (s[i] == '(' && s[i - 1] == '(')
        ans++;
    cout << ans << '\n';
  }
}