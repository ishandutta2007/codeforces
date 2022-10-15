// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    constexpr int SUM = 100 * 100 + 1;
    bitset<SUM> bs;
    bs[0] = true;
    for (int i = 0; i < N; ++i) {
      bs = (bs << A[i]) | (bs << B[i]);
    }
    long long ans = 1E17;
    long long tot = accumulate(A.begin(), A.end(), 0) + accumulate(B.begin(), B.end(), 0);
    for (int i = 0; i < SUM; ++i) {
      if (bs[i]) {
        debug(i, i * i + (tot - i) * (tot - i));
        ans = min(ans, i * i + (tot - i) * (tot - i));
      }
    }
    long long ot = 0;
    for (auto v : {A, B}) {
      for (auto e : v) {
        ot += (N - 1) * e * e; 
        ans -= e * e;
      }
    }
    debug(ans, ot);
    cout << ans + ot << '\n';
  }
}