#include <bits/stdc++.h>
using namespace std;

int n, ans[200200], v[200200], cnt[300];
vector<int> a[200200], divisor;

void visit(int x, int par, int gcd, int num)
{
  gcd = __gcd(gcd, v[x]);
  ans[x] = gcd;
  for (int i = 0; i < divisor.size(); i++)
  {
    if (v[x] % divisor[i] == 0)
      cnt[i]++;
    if (cnt[i] >= num - 1)
      ans[x] = max(ans[x], divisor[i]);
  }
  for (int y : a[x])
    if (y != par)
      visit(y, x, gcd, num + 1);
  for (int i = 0; i < divisor.size(); i++)
    if (v[x] % divisor[i] == 0)
      cnt[i]--;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 1; i <= v[1]; i++)
    if (v[1] % i == 0)
      divisor.push_back(i);

  ans[1] = v[1];
  for (int x : a[1])
    visit(x, 1, 0, 1);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}