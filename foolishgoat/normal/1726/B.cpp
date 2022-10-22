#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (n & 1) {
    if (m < n) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    for (int i = 0; i < n-1; ++i)
      cout << "1 ";
    cout << m - (n-1) << "\n";
  } else {
    if (m & 1) {
      cout << "NO\n";
      return;
    }
    if (m < n) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 2; ++i) {
      cout << "1 ";
    }
    int res = (m - (n-2)) / 2;
    cout << res << " " << res << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}