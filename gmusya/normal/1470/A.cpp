#include <iostream>
#include <vector>
#include <algorithm>

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
    vector <int> k(n), c(m);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
      k[i]--;
    }
    for (int i = 0; i < m; i++)
      cin >> c[i];
    sort(k.begin(), k.end());
    vector <ll> pre(n + 1);
    for (int i = 1; i <= n; i++)
      pre[i] = pre[i - 1] + c[k[i - 1]];
    vector <ll> suf(n + 1);
    for (int i = 1; i <= n; i++)
      suf[i] = suf[i - 1] + c[i - 1];
    int l = 0, r = min(n, m);
    while (l != r) {
      int M = (l + r + 1) / 2;
      bool flag = true;
      for (int j = n - M, val = 0; j < n; j++, val++)
        if (val > k[j])
          flag = false;
      if (flag)
        l = M;
      else
        r = M - 1;
    }
    ll ans = 1e18;
    for (int i = 0; i <= l; i++)
      ans = min(ans, suf[i] + pre[n - i]);
    cout << ans << '\n';
  }
  return 0;
}