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
    string s;
    cin >> s;
    vector<vector<int>> idx(26);
    for(int i=0; i<size(s); i++) {
      idx[s[i] - 'a'].push_back(i);
    }
    bool rev = (s.front() > s.back());
    if(rev) {
      swap(s.front(), s.back());
      for(auto& v : idx) {
        reverse(begin(v), end(v));
      }
    }
    vector<int> ans;
    for(int i = s.front() - 'a'; i <= s.back() - 'a'; i++) {
      ans.insert(end(ans), begin(idx[i]), end(idx[i]));
    }
    if(rev) {
      reverse(begin(ans), end(ans));
    }
    cout << abs(s.front() - s.back()) << " " << size(ans) << nl;
    for(int i : ans) {
      cout << i + 1 << " ";
    }
    cout << nl;
  };

  int T;
  cin >> T;
  while(T--) {
    solve();
  }

  return 0;
}