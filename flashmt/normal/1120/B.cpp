#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100], b[100100], sumA = 0, sumB = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    a[i] = s[i] - '0';
    sumA += a[i];
  }
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    b[i] = s[i] - '0';
    sumB += b[i];
  }

  if (sumA % 2 != sumB % 2)
  {
    cout << -1 << endl;
    return 0;
  }

  vector<int> add(n, 0), minus(n, 0);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int d = b[i] - a[i];
    if (i)
      d -= add[i - 1] - minus[i - 1];
    if (d > 0)
    {
      add[i] += d;
      ans += d;
    }
    else if (d < 0)
    {
      minus[i] -= d;
      ans -= d;
    }
  }

  if (a[n - 1] + add[n - 2] - minus[n - 2] != b[n - 1])
  {
    cout << -1 << endl;
    return 0;
  }

  cout << ans << '\n';
  set<int> id[10][10];
  for (int i = 0; i < n - 1; i++)
    if (add[i] + minus[i])
      id[a[i]][a[i + 1]].insert(i);

  int step = min(ans, 100000LL);
  while (step)
  {
    step--;
    int found = 0;
    for (int x = 0; x < 10 && !found; x++)
      for (int y = 0; y < 10; y++)
        if (!id[x][y].empty())
        {
          int i = *id[x][y].begin();
          if (x < 9 && y < 9 && add[i])
          {
            cout << i + 1 << ' ' << 1 << '\n';
            add[i]--;
            id[x][y].erase(i);
            a[i]++;
            a[i + 1]++;
            if (add[i] + minus[i])
              id[x + 1][y + 1].insert(i);

            if (i && add[i - 1] + minus[i - 1])
            {
              id[a[i - 1]][x].erase(i - 1);
              id[a[i - 1]][x + 1].insert(i - 1);
            }
            if (i + 2 < n && add[i + 1] + minus[i + 1])
            {
              id[y][a[i + 2]].erase(i + 1);
              id[y + 1][a[i + 2]].insert(i + 1);
            }

            found = 1;
            break;
          }

          if (x && y)
          {
            if (x == 1 && !i)
            {
              if (id[x][y].size() == 1)
                continue;
              i = *id[x][y].rbegin();
            }
            if (!minus[i])
              continue;
            cout << i + 1 << ' ' << -1 << '\n';
            minus[i]--;
            id[x][y].erase(i);
            a[i]--;
            a[i + 1]--;
            if (add[i] + minus[i])
              id[x - 1][y - 1].insert(i);

            if (i && add[i - 1] + minus[i - 1])
            {
              id[a[i - 1]][x].erase(i - 1);
              id[a[i - 1]][x - 1].insert(i - 1);
            }
            if (i + 2 < n && add[i + 1] + minus[i + 1])
            {
              id[y][a[i + 2]].erase(i + 1);
              id[y - 1][a[i + 2]].insert(i + 1);
            }

            found = 1;
            break;
          }
        }

    assert(found);
  }
}