#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

void refine(vector<int> &a)
{
  a.resize(unique(begin(a), end(a)) - begin(a));
  auto u = find(begin(a), end(a), 0);
  if (u != end(a))
    a.erase(u);
}

vector<int> solve(vector<int> a)
{
  if (empty(a) || size(a) == 1 && abs(a[0]) == 1)
    return a;

  if (none_of(begin(a), end(a), [](int x) { return x % 2; }))
  {
    for (int &x : a)
      x /= 2;
    refine(a);
    auto res = solve(a);
    for (int &x : res)
      x *= 2;
    return res;
  }

  vector<int> res;
  for (int v : {-1, 1})
  {
    auto newA = a;
    for (int &x : newA)
    {
      if (x % 2)
        x -= v;
      x /= 2;
    }
    refine(newA);

    auto cur = solve(newA);
    for (int &x : cur)
      x *= 2;
    cur.push_back(v);
    if (empty(res) || size(cur) < size(res))
      res = cur;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(begin(a), end(a));
  refine(a);

  auto ans = solve(a);
  cout << size(ans) << endl;
  for (int x : ans)
    cout << x << ' ';
}