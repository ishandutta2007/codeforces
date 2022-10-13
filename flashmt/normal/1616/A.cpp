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
    vector<int> cnt(111);
    cin >> n;
    while (n--)
    {
      int x;
      cin >> x;
      cnt[abs(x)]++;
    }

    int ans = min(1, cnt[0]);
    for (int i = 1; i <= 100; i++)
      ans += min(2, cnt[i]);
    cout << ans << '\n';
  }
}