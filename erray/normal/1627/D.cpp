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
  const int MAX = int(1e6);
  vector<bool> d(MAX + 1, false);
  for (auto e : A) {
    d[e] = true;
  } 


  for (int i = MAX; i > 0; --i) {
    int g = 0;
    for (int j = i; j <= MAX; j += i) {
      if (d[j]) {
        g = gcd(g, j);
      }
    }
    if (g == i) {
      d[i] = true;
    }
  }

  cout << accumulate(d.begin(), d.end(), 0) - N << '\n';
}