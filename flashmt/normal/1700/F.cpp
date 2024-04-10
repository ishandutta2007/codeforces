#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i : {0, 1})
    for (int &x : a[i])
      cin >> x;
  vector<vector<int>> b(2, vector<int>(n));
  for (int i : {0, 1})
    for (int &x : b[i])
      cin >> x;

  for (int i : {0, 1})
    for (int j = 0; j < n; j++)
      if (a[i][j] && b[i][j])
        a[i][j] = b[i][j] = 0;

  deque<int> qa[2], qb[2];
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    vector<int> order = size(qb[0]) >= size(qb[1]) ? vector{0, 1} : vector{1, 0};
    for (int j : order)
      if (a[j][i])
      {
        int found = 0;
        for (int jj : {j, j ^ 1})
          if (!empty(qb[jj]))
          {
            ans += i - qb[jj].front() + abs(j - jj);
            qb[jj].pop_front();
            found = 1;
            break;
          }

        if (!found)
          qa[j].push_back(i);
      }

    order = size(qa[0]) >= size(qa[1]) ? vector{0, 1} : vector{1, 0};
    for (int j : order)
      if (b[j][i])
      {
        int found = 0;
        for (int jj : {j, j ^ 1})
          if (!empty(qa[jj]))
          {
            ans += i - qa[jj].front() + abs(j - jj);
            qa[jj].pop_front();
            found = 1;
            break;
          }

        if (!found)
          qb[j].push_back(i);
      }
  }

  for (int i : {0, 1})
    if (!empty(qa[i]) || !empty(qb[i]))
    {
      cout << -1 << endl;
      return 0;
    }

  cout << ans << endl;
}