#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), badIds;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i] > q)
        badIds.push_back(i);
    }

    if (empty(badIds))
    {
      cout << string(n, '1') << '\n';
      continue;
    }

    sort(rbegin(badIds), rend(badIds));
    vector<int> id(n, -1);
    for (int i = 0; i < size(badIds); i++)
      id[badIds[i]] = i;

    int low = 1, high = size(badIds), ans = 0;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int curQ = q;
      for (int i = 0; i < n; i++)
        if (id[i] < mid && a[i] > curQ)
          curQ--;

      if (curQ >= 0)
      {
        ans = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }

    for (int i = 0; i < n; i++)
      cout << (id[i] < ans);
    cout << '\n';
  }
}