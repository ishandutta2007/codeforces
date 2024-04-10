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
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return A[x] < A[y];
    });
    
    vector<int> mx(N + 1);
    for (int i = 0; i < N; ++i) {
      mx[i + 1] = max(mx[i], B[ord[i]]);
    }

    string ans(N, '0');
    int cmn = mx[N];
    for (int i = N - 1; i >= 0; --i) {
      int x = ord[i];
      if (mx[i + 1] >= cmn) {
        cmn = min(cmn, B[x]);
        ans[x] = '1';
      }
    }
    cout << ans << '\n';
  }
}