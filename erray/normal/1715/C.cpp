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
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  auto Cost = [&](int i) {
    long long res = 0;
    for (int j = max(0, i - 1); j < min(i + 1, N - 1); ++j) {
      res += 1LL * (A[j] != A[j + 1]) * (j + 1) * (N - j - 1);
    }
    return res;
  };
  long long ans = 1LL * N * (N + 1) / 2;
  for (int i = 0; i < N - 1; ++i) {
    ans += 1LL * (A[i] != A[i + 1]) * (i + 1) * (N - i - 1);
  }
  while (M--) {
    int I, X;
    cin >> I >> X;
    --I;
    ans -= Cost(I);
    A[I] = X;
    ans += Cost(I);
    cout << ans << '\n';
  }
}