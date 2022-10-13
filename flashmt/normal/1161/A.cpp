#include <bits/stdc++.h>
using namespace std;

set <int> a[100100];

int check(int x, int y)
{
  if (a[x].empty() || a[y].empty())
    return 1;
  return *a[x].begin() > *a[y].rbegin();
}

int main()
{
  ios::sync_with_stdio(0);
  int n, k, x;
  
  cin >> n >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x;
    a[x].insert(i + 1);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (a[i].empty())
      ans++;
    if (i > 1)
      ans += check(i, i - 1);
    if (i < n)
      ans += check(i, i + 1);
  }
  cout << ans << endl;
}