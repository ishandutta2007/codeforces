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
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }
  vector<int> inv(N);
  for (int i = 0; i < N; ++i) {
    inv[P[i]] = i;
  }
  debug(P, inv);
  
  const int SQ = int(sqrt(N));
  vector<int> big(N);
  for (int i = 0; i < N; ++i) {
    big[i] = i;
    debug(i);
    for (int it = 0; it < SQ; ++it) {
      big[i] = P[big[i]];
      debug(big[i]);
    }
  }
  
  debug(SQ);
  for (int i = 0; i < Q; ++i) {
    int T, X, Y;
    cin >> T >> X >> Y;
    debug(big);
    debug(P);
    if (T == 1) {
      --X, --Y;
      swap(P[X], P[Y]);
      swap(inv[P[X]], inv[P[Y]]);
      for (auto e : {X, Y}) {
        int go = e;
        for (int it = 0; it < SQ; ++it) {
          go = P[go];
        }
        for (int it = 0; it <= SQ; ++it) {
          big[e] = go;
          go = inv[go];
          e = inv[e];
        }  
      }
    } else {
      --X;
      while (Y >= SQ) {
        X = big[X];
        Y -= SQ;
      }
      while (Y > 0) {
        X = P[X];
        --Y;
      }
      cout << X + 1 << '\n';
    }
  }

}