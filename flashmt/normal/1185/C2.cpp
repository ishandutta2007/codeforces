#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt[101] = {0}, t, sum = 0;
  cin >> n >> m;
  while (n--)
  {
    cin >> t;
    sum += t;
    if (sum <= m) cout << 0 << ' ';
    else
    {
      int sumFail = sum - m, ans = 0;
      for (int i = 100; i; i--)
        if (cnt[i] * i >= sumFail) 
        {
          ans += (sumFail + i - 1) / i;
          break;
        }
        else 
        {
          ans += cnt[i];
          sumFail -= cnt[i] * i;
        }
      cout << ans << ' ';
    }
    cnt[t]++;
  }
}