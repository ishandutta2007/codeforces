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
    sort(A.begin(), A.end());
    array<int, 2> ct = {};
    for (auto e : A) {
      if (e != 0) {
        ct[e > 0] += 1;
      }
    }
    if (max(ct[0], ct[1]) > 2) {
      cout << "NO\n";
      continue;
    }

    int p = 0;
    while (p + 1 < N && A[p + 1] <= 0) {
      ++p;
    }
    if (A[p] == 0) {
      A.erase(lower_bound(A.begin(), A.end(), 0), A.begin() + p);
    }
    N = int(A.size());
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        for (int k = j + 1; k < N; ++k) {
          ok &= binary_search(A.begin(), A.end(), A[i] + A[j] + A[k]);
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}