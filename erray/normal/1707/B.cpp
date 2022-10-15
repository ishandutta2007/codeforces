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
    
    int zero = 0;
    while (int(A.size()) > 1) {
      debug(A, zero);      
      vector<int> new_A;
      if (zero > 0) {
        new_A.push_back(A[0]);
      }
      for (int i = 0; i < int(A.size()) - 1; ++i) {
        new_A.push_back(A[i + 1] - A[i]);
      }
      swap(A, new_A);
      sort(A.begin(), A.end());      
      int p = int(lower_bound(A.begin(), A.end(), 1) - A.begin());
      zero += p - (zero > 0);
      A.erase(A.begin(), A.begin() + p);
    }
    A.push_back(0);
    cout << A[0] << '\n';
  }
}