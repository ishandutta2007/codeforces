#include <bits/stdc++.h>
using namespace std;

int ask(string op, int x, int y)
{
  cout << op << ' ' << x << ' ' << y << '\n';
  cout.flush();
  int v;
  cin >> v;
  return v;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[1 << 17], x[1 << 17], seen[1 << 16] = {0};
  cin >> n;
  pair<int, int> duplicates(0, 0);
  for (int i = 2; i <= n; i++)
  {
    x[i] = ask("XOR", 1, i);
    if (!x[i]) duplicates = {1, i};
    else if (seen[x[i]]) duplicates = {seen[x[i]], i};
    else seen[x[i]] = i;
  }

  if (duplicates.first) // has duplicates
  {
    auto [u, v] = duplicates;
    a[u] = a[v] = ask("OR", u, v);
    if (u != 1)
      a[1] = a[u] ^ x[u];
  }
  else // no duplicates, all values of [0, n - 1]
  {
    int u = 0;
    for (int i = 2; i <= n; i++)
      if (x[i] == 1)
        u = i;
    assert(u);
    a[1] = a[u] = ask("AND", 1, u);

    // find the last bit of 1 and u
    for (int i = 2; i <= n; i++)
      if (i != u)
      {
        if (x[i] % 2 == 0)
        {
          int bit = ask("AND", 1, i) % 2;
          if (bit) a[1]++;
          else a[u]++;
        }
        else
        {
          int bit = ask("AND", u, i) % 2;
          if (bit) a[u]++;
          else a[1]++;
        }
        break;
      }
  }

  for (int i = 2; i <= n; i++)
    a[i] = a[1] ^ x[i];

  cout << "!";
  for (int i = 1; i <= n; i++)
    cout << ' ' << a[i];
  cout.flush();
}