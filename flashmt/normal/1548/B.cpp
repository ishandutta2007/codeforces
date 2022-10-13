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
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (n == 1)
    {
      cout << 1 << '\n';
      continue;
    }

    vector<long long> b(n - 1);
    for (int i = 0; i < n - 1; i++)
      b[i] = abs(a[i + 1] - a[i]);

    vector<pair<long long, int>> seg = {{b[0], 0}};
    int ans = b[0] > 1;
    for (int i = 1; i < n - 1; i++)
    {
      for (int j = 0; j < size(seg); j++)
        seg[j].first = __gcd(seg[j].first, b[i]);
      seg.push_back({b[i], i});

      sort(begin(seg), end(seg));
      vector<pair<long long, int>> newSeg = {seg[0]};
      for (int j = 1; j < size(seg); j++)
        if (seg[j].first != newSeg.back().first)
          newSeg.push_back(seg[j]);

      for (auto [g, j] : newSeg)
        if (g > 1)
          ans = max(ans, i - j + 1);

      swap(seg, newSeg);
    }
    cout << ans + 1 << '\n';
  }
}