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
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= (A[i] == B[i]) || (A[i] == B[i] - 1);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}