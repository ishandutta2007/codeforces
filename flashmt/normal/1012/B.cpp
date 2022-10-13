#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> ds(n + m);
  iota(begin(ds), end(ds), 0);

  function<int(int)> get = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  };

  while (q--)
  {
    int x, y;
    cin >> x >> y;
    ds[get(--x)] = get(--y + n);
  }

  int ans = 0;
  for (int i = 0; i < m + n; i++)
    ans += get(i) == i;
  cout << ans - 1 << endl;
}