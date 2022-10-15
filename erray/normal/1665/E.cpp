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

    vector<pair<array<int, 2>, vector<int>>> trie;
    pair<array<int, 2>, vector<int>> emp;
    emp.first = {-1, -1};
    trie.push_back(emp);
    for (int i = 0; i < N; ++i) {
      int v = 0;
      for (int j = 29; j >= 0; --j) {
        int b = (A[i] >> j) & 1;
        if (trie[v].first[b] == -1) {
          trie[v].first[b] = int(trie.size());
          trie.push_back(emp);
        }
        v = trie[v].first[b];
        trie[v].second.push_back(i);
      }
    }
    
    vector<int> foo;
    int Q;
    cin >> Q;
    while (Q--) {
      int L, R;
      cin >> L >> R;
      --L, --R;
      int v = 0;
      vector<int> dump;
      int ans = 0;
      for (int i = 29; i >= 0; --i) {
        int s = 0;
        for (auto e : dump) {
          s += !((A[e] >> i) & 1);
        }
        auto& left = (v == -1 || trie[v].first[0] == -1 ? foo : trie[trie[v].first[0]].second);
        int add = int(lower_bound(left.begin(), left.end(), R + 1) - lower_bound(left.begin(), left.end(), L));
        s += add;
        int to = 0;
        if (s > 1) {
          vector<int> new_dump;
          for (auto e : dump) {
            if (!((A[e] >> i) & 1)) {
              new_dump.push_back(e);
            }
          }  
          swap(dump, new_dump);
          to = 0;
          //handle -1 case
        } else {
          if (add > 0) {
            int x = *lower_bound(left.begin(), left.end(), L);
            dump.push_back(x);
          }
          to = 1;
        }
        ans += (to << i);
        if (v != -1) {
          v = trie[v].first[to];
        }
      }
      cout << ans << '\n';
    }
  }
}