#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) ok = false;
    if (a[i] % 2 == 1) {
      if (i + 1 == n) {
        ok = false;
        break;
      }
      a[i + 1]--;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}