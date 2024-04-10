#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int quota;

int ask(int x, int y, int z)
{
  assert(quota > 0);
  quota--;
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
        a[i] = ask(i, i ^ 1, j);
        a[2] = a[i] ^ 1;
        for (int k : {x, y, z})
          if (a[k] < 0)
            a[k] = ask(k, i ^ 1, j);
        return {i ^ 1, j};
      }

  a[0] = a[1] = a[2] = v;
  if (ask(0, x, y) == v)
  {
    a[z] = v ^ 1;
    a[x] = ask(x, 0, z);
    a[y] = a[x] ^ 1;
    return {0, z};
  }

  a[x] = a[y] = v ^ 1;
  a[z] = ask(z, 0, x);
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
    quota = n + 6;
    a.assign(n, -1);
    vector<int> v(n / 3);
    int cur = -1;
    for (int i = 0; i < n / 3; i++)
    {
      v[i] = ask(i * 3, i * 3 + 1, i * 3 + 2);
      if (v[i] != v[0])
        cur = i;
    }

    auto [t, u] = solve6(cur * 3, cur * 3 + 1, cur * 3 + 2, v[0]);
    for (int i = 1; i < n / 3; i++)
      if (i != cur)
      {
        int other = v[i] == v[0] ? u : t;
        if (ask(i * 3, i * 3 + 1, other) == v[i])
        {
          a[i * 3] = a[i * 3 + 1] = v[i];
          a[i * 3 + 2] = ask(i * 3 + 2, t, u);
        }
        else
        {
          a[i * 3 + 2] = v[i];
          a[i * 3] = ask(i * 3, t, u);
          a[i * 3 + 1] = a[i * 3] ^ 1;
        }
      }

    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (!a[i])
        ans.push_back(i);

    cout << "! " << size(ans);
    for (int x : ans)
      cout << ' ' << x + 1;
    cout << endl;
    cout.flush();
  }
}