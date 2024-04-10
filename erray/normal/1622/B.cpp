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
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
      --P[i];
    }
    string S;
    cin >> S;
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return pair{S[x], P[x]} < pair{S[y], P[y]};
    });

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      ans[ord[i]] = i;
    }

    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}