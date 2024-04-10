#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int A = 1e9;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, x;
    cin >> n >> x;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
      int y;
      cin >> y;
      cnt[y]++;
    }

    int ans = 0;
    for (auto [k, v] : cnt)
      if (!v) continue;
      else if (k % x == 0 && cnt.count(k / x))
      {
        int use = min(v, cnt[k / x]);
        cnt[k] -= use;
        ans += use;
      }

    cout << n - ans * 2 << '\n';
  }
}