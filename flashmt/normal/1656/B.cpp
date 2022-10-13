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
    int n, k;
    cin >> n >> k;
    set<int> s;
    while (n--)
    {
      int x;
      cin >> x;
      s.insert(x);
    }

    int ans = 0;
    for (int x : s)
      if (s.count(x + k))
        ans = 1;
    cout << (ans ? "YES" : "NO") << '\n';
  }
}