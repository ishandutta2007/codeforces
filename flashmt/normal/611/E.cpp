#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[6], cnt[6], t[200200];

void solve()
{
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int type = -1;
    for (int j = 0; j < 6; j++)
      if (t[i] <= a[j])
      {
        type = j;
        break;
      }

    if (type < 0) ans++;
    else cnt[type]++;
  }

  ans += cnt[5] + cnt[4] + cnt[3];
  for (int i = 2, available = 0; i >= 0; i--)
  {
    cnt[i] -= cnt[5 - i] + available;
    if (cnt[i] < 0)
    {
      available = -cnt[i];
      cnt[i] = 0;
    }
    else available = 0;
  }

  int best = oo;
  for (int i = 0; i <= n; i++)
  {
    int rest = 0;
    for (int j = 2, available = 0; j >= 0; j--)
    {
      int x = cnt[j] - i - available;
      if (x < 0) available = -x;
      else 
      {
        available = 0; 
        rest += x;
      }
    }
    best = min(best, i + (rest + 1) / 2);
  }

  ans += best;
  cout << ans << endl;
}

void solveC()
{
  swap(a[2], a[3]);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int type = -1;
    for (int j = 0; j < 6; j++)
      if (t[i] <= a[j])
      {
        type = j;
        break;
      }

    if (type < 0) ans++;
    else cnt[type]++;
  }

  int best = oo;
  for (int i = 0; i <= n; i++)
  {
    int tmpCnt[6];
    for (int j = 0; j < 6; j++) 
      tmpCnt[j] = cnt[j];

    for (int j = 3, available = 0; j >= 0; j--)  
    {
      tmpCnt[j] -= (j != 2 ? i : 0) + available;
      if (tmpCnt[j] < 0)
      {
        available = -tmpCnt[j];
        tmpCnt[j] = 0;
      }
      else available = 0;
    }

    int cur = i + cnt[5] + cnt[4], rest = tmpCnt[2] + tmpCnt[3];
    for (int j = 1, available = 0; j >= 0; j--)
    {
      tmpCnt[j] -= available + tmpCnt[5 - j];
      if (tmpCnt[j] < 0)
      {
        available = -tmpCnt[j];
        tmpCnt[j] = 0;
      }
      else 
      {
        available = 0;
        rest += tmpCnt[j];
      }
    }

    cur += max(tmpCnt[3], (rest + 1) / 2);
    best = min(best, cur);
  }

  ans += best;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  sort(a, a + 3);
  a[3] = a[0] + a[1];
  a[4] = a[0] + a[2];
  a[5] = a[1] + a[2];

  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
    if (t[i] > a[0] + a[1] + a[2])
    {
      cout << -1 << endl;
      return 0;
    }
  }

  if (a[2] <= a[3]) solve();
  else solveC();
}