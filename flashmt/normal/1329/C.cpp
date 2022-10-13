#include <bits/stdc++.h>
using namespace std;

int g, h, a[1 << 21], id[1 << 21];

int canRemove(int x)
{
  int level = 31 - __builtin_clz(x);
  if (!a[x * 2] && !a[x * 2 + 1])
    return level > g - 1;
  int y = a[x * 2] > a[x * 2 + 1] ? x * 2 : x * 2 + 1;
  return canRemove(y);
}

void remove(int x)
{
  if (!a[x * 2] && !a[x * 2 + 1])
    return;
  int y = a[x * 2] > a[x * 2 + 1] ? x * 2 : x * 2 + 1;
  a[x] = a[y];
  id[a[x]] = x;
  a[y] = 0;
  remove(y);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> h >> g;
    for (int i = 1; i < 1 << h; i++)
    {
      cin >> a[i];
      a[i * 2] = a[i * 2 + 1] = 0;
      id[a[i]] = i;
    }

    vector<int> values(a + 1, a + (1 << h));
    sort(begin(values), end(values), greater<int>());
    int toRemove = (1 << h) - (1 << g);
    vector<int> removed;
    for (int i : values)
      if (canRemove(id[i]))
      {
        removed.push_back(id[i]);
        a[id[i]] = 0;
        remove(id[i]);
        if (size(removed) == toRemove)
          break;
      }

    long long ans = accumulate(a + 1, a + (1 << g), 0LL);
    cout << ans << '\n';
    for (int x : removed)
      cout << x << ' ';
    cout << '\n';
  }
}