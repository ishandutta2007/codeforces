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
    int N, A, B;
    cin >> N >> A >> B;
    if (abs(A - B) > 1 || (A + B) > N - 2) {
      cout << -1 << '\n';
      continue;
    }
    bool r = false;
    if (A < B) {
      r = true;
      swap(A, B);
    }
    debug(N, A, B, r);
    vector<int> ans(N, -1);
    for (int i = 0; i <= B; ++i) {
      ans[i * 2] = i;
    }
    for (int i = 0; i < A; ++i) {
      ans[i * 2 + 1] = (N - i - 1);
    }
    debug(ans);
    for (int i = 0; i < N - A - B - 1; ++i) {
      ans[max(B * 2, 2 * A - 1) + 1 + i] = (B == A ? B + i + 1 : N - A - 1 - i);
      debug(ans);
    }
    for (auto e : ans) {
      cout << (r ? N - e : e + 1) << ' ';
    }
    cout << '\n';
  }
}