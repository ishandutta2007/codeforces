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
    struct node {
      array<int, 2> to = {-1, -1};
      array<int, 2> mx = {};
    };
    vector<node> trie(1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int x = A[i] ^ i;
      int res = 0;
      for (int j = 29, v = 0; j >= 0 && v != -1; --j) {
        int b = (x >> j) & 1;
        int a = (A[i] >> j) & 1;
        if (trie[v].to[b ^ 1] != -1) {
          res = max(res, trie[trie[v].to[b ^ 1]].mx[a ^ 1]); 
        }
        v = trie[v].to[b];
      }
      ans = max(ans, res += 1);
      for (int j = 29, v = 0; j >= 0; --j) {
        int b = (x >> j) & 1;
        int id = (i >> j) & 1;
        if (trie[v].to[b] == -1) {
          trie[v].to[b] = int(trie.size());
          trie.push_back(node{});
        }
        v = trie[v].to[b];
        trie[v].mx[id] = max(trie[v].mx[id], res);
      }
    }
    cout << ans << '\n';
  }
}