#include <bits/stdc++.h>
using namespace std;

set<int> s[3];
int n, tree[3][200200];

void add(int id, int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[id][i] += v;
}

int get(int id, int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[id][i];
  return res;
}

int calc()
{
  int res = n;
  for (int x = 0; x < 3; x++)
  {
    int y = (x + 1) % 3, z = (x + 2) % 3;
    if (s[y].empty())
      continue;
    int minY = *s[y].begin(), maxY = *s[y].rbegin();
    if (s[z].empty()) res -= s[x].size();
    else
    {
      int minZ = *s[z].begin(), maxZ = *s[z].rbegin();
      if (minY < minZ)
        res -= get(x, minZ) - get(x, minY);
      if (maxZ < maxY)
        res -= get(x, maxY) - get(x, maxZ);
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m[128];
  m['R'] = 0;
  m['P'] = 1;
  m['S'] = 2;

  int q, a[200200];
  string t;
  cin >> n >> q >> t;
  for (int i = 1; i <= n; i++)
  {
    a[i] = m[t[i - 1]];
    s[a[i]].insert(i);
    add(a[i], i, 1);
  }
  cout << calc() << '\n';

  while (q--)
  {
    char c;
    int x;
    cin >> x >> c;
    s[a[x]].erase(x);
    add(a[x], x, -1);
    a[x] = m[c];
    s[a[x]].insert(x);
    add(a[x], x, 1);
    cout << calc() << '\n';
  }
}