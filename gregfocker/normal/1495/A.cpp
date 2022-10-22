#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= 2 * n; i++) {
      int x, y;
      cin >> x >> y;
      if (x == 0) a.push_back(y);
      else b.push_back(x);
    }
    assert((int) a.size() == (int) b.size());
    assert((int) a.size() == n);
    for (auto &x : a) x *= x;
    for (auto &x : b) x *= x;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ld ret = 0;
    for (int i = 0; i < n; i++) {
      ret += sqrt(a[i] + b[n - i - 1]);
    }
    cout << fixed << setprecision(9) << ret << "\n";
  }
}