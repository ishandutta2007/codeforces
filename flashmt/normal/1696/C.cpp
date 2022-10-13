#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

vector<pair<int, long long>> normalize(vector<pair<int, long long>> a)
{
  vector<pair<int, long long>> res;
  int n = size(a);
  for (int i = 0; i < n;)
  {
    int j = i;
    long long sum = 0;
    while (j < n && a[j].first == a[i].first)
      sum += a[j++].second;
    res.push_back({a[i].first, sum});
    i = j;
  }
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> a;
    for (int i = 0; i < n; i++)
    {
      int x;
      long long y = 1;
      cin >> x;
      while (x % m == 0)
      {
        x /= m;
        y *= m;
      }
      a.push_back({x, y});
    }

    int k;
    cin >> k;
    vector<pair<int, long long>> b;
    for (int i = 0; i < k; i++)
    {
      int x;
      long long y = 1;
      cin >> x;
      while (x % m == 0)
      {
        x /= m;
        y *= m;
      }
      b.push_back({x, y});
    }

    cout << (normalize(a) == normalize(b) ? "Yes" : "No") << '\n';
  }
}