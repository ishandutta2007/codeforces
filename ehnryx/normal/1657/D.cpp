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


//#define MULTI_TEST
void solve_main([[maybe_unused]] int testnum, [[maybe_unused]] auto& cin) {
  // monster kills unit in t = h / D.
  // need to kill monster with min k such that H / (k * d) < t = h / D
  // so H * D < h * d * k  -->  k = ceil((H * D) / (h * d))
  // cost = min_i ceil(V / v_i) * c_i

  int n, cap;
  cin >> n >> cap;
  vector<ll> units(cap + 1);
  for(int i=0; i<n; i++) {
    int c, d, h;
    cin >> c >> d >> h;
    units[c] = max(units[c], (ll)d * h);
  }

  vector<ll> value(cap + 1);
  for(int c=1; c<=cap; c++) {
    if(!units[c]) continue;
    for(int i=1, cost=c; cost<=cap; i++, cost+=c) {
      value[cost] = max(value[cost], units[c] * i);
    }
  }
  for(int c=1; c<=cap; c++) {
    value[c] = max(value[c], value[c-1]);
  }

  int m;
  cin >> m;
  vector<tuple<ll, int>> monsters;
  for(int i=0; i<m; i++) {
    ll d, h;
    cin >> d >> h;
    auto it = upper_bound(begin(value), end(value), d * h);
    if(it == end(value)) {
      cout << -1 << " ";
    } else {
      cout << it - begin(value) << " ";
    }
  }
  cout << nl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T = 1;
#ifdef MULTI_TEST
  cin >> T;
#endif
  for(int testnum=1; testnum<=T; testnum++) {
    solve_main(testnum, cin);
  }

  return 0;
}