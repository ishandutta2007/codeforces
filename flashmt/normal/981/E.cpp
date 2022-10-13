#include <bits/stdc++.h>
using namespace std;
const int NUM_BASE = 2;
const int BASES[] = {int(1e9) + 7, 999999937};

int n, good[10100];
vector <int> l[10100], r[10100];

void solve(int BASE)
{
  int ways[10100] = {0}, res[10100] = {0};
  ways[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (auto v : l[i])
      for (int j = n; j >= v; j--)
        ways[j] = (ways[j] + ways[j - v]) % BASE;

    for (int j = 1; j <= n; j++)
      res[j] |= ways[j] > 0;

    for (auto v : r[i])
      for (int j = v; j <= n; j++)
        ways[j] = (ways[j] - ways[j - v] + BASE) % BASE;
  }
  for (int i = 1; i <= n; i++)
    good[i] += res[i];
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y, v, q;
  cin >> n >> q;
  while (q--)
  {
    cin >> x >> y >> v;
    l[x].push_back(v);
    r[y].push_back(v);
  }

  for (int i = 0; i < NUM_BASE; i++)
    solve(BASES[i]);

  vector <int> ans;
  for (int i = 1; i <= n; i++)
    if (good[i] == NUM_BASE)
      ans.push_back(i);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
}