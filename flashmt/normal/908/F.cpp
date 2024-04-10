#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a[3];
  for (int i = 0; i < n; i++)
  {
    int x;
    char c;
    cin >> x >> c;
    if (c == 'B') a[0].push_back(x);
    else if (c == 'R') a[1].push_back(x);
    else a[2].push_back(x);
  }

  auto getMaxGap = [&](int color, int from, int to)
  {
    int l = lower_bound(begin(a[color]), end(a[color]), from) - begin(a[color]);
    int r = upper_bound(begin(a[color]), end(a[color]), to) - begin(a[color]);
    if (l == r)
      return 0;
    int res = max(a[color][l] - from, to - a[color][r - 1]);
    for (int i = l + 1; i < r; i++)
      res = max(res, a[color][i] - a[color][i - 1]);
    return res;
  };

  if (empty(a[2]))
  {
    long long ans = 0;
    for (int c = 0; c < 2; c++)
      if (!empty(a[c]))
        ans += a[c].back() - a[c][0];
    cout << ans << endl;
  }
  else
  {
    long long ans = 0;
    for (int i = 0; i + 1 < size(a[2]); i++)
    {
      int from = a[2][i], to = a[2][i + 1];
      int maxGap0 = getMaxGap(0, from, to);
      int maxGap1 = getMaxGap(1, from, to);
      ans += to - from;
      if (maxGap0 && maxGap1) ans += min(to - from, (to - from) * 2 - maxGap0 - maxGap1);
      else if (maxGap0 || maxGap1) ans += to - from - maxGap0 - maxGap1;
    }
    for (int c = 0; c < 2; c++)
      if (!empty(a[c]))
      {
        ans += max(0, a[2][0] - a[c][0]);
        ans += max(0, a[c].back() - a[2].back());
      }

    cout << ans << endl;
  }
}