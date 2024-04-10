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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    if (K == N) {
      cout << int(1e9) << '\n';
      continue;
    }	
    int mx = 0;
    for (int i = 0; i < N - 1; ++i) {
      mx = max(mx, min(A[i], A[i + 1]));
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < N; ++i) {
      mp[A[i]].push_back(i);
    }
    int ans = 0;
    int moves = 0;
    debug(mp);
    for (auto[x, v] : mp) {
      if (moves == 0 && K == 1) {
        ans = max(ans, min(x * 2, *max_element(A.begin(), A.end())));
      } else if (moves == K) {
        ans = max(ans, min(x * 2, mx)); 
      } else {
        ans = max(ans, x * 2);
      }
      if (moves + int(v.size()) > K) {
        break;
      }
      moves += int(v.size());
      for (auto e : v) {
        A[e] = int(1e9);
        if (e > 0) {
          mx = max(mx, A[e - 1]);
        }
        if (e < N - 1) {
          mx = max(mx, A[e + 1]);
        }
      }
    }
    cout << min(ans, int(1e9)) << '\n';
  }
}