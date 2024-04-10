#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q, maxValue = 0, a[200200];
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    maxValue = max(maxValue, a[i]);
  }

  vector < pair<int, int> > ans;
  int turn = 0;
  while (a[turn] != maxValue)
  {
    ans.push_back({a[turn], a[turn + 1]});
    if (a[turn] > a[turn + 1])
    {
      a[turn + n] = a[turn + 1];
      a[turn + 1] = a[turn];
    }
    else a[turn + n] = a[turn];
    turn++;
  }

  long long x;
  while (q--)
  {
    cin >> x;
    if (x <= turn) cout << ans[x - 1].first << ' ' << ans[x - 1].second << '\n';
    else
    {
      x = (x - turn - 1) % (n - 1);
      cout << a[turn] << ' ' << a[turn + 1 + x] << '\n';
    }
  }
}