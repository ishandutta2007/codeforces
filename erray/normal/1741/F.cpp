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
    vector<int> L(N), R(N), C(N);
    for (int i = 0; i < N; ++i) {
      cin >> L[i] >> R[i] >> C[i];
      --C[i];
    }
    vector<vector<int>> gs(N);
    for (int i = 0; i < N; ++i) {
      gs[C[i]].push_back(i);
    }
    multiset<int> ls(L.begin(), L.end());
    multiset<int> rs(R.begin(), R.end());
    vector<int> ans(N);
    for (int c = 0; c < N; ++c) {
      for (auto i : gs[c]) {
        ls.erase(ls.find(L[i]));
        rs.erase(rs.find(R[i]));
      }
      for (auto i : gs[c]) {
        ans[i] = int(1e9);
        if (ls.lower_bound(L[i]) != ls.end()) {
          ans[i] = (*ls.lower_bound(L[i])) - R[i];   
        }
        if (rs.lower_bound(R[i] + 1) != rs.begin()) {
          ans[i] = min(ans[i], L[i] - (*prev(rs.lower_bound(R[i] + 1))));
        }
      }
      for (auto i : gs[c]) {
        ls.insert(L[i]);
        rs.insert(R[i]);
      }
    } 
    auto Inside = [&](vector<int> s) {  
      int n = int(s.size());
      vector<int> ordr(n);
      iota(ordr.begin(), ordr.end(), 0);
      sort(ordr.begin(), ordr.end(), [&](int x, int y) {
        return R[s[x]] < R[s[y]];
      });
      vector<int> ordl(n);
      iota(ordl.begin(), ordl.end(), 0);
      sort(ordl.begin(), ordl.end(), [&](int x, int y) {
        return L[s[x]] < L[s[y]];
      });
      vector<int> res(n);
      int p = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = 0; i < n; ++i) {
        int id0 = ordr[i];
        int id = s[id0];
        while (p < n && L[s[ordl[p]]] < R[id]) {
          pq.push(R[s[ordl[p]]]);
          ++p;
        } 
        while (!pq.empty() && pq.top() <= R[id]) {
          pq.pop();
        }
        res[id0] = int(pq.size());
      }
      return res;
    };
    vector<int> foo(N);
    iota(foo.begin(), foo.end(), 0);
    auto all = Inside(foo);
    for (int i = 0; i < N; ++i) {
      auto ins = Inside(gs[i]);
      for (int j = 0; j < int(gs[i].size()); ++j) {
        if (all[gs[i][j]] != ins[j]) {
          ans[gs[i][j]] = 0; 
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      cout << max(ans[i], 0) << " \n"[i == N - 1];
    }
  }
}