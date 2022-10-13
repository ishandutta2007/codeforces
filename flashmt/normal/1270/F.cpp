#include <bits/stdc++.h>
using namespace std;
const int K = 450;

int s[200200], n, t[200200];

long long solveSmall(int k)
{
  long long res = 0;
  for (int i = 0; i <= n; i++)
    t[i] = s[i] * k - i;
  sort(t, t + n + 1);
  for (int i = 0; i <= n;)
  {
    int j = i;
    while (j <= n && t[i] == t[j])
      j++;
    res += (j - i) * (j - i - 1LL) / 2;
    i = j;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a;
  cin >> a;
  n = a.size();
  a = " " + a;
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i] - '0';

  long long ans = 0;
  for (int k = 1; k <= K; k++)
    ans += solveSmall(k);

  vector<pair<int, int>> intervals;
  for (int i = 0; i <= n;)
  {
    int j = i;
    while (j <= n && s[j] == s[i])
      j++;
    intervals.push_back({i, j - 1});
    i = j;
  }

  for (int i = 0; i < intervals.size(); i++)
    for (int diff = 1; diff <= min(K, i); diff++)
    {
      int j = i - diff;
      auto [l, r] = intervals[i];
      auto [ll, rr] = intervals[j];
      for (int x = l; x <= r; x++)
      {
        int from = max((x - rr + diff - 1) / diff, K + 1);
        int to = (x - ll) / diff;
        ans += max(0, to - from + 1);
      }
    }

  cout << ans << endl;
}