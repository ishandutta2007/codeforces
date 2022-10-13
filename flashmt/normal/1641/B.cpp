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
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }

    int hasOdd = 0;
    for (auto [k, v] : cnt)
      hasOdd |= v % 2;

    if (hasOdd)
    {
      cout << -1 << '\n';
      continue;
    }

    int offset = 0;
    vector<pair<int, int>> ops;
    vector<int> splits;
    while (!empty(a))
    {
      n = size(a);
      int id = 1;
      while (a[id] != a[0])
        id++;

      for (int j = 1; j < id; j++)
      {
        int pos = offset + id + j;
        ops.push_back({pos, a[j]});
      }

      splits.push_back(id * 2);
      offset += id * 2;

      reverse(begin(a), begin(a) + id + 1);
      a.erase(begin(a) + id);
      a.erase(begin(a));
    }

    cout << size(ops) << '\n';
    for (auto [p, c] : ops)
      cout << p << ' ' << c << '\n';
    cout << size(splits) << '\n';
    for (int x : splits)
      cout << x << ' ';
    cout << '\n';
  }
}