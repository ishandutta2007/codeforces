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
  }
  const int MAX = 4e6 + 5;
  vector<int> next(MAX, -1);
  vector<int> prev(MAX, -1);  
  for (int i = 0; i < N; ++i) {
    prev[A[i] - A[0]] = next[A[i] - A[0]] = A[i] - A[0];
  }
  for (int i = 0; i < MAX - 1; ++i) {
    prev[i + 1] = prev[prev[i + 1] == -1 ? i : i + 1];
  }
  for (int i = MAX - 1; i > 0; --i) {
    next[i - 1] = next[next[i - 1] == -1 ? i : i - 1];
  }
  
  int start = 0;
  while (start * (start + 1) < A[0]) {
    ++start;
  }

  while (true) {
    long long base = max(A[0] + 0LL, 1LL * start * start);
    debug(base);
    long long L = 0;
    for (int i = start; ; ++i) {
      long long from = 1LL * i * (i + 1) + 1;
      long long id = from - base;
      if (id >= MAX) {
        break;
      }
      long long x = base + next[id];
      long long tar = 1LL * (i + 1) * (i + 1);
      if (next[id] != -1 && x < tar) {
        L = max(L, tar - x);
      }
    }
       
    long long R = 1LL * start * (start + 1) - base;
    for (int i = start; ; ++i) {
      long long from = 1LL * i * (i + 1);
      long  long id = from - base;
      if (id >= MAX) {
        break;
      }
      long long x = base + prev[id];
      long long tar = 1LL * i * (i + 1);
      if (prev[id] != -1) {
        R = min(R, tar - x);
      } 
    }

    debug(L, R);
    if (L <= R) {
      cout << base + L - A[0] << '\n';
      return 0;
    }
    ++start;
  }
}