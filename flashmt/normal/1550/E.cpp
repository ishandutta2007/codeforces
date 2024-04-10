#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, k, cnt[200200][22], f[1 << 17];
vector<int> r[200200];

int isGood(int goal)
{
  vector<int> last(k, n + 1);
  r[n] = last;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < k; j++)
      if (i + goal <= n && cnt[i][j] + cnt[i][k] + goal == cnt[i + goal][j] + cnt[i + goal][k])
        last[j] = i + goal;
    r[i] = last;
  }

  fill(f, f + (1 << k), n + 1);
  f[0] = 0;
  for (int mask = 1; mask < 1 << k; mask++)
    for (int i = 0; i < k; i++)
      if ((mask >> i & 1) && f[mask ^ 1 << i] <= n)
        f[mask] = min(f[mask], r[f[mask ^ 1 << i]][i]);

  return f[(1 << k) - 1] <= n;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a;
  cin >> n >> k >> a;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
      cnt[i + 1][j] = cnt[i][j];
    int c = a[i] == '?' ? k : a[i] - 'a';
    cnt[i + 1][c]++;
  }

  int low = 1, high = n / k, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(mid))
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  cout << ans << endl;
}