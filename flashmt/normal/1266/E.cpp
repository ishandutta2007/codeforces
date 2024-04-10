#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200];
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ans += a[i];
  }

  int q;
  vector<int> gain(n, 0);
  cin >> q;
  map<int, int> m[200200];
  for (int i = 0; i < q; i++)
  {
    int s, t, u;
    cin >> s >> t >> u;
    s--;
    u--;
    if (m[s].count(t))
    {
      int uu = m[s][t];
      if (uu == s) a[uu]++;
      else gain[uu]--;
      if (a[uu] > gain[uu])
        ans++;
      m[s].erase(t);
    }

    if (u >= 0)
    {
      if (s == u) a[u]--;
      else gain[u]++;
      if (a[u] >= gain[u])
        ans--;
      m[s][t] = u;
    }

    cout << ans << '\n';
  }
}