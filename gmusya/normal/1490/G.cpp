#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <ll> sum(n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
      sum[i] = sum[i - 1] + a[i];
    vector <ll> mx(n);
    mx[0] = max(0ll, sum[0]);
    for (int i = 1; i < n; i++)
      mx[i] = max(mx[i - 1], sum[i]);
    while (m--) {
      ll x;
      cin >> x;
      if (sum[n - 1] <= 0 || x <= mx[n - 1]) {
        int pos = lower_bound(mx.begin(), mx.end(), x) - mx.begin();
        if (pos == n)
          cout << -1 << ' ';
        else
          cout << pos << ' ';
        continue;
      }
      ll c = (x - mx[n - 1] + sum[n - 1] - 1) / sum[n - 1];
      ll ans = 0;
      ans += c * n;
      x -= c * sum[n - 1];
      if (!x) {
        cout << ans << ' ';
        continue;
      }
      int pos = lower_bound(mx.begin(), mx.end(), x) - mx.begin();
      ans += pos + 1;
      cout << ans - 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}