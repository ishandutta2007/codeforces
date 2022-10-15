// author: erray
#undef LOCAL
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
    #ifdef LOCAL
      for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
      } 
    #endif
    vector<int> Q(N);
    iota(Q.begin(), Q.end(), 0);
    auto Ask = [&](int x) {
      #ifdef LOCAL 
        int res = Q[x];
        vector<int> new_Q(N);
        for (int i = 0; i < N; ++i) {
          new_Q[i] = Q[P[i]];
        }
        swap(new_Q, Q);
        return res;
      #else 
        cout << "? " << x + 1 << endl;
        int res;
        cin >> res;
        --res;
        return res;
      #endif
    };
    
    vector<bool> vis(N);
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      if (vis[i]) {
        continue;
      } 
      vector<int> p;
      int x = Ask(i);
      while (!vis[x]) {
        vis[x] = true;
        p.push_back(x);
        x = Ask(i);
      }
      int s = int(p.size());
      for (int j = 0; j < s; ++j) {
        ans[p[j]] = p[(j + 1) % s];
      }
    }
    cout << "! ";
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << endl;
  }
}