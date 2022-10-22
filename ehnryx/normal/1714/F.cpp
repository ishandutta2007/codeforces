#include <bits/stdc++.h>
using namespace std;

static const char nl = '\n';

void solve() {
  int n, d12, d23, d31;
  cin >> n >> d12 >> d23 >> d31;
  if ((d12 + d23 + d31) % 2) {
    cout << "NO" << nl;
    return;
  }

  int d1 = ( d12 - d23 + d31) / 2;
  int d2 = ( d12 + d23 - d31) / 2;
  int d3 = (-d12 + d23 + d31) / 2;
  if (d1 < 0 || d2 < 0 || d3 < 0 || d1 + d2 + d3 + 1 > n) {
    cout << "NO" << nl;
    return;
  }

  cout << "YES" << nl;

  int center = 4;
  if (d1 == 0) center = 1;
  if (d2 == 0) center = 2;
  if (d3 == 0) center = 3;
  int at = (center == 4 ? 5 : 4);

  auto build = [&](int v, int d) -> void {
    if (d == 1) {
      cout << center << " " << v << nl;
    } else if(d > 1) {
      cout << v << " " << at++ << nl;
      for (int i=0; i<d-2; i++) {
        cout << at << " " << at-1 << nl;
        at++;
      }
      cout << at-1 << " " << center << nl;
    }
  };

  build(1, d1);
  build(2, d2);
  build(3, d3);

  while (at <= n) {
    cout << center << " " << at++ << nl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}