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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m, 0);
    while (n--)
    {
      int x;
      cin >> x;
      cnt[x % m]++;
    }

    int ans = 0;
    if (cnt[0])
      ans++;
    for (int i = 1; i * 2 < m; i++)
      if (cnt[i] && cnt[m - i]) ans += max(1, abs(cnt[i] - cnt[m - i]));
      else ans += cnt[i] + cnt[m - i];
    if (m % 2 == 0 && cnt[m / 2])
      ans++;
    cout << ans << endl;
  }
}