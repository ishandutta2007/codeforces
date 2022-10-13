#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int n;
vector<int> monsters, gain;
vector<vector<int>> a;

int isGood(int power)
{
  vector<int> safe(n);
  safe[0] = 1;
  while (1)
  {
    vector<int> tr(n, -1), powerAt(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (safe[i])
      {
        powerAt[i] = power;
        tr[i] = 0;
        q.push(i);
      }

    if (size(q) == n)
      return 1;

    auto trace = [&](int x)
    {
      while (!safe[x])
      {
        safe[x] = 1;
        power = min(power + gain[x], oo);
        x = tr[x];
      }
    };

    int found = 0;
    while (!q.empty() && !found)
    {
      int x = q.front();
      q.pop();
      for (int y : a[x])
      {
        if (safe[x] && safe[y])
          continue;

        if (tr[x] != y && powerAt[x] > monsters[y])
        {
          if (tr[y] < 0)
          {
            tr[y] = x;
            powerAt[y] = min(powerAt[x] + gain[y], oo);
            q.push(y);
          }
          else
          {
            trace(x);
            trace(y);
            found = 1;
            break;
          }
        }
      }
    }

    if (!found)
      return 0;
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m;
    cin >> n >> m;
    monsters.resize(n);
    gain.resize(n);
    a.assign(n, vector<int>());
    for (int i = 1; i < n; i++)
      cin >> monsters[i];
    for (int i = 1; i < n; i++)
      cin >> gain[i];
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    int low = 1, high = 1e9, ans = high + 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (isGood(mid))
      {
        ans = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    cout << ans << endl;
  }
}