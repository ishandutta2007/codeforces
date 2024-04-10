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
    int n;
    cin >> n;
    vector<int> a(n);
    int first = n;
    int last = -1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      if(a[i]) {
        first = min(first, i);
        last = max(last, i);
        cnt += 1;
      }
    }
    if(cnt == 0) {
      cout << 0 << nl;
    } else if(last - first + 1 == cnt) {
      cout << 1 << nl;
    } else {
      cout << 2 << nl;
    }
  }

  return 0;
}