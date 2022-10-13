#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, v[100100];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  v[n++] = 1e9;

  sort(v, v + n);
  vector<int> cnt(n, 0);
  while (m--)
  {
    int x, xx, y;
    cin >> x >> xx >> y;
    if (x == 1)
    {
      int id = upper_bound(v, v + n, xx) - v;
      if (id > 0)
        cnt[--id]++;
    }
  }

  for (int i = n - 2; i >= 0; i--)
    cnt[i] += cnt[i + 1];

  if (!cnt[0]) cout << 0 << endl;
  else
  {
    int ans = oo;
    for (int i = 0; i < n; i++)
      ans = min(ans, i + cnt[i]);
    cout << ans << endl;
  }
}