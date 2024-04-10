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
  string S;
  cin >> N >> S;
  vector<int> val(1 << N);
  for (int i = 0; i < (1 << N); ++i) {
    val[i] = S[i];
  }

  vector<int> ord(1 << N);
  iota(ord.begin(), ord.end(), 0);

  for (int l = 0; l < N; ++l) {
    vector<array<int, 2>> c(1 << N);
    for (int i = 0; i < (1 << N); ++i) {
      c[i] = array{val[i], val[i ^ (1 << l)]};
    }
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return c[x] < c[y];
    });

    val[ord[0]] = 0;
    for (int i = 1; i < (1 << N); ++i) {
      val[ord[i]] = val[ord[i - 1]] + (c[ord[i]] != c[ord[i - 1]]);      
    }
  }

  for (int i = 0; i < (1 << N); ++i) {
    cout << S[i ^ ord[0]];
  }
}