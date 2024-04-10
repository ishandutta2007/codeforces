#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 5000 + 7;
int n, jump[N], cnt[N];

bool ok(int x) {
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  cnt[1] = x;
  for (int i = 1; i <= n; i++) {
    if (jump[i] - cnt[i] > 1) {
      return 0;
    }
    for (int j = i + 1; j <= min(n, i + jump[i]); j++) {
      cnt[j]++;
    }
    cnt[i + 1] += cnt[i] - jump[i];
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> jump[i];
    }
    int l = 0, r = (int) 1e9 * 5000, ret = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (ok(m)) {
        ret = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ret << "\n";
    assert(ret != -1);
  }
}