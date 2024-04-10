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
    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 0);
    cout << N << '\n';
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << ans[j] + 1 << " \n"[j == N - 1];
      }
      if (i < N - 1) {
        swap(ans[i], ans[i + 1]);
      }
    }
  }
}