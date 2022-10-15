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
      --A[i];
    }
    vector<vector<int>> pos(N);
    for (int i = 0; i < N; ++i) {
      pos[A[i]].push_back(i);
    }
    set<int> st;
    for (auto e : A) {
      st.insert(e);
    }
    while (int(st.size()) > 1) {
      vector<int> t(st.begin(), st.end());
      vector<int> a;
      for (auto x : t) {
        a.push_back(pos[x].back());
        pos[x].pop_back();
        if (pos[x].empty()) {
          st.erase(x);
        }
      }
      for (int i = 0; i < int(a.size()) - 1; ++i) {
        swap(A[a[i]], A[a[i + 1]]);
      }
    }
    for (auto e : A) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}