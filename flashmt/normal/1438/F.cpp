#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y, int z)
{
  cout << "? " << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
  cout.flush();
  int res;
  cin >> res;
  return res - 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h;
  cin >> h;
  int n = (1 << h) - 1;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

  vector<int> cnt(n, 0);
  for (int i = 0; i < 422; i++)
    while (1)
    {
      int x = rng() % n, y = rng() % n, z = rng() % n;
      if (x != y && y != z && z != x)
      {
        cnt[ask(x, y, z)]++;
        break;
      }
    }

  int u = 0, v = 1;
  if (cnt[0] < cnt[1])
    swap(u, v);
  for (int i = 2; i < n; i++)
    if (cnt[i] > cnt[u])
    {
      v = u;
      u = i;
    }
    else if (cnt[i] > cnt[v]) v = i;

  for (int i = 0; i < n; i++)
    if (i != u && i != v)
      if (ask(u, v, i) == i)
      {
        cout << "! " << i + 1 << '\n';
        cout.flush();
        return 0;
      }

  assert(0);
}