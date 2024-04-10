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

vector<pair<int, ll>> read(int n, int d) {
  vector<pair<int, ll>> out;
  for(int i=0; i<n; i++) {
    int v;
    cin >> v;
    int cnt = 1;
    while(v % d == 0) {
      v /= d;
      cnt *= d;
    }
    if(!out.empty() && v == out.back().first) {
      out.back().second += cnt;
    } else {
      out.emplace_back(v, cnt);
    }
  }
  return out;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T;
  cin >> T;
  while(T--) {
    int n, d;
    cin >> n >> d;
    auto a = read(n, d);
    int m;
    cin >> m;
    auto b = read(m, d);
    if(a == b) {
      cout << "Yes" << nl;
    } else {
      cout << "No" << nl;
    }
  }

  return 0;
}