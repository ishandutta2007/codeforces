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
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto x, auto y) {
      return A[x] > A[y];
    });

    vector<int> ans(N + 1);
    long long res = 0;
    int c = 0;
    for (auto i : ord) {
      c *= -1;      
      if (c >= 0) {
        c += 1;
      } 
      ans[i + 1] = c;
      res += 1LL * abs(c) * A[i];
    }

    cout << res * 2 << '\n';
    for (int i = 0; i <= N; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}