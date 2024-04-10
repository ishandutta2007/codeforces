#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
const long long INF = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    cin >> m >> n;
    vector<int> a = {-oo, oo};
    for (int i = 0; i < m; i++)
    {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(begin(a), end(a));
    m = size(a) - 1;
    vector<vector<pair<int, int>>> segs(m);
    for (int i = 0; i < n; i++)
    {
      int l, r;
      cin >> l >> r;
      int j = lower_bound(begin(a), end(a), l) - begin(a);
      if (r < a[j])
        segs[j - 1].push_back({l, r});
    }

    vector<vector<long long>> f(m);
    for (int i = 0; i < m; i++)
      if (!empty(segs[i]))
      {
        sort(begin(segs[i]), end(segs[i]));
        int cur = 1;
        for (int j = 1; j < size(segs[i]); j++)
          if (segs[i][j].first > segs[i][cur - 1].first)
          {
            while (cur && segs[i][cur - 1].second >= segs[i][j].second)
              cur--;
            segs[i][cur++] = segs[i][j];
          }
        segs[i].resize(cur);
      }

    f[0].assign(size(segs[0]) + 1, INF);
    f[0][0] = 0;
    for (int i = 1; i < m; i++)
    {
      int cntL = size(segs[i - 1]), cntR = size(segs[i]);
      f[i].assign(cntR + 1, INF);

      long long minLarge = oo;
      for (int j = 0; j <= cntL; j++)
        minLarge = min(minLarge, f[i - 1][j] - (j < cntL ? segs[i - 1][j].second : a[i]));
      long long minSmall = f[i - 1][cntL] - a[i] * 2LL;

      for (int j = 0, k = cntL; j <= cntR; j++)
      {
        int r = j ? segs[i][j - 1].first : a[i];
        while (k && a[i] - segs[i - 1][k - 1].second < r - a[i])
        {
          k--;
          minSmall = min(minSmall, f[i - 1][k] - segs[i - 1][k].second * 2LL);
        }
        f[i][j] = min(minLarge + r * 2LL - a[i], minSmall + a[i] + r);
      }
    }

    cout << f[m - 1].back() << '\n';
  }
}