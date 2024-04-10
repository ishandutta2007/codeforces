#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int ask(int x, int y, int z)
{
  cout << "? " << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

pair<int, int> solve6(int x, int y, int z, int v)
{
  for (int i : {0, 1})
    for (int j : {x, y})
      if (ask(i, j, 2) != v)
      {
        a[i ^ 1] = v;
        a[j] = v ^ 1;
        return {i ^ 1, j};
      }

  a[0] = a[1] = a[2] = v;
  if (ask(0, x, y) == v)
  {
    a[z] = v ^ 1;
    return {0, z};
  }

  a[x] = a[y] = v ^ 1;
  return {0, x};
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    int v = ask(0, 1, 2), x, y, z;
    while (1)
    {
      while (1)
      {
        x = rng() % (n - 3) + 3;
        y = rng() % (n - 3) + 3;
        z = rng() % (n - 3) + 3;
        if (x != y && y != z && z != x)
          break;
      }

      if (ask(x, y, z) != v)
        break;
    }

    a.assign(n, -1);
    auto [t, u] = solve6(x, y, z, v);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (a[i] < 0)
        a[i] = ask(t, u, i);
      if (!a[i])
        ans.push_back(i);
    }

    cout << "! " << size(ans);
    for (int x : ans)
      cout << ' ' << x + 1;
    cout << endl;
    cout.flush();
  }
}