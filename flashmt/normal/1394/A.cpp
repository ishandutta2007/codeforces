#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  vector<long long> bad, good;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x > m) bad.push_back(x);
    else good.push_back(x);
  }

  sort(good.begin(), good.end(), greater<int>());
  for (int i = 1; i < size(good); i++)
    good[i] += good[i - 1];
  sort(bad.begin(), bad.end(), greater<int>());
  for (int i = 1; i < size(bad); i++)
    bad[i] += bad[i - 1];

  long long ans = 0;
  for (int i = 0; i + (i - 1) * d <= n && i <= bad.size(); i++)
  {
    long long score = i ? bad[i - 1] : 0;
    int rem = min(n - i - (i - 1) * d, int(size(good)));
    if (rem)
      score += good[rem - 1];
    ans = max(ans, score);
  }

  cout << ans << endl;
}