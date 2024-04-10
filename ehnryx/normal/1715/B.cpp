#include <bits/stdc++.h>
using namespace std;

//%:include "utility/defines.h"
//%:include "utility/fast_input.h"
//%:include "utility/output.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T;
  cin >> T;
  while(T--) {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    // bi = floor(ai/k)
    // k*bi <= ai <= k*bi + k-1
    // k*b <= s <= k*b + (k-1)*n
    if(not (k*b <= s and s <= k*b + (k-1)*n)) {
      cout << -1 << nl;
      continue;
    }

    ll extra = s - k*b;
    for(int i=0; i<n; i++) {
      if(i == 0) {
        cout << k*b + min(extra, k-1);
      } else {
        cout << " " << min(extra, k-1);
      }
      extra -= min(extra, k-1);
    }
    cout << nl;
  }

  return 0;
}