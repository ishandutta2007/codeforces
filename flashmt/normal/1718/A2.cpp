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
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    int ans = n;
    set<int> s = {0};
    for (int i = 0, sumXor = 0; i < n; i++)
    {
      sumXor ^= a[i];
      if (s.count(sumXor))
      {
        ans--;
        s = {0};
        sumXor = 0;
      }
      else s.insert(sumXor);
    }

    cout << ans << endl;
  }
}