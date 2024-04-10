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
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      a[i] = (S[i] - '0') ^ (K % 2);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      if (!a[i] && K > 0) {
        a[i] = 1;
        --K;
        ans[i] = 1;
      }
    }
    if (K % 2 == 1) {
      a[N - 1] = 0;
      ans[N - 1] += 1;
      --K;
    }
    ans[0] += K;
    for (int i = 0; i < N; ++i) {
      cout << a[i];
    }
    cout << '\n';
    for (int i = 0; i < N; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}