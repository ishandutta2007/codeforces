#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], b[200200], deg[200200] = {0};
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a[i];
    deg[a[i]]++;
  }

  set<int> s;
  for (int i = 1; i <= n; i++)
    if (!deg[i])
      s.insert(i);

  for (int i = n - 2; i >= 0; i--)
  {
    assert(!s.empty());
    b[i] = *s.begin();
    s.erase(b[i]);
    if (!--deg[a[i]])
      s.insert(a[i]);
  }

  cout << a[0] << '\n';
  for (int i = 0; i < n - 1; i++)
    cout << a[i] << ' ' << b[i] << '\n';
}