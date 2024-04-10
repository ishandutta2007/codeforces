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
    vector<int> a(n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      b.push_back({a[i] + i, i});
    }

    sort(begin(b), end(b));
    vector<int> flag(n);
    for (int i = 0; i < n - k; i++)
      flag[b[i].second] = 1;

    long long ans = 0;
    for (int i = 0, stacked = 0; i < n; i++)
      if (flag[i]) ans += a[i] + stacked;
      else stacked++;
    cout << ans << '\n';
  }
}