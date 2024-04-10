#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long

set<int> st;

int lim = 100;

void upd() {
  vector<int> v;
  for (auto &x : st) {
    v.push_back(x);
  }
  int init = (int) st.size();
  for (auto &x : v) {
    for (auto &y : v) {
      int z = 2 * x - y;
      if (-lim <= z && z <= +lim) {
        st.insert(z);
      }
    }
  }
  if (init != (int) st.size()) {
    upd();
  }
}

int mod(int x, int y) {
  x %= y;
  if (x < 0) {
    x += y;
  }
  return x;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  /**for (int i = 1; i <= 2; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  upd();
  for (auto &x : st) {
    cout << x << "\n";
  }
  cout << "\n";
  return 0;**/

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 1; i < n; i++) {
      g = __gcd(g, a[i] - a[i - 1]);
    }
    int r1 = mod(k, g), r2 = mod(a[0], g);
    if (r1 == r2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}