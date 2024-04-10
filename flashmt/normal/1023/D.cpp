#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a[200200], ans[200200];
  cin >> n >> q;
  vector<int> minIndex(q + 1, n), maxIndex(q + 1, -1);
  set<int> s;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    s.insert(i);
    if (a[i])
    {
      minIndex[a[i]] = min(minIndex[a[i]], i);
      maxIndex[a[i]] = max(maxIndex[a[i]], i);
    }
  }

  if (minIndex[q] == n)
  {
    int found = 0;
    for (int i = 0; i < n; i++)
      if (!a[i])
      {
        minIndex[q] = maxIndex[q] = i;
        found = 1;
        break;
      }
    if (!found)
    {
      cout << "NO" << endl;
      return 0;
    }
  }

  for (int i = q; i; i--)
    if (minIndex[i] < n)
    {
      auto it = s.lower_bound(minIndex[i]);
      while (it != s.end() && *it <= maxIndex[i])
      {
        ans[*it] = i;
        s.erase(it++);
      }
    }

  for (auto i : s)
    ans[i] = 1;

  for (int i = 0; i < n; i++)
    if (a[i] && ans[i] != a[i])
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}