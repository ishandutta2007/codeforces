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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, L, R, K;
    cin >> N >> L >> R >> K;
    vector<int> A(N);
    vector<int> B;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      if (A[i] < L || A[i] > R) {
        A[i] = int(1e9 + 5);
      }
    }

    sort(A.begin(), A.end());
    int ans = 0;
    for (auto e : A) {
      if (e <= K) {
        K -= e;
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
}