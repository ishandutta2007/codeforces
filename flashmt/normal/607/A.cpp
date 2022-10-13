#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios::sync_with_stdio(0);
  int n, f[100100] = {0};
  pair <int,int> a[100100];
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second;

  sort(a + 1, a + n + 1);

  int ans = oo;
  for (int i = 1; i <= n; i++)
  {
    int j = lower_bound(a + 1, a + i, make_pair(a[i].first - a[i].second, -1)) - a;
    f[i] = i - j + f[j - 1];
    ans = min(ans, f[i] + n - i);
  }

  cout << ans << endl;
}