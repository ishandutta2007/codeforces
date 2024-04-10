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
  const int MAX = int(1e6);
  vector<bool> ip(MAX + 1, true);
  ip[1] = false;
  for (int i = 2; i <= MAX; ++i) {
    if (ip[i]) {
      for (int j = i * 2; j <= MAX; j += i) {
        ip[j] = false;
      }
    }
  }
  
  int TT;
  cin >> TT;
  while (TT--) {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> A(E);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      A[i % E].push_back(X);
    }

    long long ans = 0;
    for (auto a : A) {
      vector<int> pos;
      pos.push_back(-1);
      for (int i = 0; i < int(a.size()); ++i) {
        if (a[i] != 1) {
          pos.push_back(i);
        }
      }
      pos.push_back(int(a.size()));
      debug(a, pos);
      for (int i = 1; i < int(pos.size()) - 1; ++i) {
        if (ip[a[pos[i]]]) {
          int me = pos[i];
          int next = pos[i + 1];
          int prev = pos[i - 1];
          ans += 1LL * (next - me) * (me - prev) - 1;
        } 
      }
    }
    cout << ans << '\n';
  }
}