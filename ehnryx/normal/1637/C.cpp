#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    if(n == 3) {
      if(a[1] % 2 == 0) {
        cout << a[1] / 2 << nl;
      } else {
        cout << -1 << nl;
      }
      continue;
    }

    ll ans = 0;
    bool even = false;
    bool big = false;
    for(int i=1; i<n-1; i++) {
      ans += (a[i] + 1) / 2;
      even |= (a[i] % 2 == 0);
      big |= (a[i] > 1);
    }
    if(even || big) {
      cout << ans << nl;
    } else {
      cout << -1 << nl;
    }
  }

  return 0;
}