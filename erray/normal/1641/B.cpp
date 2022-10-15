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
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= count(A.begin(), A.end(), A[i]) % 2 == 0;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }

    vector<int> ans;
    vector<array<int, 2>> add;
    while (!A.empty()) {
      int p = N - 2;
      while (A[p] != A.back()) {
        --p;
      }
      debug(A, p);	
      int ind = p;
      for (int i = N - 2; i > p; --i) {
        debug(A[i]);
        add.push_back({ind, A[i]});
        ++ind;
      }
      A.erase(A.end() - 1);
      A.erase(A.begin() + p);
      reverse(A.begin() + p, A.end());
      ans.push_back((N - p - 1) * 2);
      N -= 2;
    }

    cout << int(add.size()) << '\n';
    for (auto[p, c] : add) {
      cout << p << ' ' << c << '\n';
    }
    reverse(ans.begin(), ans.end());
    cout << int(ans.size()) << '\n';
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}