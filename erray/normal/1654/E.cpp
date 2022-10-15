// author: erray
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
  const int B = 400;
  const int MIN = int(5e7);
  const int MAX = int(1e5);
  vector<int> ct(int(1e8));
  int ans = 0;
  vector<int> op;
  auto Add = [&](int x, int d, bool gr = false) {
    x += MIN;
    op.push_back(x);
    ct[x] += d;
    ans = max(ans, ct[x] + gr);
  };
  auto Rollback = [&] {
    for (auto x : op) {
      ct[x] = 0;
    }
    op.clear();
  };


  for (int j = -B; j <= B; ++j) {
    for (int i = 0; i < N; ++i) {
      Add(A[i] - i * j, 1);
    }
    Rollback();
  } 

  debug(ans);

  for (int i = 0; i < N; ++i) {
    for (int j = -B / 2; j <= B / 2; ++j) {
      int ind = i + j;
      if (ind < N && ind >= 0 && ind != i) {
        int diff = A[i] - A[ind];
        int idiff = i - ind;
        int x = diff / idiff;
        if (idiff * x == diff) {
          debug(i, ind, x);
          Add(x, +1, true);
        }
      }
    }
    Rollback();
  }

  cout << N - ans << '\n';
}