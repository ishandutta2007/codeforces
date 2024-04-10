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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    int mx = max_element(A.begin(), A.end()) - A.begin();
    int mn = min_element(A.begin(), A.end()) - A.begin();
    cout << mx + 1 << ' ' << mn + 1 << '\n';
  }
}