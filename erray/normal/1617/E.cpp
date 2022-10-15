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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  const int LG = __lg(int(1e9)) + 2;
  vector<int> emp(LG, -1);
  vector<vector<int>> trie(1, emp);
  vector<int> d(1, 0);
  vector<int> mx(1, -1);

  for (int id = 0; id < N; ++id) {
    int ctz = __builtin_ctz(A[id]);
    A[id] >>= ctz + 1;
    vector<int> push;
    push.push_back(ctz);
    int prev = -1;

    debug(A[id]);
    for (int i = 1; i <= A[id]; i <<= 1) {
      int b = !!(A[id] & i);
      if (prev != b) {
        push.push_back(0);      
      }
      push.back() += 1;
      prev = b;
    }

    debug(id, push);
    int v = 0;
    for (auto e : push) {
      if (trie[v][e] == -1) {
        trie[v][e] = int(trie.size());
        trie.push_back(emp);
        d.push_back(d[v] + 1);
        mx.push_back(-1);
      }
      v = trie[v][e];
    }
    mx[v] = id;
  }
  debug(d);
  debug(mx);
  
  array<int, 3> ans = {-1, -1, -1};
  int s = int(trie.size());
  vector<int> fd = d;
  for (int i = s - 1; i >= 0; --i) {
    for (auto u : trie[i]) {
      if (u != -1) {
        if (mx[i] != -1) {
          ans = max(ans, array{d[i] + d[u] - 2 * fd[i], mx[i], mx[u]});
        }
        if (d[i] < d[u]) {
          mx[i] = mx[u];
          d[i] = d[u];
        }
      }
    }
  }

  cout << ans[1] + 1 << ' ' << ans[2] + 1 << ' ' << ans[0] << '\n';
}