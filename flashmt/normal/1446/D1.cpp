#include <bits/stdc++.h>
using namespace std;

int n, a[200200], cnt[200200], last[400400];

int solve(int value1, int value2)
{
  int res = 0;
  memset(last, -1, sizeof last);
  last[n] = 0;
  for (int i = 1, cur = n; i <= n; i++)
  {
    if (a[i] == value1) cur++;
    else if (a[i] == value2) cur--;
    if (last[cur] >= 0) res = max(res, i - last[cur]);
    else last[cur] = i;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }

  int maxCnt = *max_element(cnt, cnt + n + 1);
  int mostFreq = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == maxCnt)
    {
      if (mostFreq)
      {
        cout << n << endl;
        return 0;
      }
      mostFreq = i;
    }

  int ans = 0;
  for (int other = 1; other <= 100; other++)
    if (other != mostFreq)
      ans = max(ans, solve(mostFreq, other));

  cout << ans << endl;
}