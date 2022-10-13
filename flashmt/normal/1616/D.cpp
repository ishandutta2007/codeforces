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
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i++)
      a[i] -= x;

    int ans = n;
    long long sum = 0;
    for (int i = 0, cnt = 0; i < n; i++)
    {
      if (cnt >= 1 && sum + a[i] < 0)
      {
        ans--;
        sum = cnt = 0;
      }
      else if (sum < 0)
      {
        sum += a[i];
        cnt++;
      }
      else
      {
        sum = a[i];
        cnt = 1;
      }
    }

    cout << ans << '\n';
  }
}