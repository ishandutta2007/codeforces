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

  auto solve = []{
    int a, b, c;
    cin >> a >> b >> c;
    int first = abs(a - 1);
    int second = abs(b - c) + abs(c - 1);
    if(first < second) {
      cout << 1 << nl;
    } else if(first > second) {
      cout << 2 << nl;
    } else {
      cout << 3 << nl;
    }
  };

  int T;
  cin >> T;
  while(T--) {
    solve();
  }

  return 0;
}