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
    array<vector<int>, 2> pos;
    pos[0] = {-1};
    for (int i = 0; i < N; ++i) {
      pos[A[i]].push_back(i);
    }
    pos[1].push_back(N);
    int ans = 0;
    while (pos[1][ans] < pos[0].back()) {
      ++ans, pos[0].pop_back();
    }
    cout << ans << '\n';
  }
}