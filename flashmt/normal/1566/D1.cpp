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
    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n * m; i++)
      cin >> a[i];

    vector<int> id(n);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int u, int v) { return make_pair(a[u], -u) < make_pair(a[v], -v); });

    vector<int> seat(n);
    for (int i = 0; i < n; i++)
      seat[id[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        ans += seat[j] > seat[i];

    cout << ans << '\n';
  }
}