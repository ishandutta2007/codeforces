// author: erray
#undef DEBUG 
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

  constexpr int B = 22;
  constexpr int MAX = 1 << B;
  vector<int> first(MAX, -1);
  vector<int> second(MAX, -1);
  for (int i = N - 1; i >= 0; --i) {
    int x = A[i];
    if (first[x] == -1) {
      first[x] = i;
    } else if (second[x] == -1) {
      second[x] = i;
    }
  }
  debug(second, first);
    
  for (int i = MAX - 1; i >= 0; --i) {
    debug("start", bitset<B>(i), first[i], second[i]);    
    int s = first[i];
    for (int b = 0; b < B; ++b) {
      if ((i & (1 << b)) == 0) {
        first[i] = max(first[i], first[i ^ (1 << b)]);
      }  
    }
    if (s != first[i]) {
      second[i] = max(second[i], s);
    }
    for (int b = 0; b < B; ++b) {
      if ((i & (1 << b)) == 0) {
        int next = i ^ (1 << b);
        if (first[next] < first[i]) {
          second[i] = max(second[i], first[next]);
        } 
        if (second[next] < first[i]) {
          second[i] = max(second[i], second[next]);
        }
      } 
    }
    debug("end", bitset<B>(i), first[i], second[i]);
  }
  
  debug(first);
  debug(second);
  int ans = 0;
  for (int i = 0; i < N - 2; ++i) {
    int res = 0;
    for (int j = B - 1; j >= 0; --j) {
      bool in = (A[i] >> j) & 1;
      int next = res;
      if (!in) {
        next |= (1 << j);
      }
      if (second[next] > i) {
        swap(next, res);
      }
    }                   
    ans = max(ans, res | A[i]);
  }
  cout << ans << '\n';
}