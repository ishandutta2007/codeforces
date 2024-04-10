#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n, d[N], pre[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + d[i];
    }
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (i - 2 < 1) continue;
      sol += d[i] * (i - 2);
      sol -= pre[i - 2];
      continue;
      for (int j = 1; j <= i - 2; j++) {
        sol += d[i] - d[j];
      }
    }
    sol *= -1;
    cout << sol << "\n";
  }

  return 0;
}