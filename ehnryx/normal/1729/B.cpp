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
    string s;
    cin >> s;
    string ans;
    for(int i=n-1; i>=0; ) {
      if(s[i] == '0') {
        ans.push_back(stoi(s.substr(i-2, 2)) + 'a' - 1);
        i -= 3;
      } else {
        ans.push_back(s[i] - '0' + 'a' - 1);
        i -= 1;
      }
    }
    reverse(begin(ans), end(ans));
    cout << ans << nl;
  };

  int T;
  cin >> T;
  while(T--) {
    solve();
  }

  return 0;
}