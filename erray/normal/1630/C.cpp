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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    --A[i];
  }
  vector<int> last(N);
  for (int i = 0; i < N; ++i) {
    last[A[i]] = i;
  }

  debug(A);
  debug(last);

  int ans = 0;
  for (int i = 0; i < N;) {
    int p = i;
    int used = 0;
    while (i <= p) {
      int next = 0;
      while (i <= p) {
        next = max(next, last[A[i]]);
        ++i;
      }
      if (next > p) {
        used += 1;      
        p = next;
      }
    }  
    debug(used);
    debug(i, p);
    ans += used + 1;
  }
  cout << N - ans << '\n';  
    
}