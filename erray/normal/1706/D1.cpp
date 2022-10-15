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
    const int MAX = (*max_element(A.begin(), A.end())) + 1;
    vector<vector<int>> c(MAX);
    for (auto e : A) {
      if (c[e].empty()) {
        c[e].push_back(e);
      }
    }
    int ans = MAX + 1;
    int r = MAX - 1;
    int need = MAX;
    for (int i = int(*min_element(A.begin(), A.end())); i >= 1; --i) {
      while (r > i) {
        if (need < i) {
          break;
        }
        for (auto e : c[r]) {
          if (e / K == r) {
            need = -1;
            break;
          }
          int n = min(K, e / i);
          if (e / n >= r) {
            int low = 1, high = i;
            while (low < high) {
              int mid = 1 + ((low + high) >> 1);
              int next = min(K, e / mid);
              if (e / next < r) {
                low = mid;
              } else {
                high = mid - 1;
              }
            }
            need = min(need, low);
          } 
        }
        if (need >= i) {
          for (auto e : c[r]) {
            int n = min(K, e / i);
            int next = e / n;
            //debug(i, e, n, next);
            c[next].push_back(e);
          }
          c[r].clear();
          --r;
        } else {
          break;
        }
      }
      //debug(i, r, c);
      ans = min(ans, r - i);
    }
    cout << ans << '\n';
  }
}