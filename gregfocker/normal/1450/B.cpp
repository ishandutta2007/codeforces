#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int x[123], y[123];

int d(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
      bool now = 1;
      for (int j = 1; j <= n; j++) now &= (d(i, j) <= k);
      if (now) ok = 1;
    }
    if (ok) cout << "1\n";
    else cout << "-1\n";
  }
}