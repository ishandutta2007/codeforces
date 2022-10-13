#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  s = ")" + s;
  n++;
  vector<int> l(n, -1), r(n, -1), st;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') st.push_back(i);
    else if (!empty(st))
    {
      int j = st.back();
      st.pop_back();
      l[i] = j;
      r[j] = i;
    }

  vector<long long> f(n);
  vector<vector<long long>> fChild(n);
  vector<int> child(n), par(n), childId(n);

  auto construct = [&](auto self, int i) -> void
  {
    fChild[i] = {0};
    for (int j = i + 1; j < r[i]; j = r[j] + 1)
    {
      childId[j] = child[i]++;
      par[j] = i;
      self(self, j);
      f[i] += f[j];
      fChild[i].push_back(f[i]);
    }
    f[i]++;
    f[i] += child[i] * (child[i] - 1LL) / 2;
  };

  for (int i = 1; i < n; i++)
    if (r[i] >= 0)
    {
      int j = i;
      fChild[i - 1] = {0};
      while (j < n && r[j] >= 0)
      {
        childId[j] = child[i - 1]++;
        par[j] = i - 1;
        construct(construct, j);
        f[i - 1] += f[j];
        fChild[i - 1].push_back(f[i - 1]);
        j = r[j] + 1;
      }
      i = j;
    }

  while (q--)
  {
    int t, x, y;
    cin >> t >> x >> y;
    if (r[x] == y) cout << f[x] << '\n';
    else
    {
      int p = par[x];
      x = childId[x];
      y = childId[l[y]];
      long long ans = (y - x) * (y - x + 1LL) / 2;
      ans += fChild[p][y + 1] - fChild[p][x];
      cout << ans << '\n';
    }
  }
}