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
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    C += 1;
    vector<bool> in(C);
    vector<int> ct(C + 1);
    for (int i = 0; i < N; ++i) {
      ct[A[i]] += 1;
      in[A[i]] = true;
    }
    for (int i = 0; i < C; ++i) {
      ct[i + 1] += ct[i];
    }

    vector<bool> need(C);
    for (int i = 1; i < C; ++i) {
      if (!in[i]) {
        continue;
      }
      for (int j = 1; j * i - 1 <= C; ++j) {
        int sum = ct[min(C, (j + 1) * i - 1)] - ct[j * i - 1];  
        if (sum > 0) {
          need[j] = true;
        }
      }
    }
                     
    bool ok = true;
    for (int i = 1; i < C; ++i) {
      if (need[i] && !in[i]) {
        ok = false;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}