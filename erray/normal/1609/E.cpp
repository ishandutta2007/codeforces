// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;        
  string ST;
  cin >> ST;
  while (__builtin_popcount(N) > 1) {
    ++N;
    ST += 'A';
  }

  using T = array<array<array<int, 3>, 3>, 2>;
  vector<T> tree((N << 1));
  auto I = [&](T& x) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          x[i][j][k] = N + 1;
        }
      }
    }
  };

  for (int i = 0; i < (N << 1); ++i) {
    I(tree[i]);
  }


  auto Merge = [&](T L, T R) {
    T res;
    I(res);
    for (int ll = 0; ll < 3; ++ll) {
      for (int lr = 0; lr < 3; ++lr) {
        for (int lb = 0; lb < 2; ++lb) {
          for (int rl = 0; rl < 3; ++rl) {
            for (int rr = 0; rr + ll < 3; ++rr) {
              for (int rb = 0; rb < 2; ++rb) {
                int new_b = rb || lb;
                int new_l = max(ll + (rb && ll == 1), rl);
                int new_r = max(rr + (lb && rr == 1), lr);
                int &p = res[new_b][new_l][new_r];
                p = min(p, L[lb][ll][lr] + R[rb][rl][rr]);
              }
            }
          }
        }
      }
    }

    return res;
  };


  auto Modify = [&](int p, char c) {
    debug(p, c);
    p += N;
    I(tree[p]);
    tree[p][0][0][0] = 1;
    if (c == 'a') {
      tree[p][0][1][0] = 0;
    } else if (c == 'c') {
      tree[p][0][0][1] = 0;         
    } else {
      tree[p][1][0][0] = 0;               
    }

    debug(p, tree[p]);

    while (p > 1) {
      p >>= 1;
      tree[p] = Merge(tree[p << 1], tree[(p << 1) | 1]);
      debug(p, tree[p]);
    }

  };

  for (int i = 0; i < N; ++i) {
    Modify(i, ST[i]);  
  }
  

  for (int it = 0; it < Q; ++it) {
    int P;
    char C;
    cin >> P >> C;
    Modify(P - 1, C);
    int ans = N + 1;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          ans = min(ans, tree[1][i][j][k]);
        }
      }
    }
    cout << ans << '\n';
  }
}