#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (!accumulate(begin(a), end(a), 0, [](int u, int v) { return u ^ v; }))
  {
    cout << -1 << endl;
    return 0;
  }

  vector<int> basis;
  for (int x : a)
  {
    for (int y : basis)
      x = min(x, x ^ y);
    if (x)
    {
      int id = 0;
      while (id < size(basis) && basis[id] > x)
        id++;
      basis.insert(begin(basis) + id, x);
    }
  }
  cout << size(basis) << endl;
}