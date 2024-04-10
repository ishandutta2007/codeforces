#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 450;

int n, a[200200], cnt[200200], last[400400];

int solveValues(int value1, int value2)
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

int solveFrequency(int maxFreq)
{
  memset(cnt, 0, sizeof cnt);
  int cntMax = 0, res = 0;
  for (int i = 1, j = 1; i <= n; i++)
  {
    cnt[a[i]]++;
    if (cnt[a[i]] == maxFreq) cntMax++;
    else while (cnt[a[i]] > maxFreq)
    {
      if (cnt[a[j]] == maxFreq)
        cntMax--;
      cnt[a[j]]--;
      j++;
    }

    if (cntMax > 1)
      res = max(res, i - j + 1);
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
  vector<int> freqValues;
  for (int i = 1; i <= n; i++)
  {
    if (cnt[i] == maxCnt)
    {
      if (mostFreq)
      {
        cout << n << endl;
        return 0;
      }
      mostFreq = i;
    }
    if (cnt[i] > LIMIT)
      freqValues.push_back(i);
  }

  int ans = 0;
  // frequent values
  for (int v : freqValues)
    if (v != mostFreq)
      ans = max(ans, solveValues(mostFreq, v));

  // non-frequent
  for (int maxFreq = 1; maxFreq <= LIMIT; maxFreq++)
    ans = max(ans, solveFrequency(maxFreq));

  cout << ans << endl;
}