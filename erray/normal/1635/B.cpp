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
    int ans = 0;
    vector<int> pos;
    for (int i = 1; i < N - 1; ++i) {
      if (A[i] > max(A[i - 1], A[i + 1])) {
        pos.push_back(i);
      }
    }
    debug(pos);
    for (int i = 0; i < int(pos.size()); ++i) {
      ans += 1;
      if (i < int(pos.size()) - 1 && pos[i] == pos[i + 1] - 2) {
        A[pos[i] + 1] = max(A[pos[i]], A[pos[i] + 2]);
        ++i;
      } else {
        A[pos[i]] = max(A[pos[i] - 1], A[pos[i] + 1]);
      }
    }
    cout << ans << '\n';
    for (int i = 0; i < N; ++i) {
      cout << A[i] << ' ';
    }
    cout << '\n';
  }
}