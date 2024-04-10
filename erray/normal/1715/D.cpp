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
  int N, Q;
  cin >> N >> Q;
  vector<int> ad(N, (1 << 30) - 1);
  vector<vector<array<int, 2>>> qs(N);
  for (int i = 0; i < Q; ++i) {
    int I, J, X;
    cin >> I >> J >> X;
    --I, --J;
    if (I > J) {
      swap(I, J);
    }
    qs[I].push_back({J, X});
    ad[I] &= X;
    ad[J] &= X; 
  }
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    for (auto[j, x] : qs[i]) {
      a[i] |= x & ~ad[j];
    }
    for (auto[j, x] : qs[i]) {
      a[j] |= x & ~a[i];
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << a[i] << " \n"[i == N - 1];
  }
}