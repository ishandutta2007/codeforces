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

  int n, m;
  cin >> n >> m;
  vector edges(30, vector<vector<int>>(n+1));
  vector zeros(30, vector<bool>(n+1));

  vector<int> ans(n+1);
  for(int t=0; t<m; t++) {
    int i, j, x;
    cin >> i >> j >> x;
    for(int b=0; b<30; b++) {
      if(x & 1<<b) {
        if(i == j) {
          ans[i] |= 1 << b;
        } else {
          edges[b][min(i, j)].push_back(max(i, j));
        }
      } else {
        zeros[b][i] = true;
        zeros[b][j] = true;
      }
    }
  }

  for(int b=0; b<30; b++) {
    for(int i=1; i<=n; i++) {
      // skip if already one
      if(ans[i] & 1<<b) {
        continue;
      }

      bool ok = true;
      for(int j : edges[b][i]) {
        if(zeros[b][j]) {
          ok = false;
          break;
        }
      }
      if(!ok) {
        ans[i] |= 1 << b;
      } else {
        for(int j : edges[b][i]) {
          ans[j] |= 1 << b;
        }
      }
    }
  }

  for(int i=1; i<=n; i++) {
    cout << ans[i] << " ";
  }
  cout << nl;

  return 0;
}