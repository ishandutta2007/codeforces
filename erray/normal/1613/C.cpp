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
    long long H;
    cin >> N >> H;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    auto Can = [&](long long x) {
      long long res = 0;
      for (int i = 0; i < N; ++i) {
        res += min(x, (i == N - 1 ? A[i] + x : 0LL + A[i + 1] - A[i]));
        debug(res);
        res = min(res, H);
      }
      debug(res);
      return (res == H);
    };

    long long low = 1, high = H;
    while (low < high) {
      long long mid = (low + high) >> 1;
      if (Can(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << low << '\n';
  }
}