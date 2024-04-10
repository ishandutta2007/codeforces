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
  vector<int> fib(2, 1);
  for (int i = 1; fib.back() < int(1e9); ++i) {
    fib.push_back(fib[i] + fib[i - 1]);
  }
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    int k = 0;
    while (k < int(fib.size()) && sum > 0) {
      sum -= fib[k];
      k += 1;
    }
    int prev = -1;
    bool ok = sum == 0;
    for (int f = k - 1; f >= 0; --f) {
      int next = -1;
      for (int i = 0; i < N; ++i) {
        if (i != prev && (next == -1 || A[i] > A[next])) {
          next = i;
        }
      }
      if (next == -1 || A[next] < fib[f]) {
        ok = false;
        break;
      }
      A[next] -= fib[f];
      prev = next;
    }
    cout << (ok ? "YES" : "NO") << '\n'; 
  }
}