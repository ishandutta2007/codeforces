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
    cin >> n;
    vector<long long> a(n);
    int p2 = 0;
    long long sumA = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      while (a[i] % 2 == 0)
      {
        a[i] /= 2;
        p2++;
      }
      sumA += a[i];
    }

    long long ans = 0;
    for (auto x : a)
      ans = max(ans, sumA - x + (x << p2));
    cout << ans << '\n';
  }
}