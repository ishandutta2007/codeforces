#include <bits/stdc++.h>
using namespace std;

int n, tree[200200];

void add(int x)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i]++;
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    vector<pair<int, int>> a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      a.push_back({x, i});
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());
    set<int> has;
    has.insert(0);
    has.insert(n + 1);
    int ansX = -1, ansY = -1;
    for (int i = 0; i < n;)
    {
      int ii = i, x = a[i].first;
      while (ii < n && a[ii].first == x)
        add(a[ii++].second);

      if (ii - i >= 3)
      {
        int low = a[ii - 1].second, high = a[i].second;
        auto r = has.lower_bound(high);
        auto l = has.lower_bound(low);
        if (*--l == 0 && *r == n + 1)
        {
          int from = *++l, to = *--r;
          if (from > to)
          {
            int mid = a[i + 1].second;
            ansX = mid - 1;
            ansY = n - mid;
          }
          else
          {
            for (int j = i + 1; j < ii - 1; j++)
            {
              int mid = a[j].second;
              if (mid < from - 1 || mid > to + 1)
                continue;
              int newFrom = min(from, mid), newTo = max(to, mid);
              if (get(newTo) - get(newFrom) == newTo - newFrom)
              {
                ansX = newFrom - 1;
                ansY = n - newTo;
                break;
              }
            }
          }
        }
      }

      for (int j = i; j < ii; j++)
        has.insert(a[j].second);

      i = ii;
    }

    if (ansX < 0) cout << "NO\n";
    else
    {
      cout << "YES\n";
      cout << ansX << ' ' << n - ansX - ansY << ' ' << ansY << '\n';
    }

    for (int i = 1; i <= n; i++)
      tree[i] = 0;
  }
}