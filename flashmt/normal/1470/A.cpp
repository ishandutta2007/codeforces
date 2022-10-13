#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, a[300300], c[300300];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= m; i++)
      cin >> c[i];
    sort(a + 1, a + n + 1, greater<int>());

    long long ans = 0;
    for (int i = 1, j = 1; i <= n; i++)
      if (j <= m && c[a[i]] > c[j]) ans += c[j++];
      else ans += c[a[i]];
    cout << ans << endl;
  }
}