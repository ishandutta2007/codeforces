#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  long long ans = 1LL << 60;
  for (int i = 0; i < n; i++)
  {
    long long cnt = 0;
    long long cur = 0;
    for (int j = i - 1; j >= 0; j--)
    {
      cnt += cur / a[j] + 1;
      cur = (cur / a[j] + 1) * a[j];
    }

    cur = 0;
    for (int j = i + 1; j < n; j++)
    {
      cnt += cur / a[j] + 1;
      cur = (cur / a[j] + 1) * a[j];
    }

    ans = min(ans, cnt);
  }

  cout << ans << endl;
}