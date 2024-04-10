#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  i64 pref = 0;
  for (auto& x : a) {
    cin >> x;
    pref += x;
  }
  i64 mx = pref;
  for (int i = n - 1; i > 1; --i) {
    pref -= a[i];
    mx = max(mx, pref - mx);
  }
  cout << mx << '\n';
  return 0;
}