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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for_each(begin(a), end(a), [](auto& x) { cin >> x; });
    for_each(begin(b), end(b), [](auto& x) { cin >> x; });
    vector<int> x;
    transform(begin(a), end(a), begin(b), back_inserter(x),
        [](int ai, int bi) { return bi - ai; });
    ranges::sort(x, greater<>());
    int ans = 0;
    for(int i=0, j=n-1; i<j; i++, j--) {
      while(j > i && x[i]+x[j] < 0) {
        j--;
      }
      if(j <= i) break;
      ans++;
    }
    cout << ans << nl;
  };

  int T; cin >> T; while(T--) solve();

  return 0;
}