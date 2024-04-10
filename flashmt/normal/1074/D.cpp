#include <bits/stdc++.h>
using namespace std;

int a[500500], ds[500500];
vector<int> comp[500500];
map<int, int> m;

int getId(int x)
{
  if (!m.count(x))
  {
    int sz = m.size();
    m[x] = sz;
    ds[sz] = sz;
    comp[sz].push_back(sz);
  }
  return m[x];
}

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, last = 0;
  cin >> q;
  m[0] = ds[0] = 0;
  comp[0] = {0};
  while (q--)
  {
    int op, l, r, x;
    cin >> op >> l >> r;
    l = l ^ last;
    r = r ^ last;
    if (l > r)
      swap(l, r);

    l = getId(l);
    r = getId(r + 1);
    int dl = get(l), dr = get(r);

    if (op == 1)
    {
      cin >> x;
      x = x ^ last;
      if (dl != dr)
      {
        if (comp[dl].size() < comp[dr].size())
        {
          swap(l, r);
          swap(dl, dr);
        }
        ds[dr] = dl;
        x ^= a[l] ^ a[r];
        for (int u : comp[dr])
        {
          a[u] ^= x;
          comp[dl].push_back(u);
        }
      }
    }
    else
    {
      if (dl != dr)
      {
        cout << -1 << '\n';
        last = 1;
      }
      else
      {
        last = a[l] ^ a[r];
        cout << last << '\n';
      }
    }
  }
}