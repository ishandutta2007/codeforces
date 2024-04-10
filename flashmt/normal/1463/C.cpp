#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, ans = 0, prev = -1;
    long long t[100100], x[100100], curT = 0, oldX = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> t[i] >> x[i];
    t[n] = 1LL << 50;

    for (int i = 0; i < n; i++)
      if (t[i] >= curT)
      {
        if (prev >= 0)
          oldX = x[prev];
        curT = t[i] + llabs(x[i] - oldX);
        ans += t[i + 1] >= curT;
        prev = i;
      }
      else
      {
        if ((x[i] - x[prev]) * (x[i] - oldX) > 0)
          continue;
        long long at = t[prev] + llabs(x[i] - oldX);
        if (t[i] <= at && at <= t[i + 1])
          ans++;
      }

    cout << ans << endl;
  }
}