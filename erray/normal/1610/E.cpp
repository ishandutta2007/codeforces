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
    int ans = 0;
    for (int j = 0; j < N; ++j) {
      if (j > 0 && A[j] == A[j - 1]) {
        continue;
      }
      int i = j;
      int res = 0;      
      while (i < N) {
        i = int(lower_bound(A.begin() + i + 1, A.end(), 2 * A[i] - A[j]) - A.begin());
        res += 1;  
      }
      ans = max(ans, res);
    }
    cout << N - ans << '\n';
  }
}