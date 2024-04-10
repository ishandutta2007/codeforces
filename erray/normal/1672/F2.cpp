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
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      --B[i];
    }

    vector<int> freq(N);
    for (auto e : A) {
      freq[e] += 1;
    }
    int mx = 0;
    for (int i = 0; i < N; ++i) {
      if (freq[i] > freq[mx]) {
        mx = i;
      }
    }
    vector<vector<int>> g(N);
    vector<int> indeg(N);
    for (int i = 0; i < N; ++i) {
      if (B[i] != mx && A[i] != mx) {
        g[A[i]].push_back(B[i]);    
        ++indeg[B[i]];
      }
    }
    vector<int> que;
    for (int i = 0; i < N; ++i) {
      if (indeg[i] == 0) {
        que.push_back(i);
      }
    }
    for (int t = 0; t < int(que.size()); ++t) {
      int v = que[t];
      for (auto u : g[v]) {
        if (--indeg[u] == 0) {
          que.push_back(u);
        }
      }
    }
    cout << (int(que.size()) == N ? "AC" : "WA") << '\n';
  }
}