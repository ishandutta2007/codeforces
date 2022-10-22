#include <bits/stdc++.h>
using namespace std;

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

  auto guess = [](ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    ll res;
    cin >> res;
    return res;
  };

  auto answer = [](ll n) {
    cout << "! " << n << endl;
  };

  ll ans = 0;
  for(int i=0, j=2; i<25; i++, j++) {
    ll lo = guess(1, j);
    ll hi = guess(j, 1);
    if(hi != lo) {
      ans = hi + lo;
      break;
    } else if(hi == -1) {
      ans = j - 1;
      break;
    }
  }
  answer(ans);

  return 0;
}