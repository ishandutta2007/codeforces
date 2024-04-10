#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, len;
  string s;
  cin >> n >> k >> len >> s;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++)
    a[i + 1] = s[i] <= 'Z';

  auto solve = [&](int penalty)
  {
    vector<pair<long long, int>> f(n + 1, pair<long long, int>(oo, 0));
    f[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
      f[i] = {f[i - 1].first + a[i], f[i - 1].second};
      int j = max(0, i - len);
      f[i] = min(f[i], make_pair(f[j].first + penalty, f[j].second + 1));
    }
    return f[n];
  };

  long long ans = oo;
  for (int turn = 0; turn < 2; turn++)
  {
    int low = 0, high = n, res = high;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (solve(mid).second > k) low = mid + 1;
      else
      {
        res = mid;
        high = mid - 1;
      }
    }

    auto [f, cnt] = solve(res);
    ans = min(ans, f - 1LL * k * res);

    for (int i = 1; i <= n; i++)
      a[i] ^= 1;
  }

  cout << ans << endl;
}