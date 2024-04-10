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
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 0; i < N - 1; ++i) {
      if (S[i] == S[i + 1]) {
        swap(ans[i], ans[i + 1]);
      }
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= ans[i] != i;
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      for (auto e : ans) {
        cout << e + 1 << ' ';
      }
      cout << '\n';
    }
  }
}