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
    vector<int> c(N + 1);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      c[A[i]] += 1;
    }
    for (int i = 0; i < N; ++i) {
      c[i + 1] += c[i];
    }
    array<int, 2> ans = {1, N};
    {
      int p = 0;
      for (int i = 0; i <= N; ++i) {
        while (p <= N && 2 * (c[p] - c[i]) - N < K) {
          ++p;
        }   
        if (p <= N && ans[1] - ans[0] > p - i - 1) {
          ans = {i + 1, p};
        }
      }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';	
    debug(ans);	
    int p = 0;
    int sum = 0;
    for (int i = 0; K > 1; ++i) {
      sum += (A[i] >= ans[0] && A[i] <= ans[1] ? 1 : -1);
      if (sum == 1) {
        cout << p + 1 << ' ' << i + 1 << '\n';
        p = i + 1;
        --K;
        sum = 0;
      }
    }
    cout << p + 1 << ' ' << N << '\n'; 
  }
}