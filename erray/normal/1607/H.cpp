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
  int tt;
  cin >> tt;
  while (tt--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N), M(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i] >> B[i] >> M[i];
      M[i] = A[i] + B[i] - M[i];
    }

    vector<int> all;
    for (int i = 0; i < N; ++i) {
      all.push_back(M[i]);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int size = int(all.size());
    vector<vector<array<int, 3>>> rg(size);
    for (int i = 0; i < N; ++i) {
      int r = min(M[i], A[i]);
      int l = max(M[i] - B[i], 0); 
      rg[int(lower_bound(all.begin(), all.end(), M[i]) - all.begin())].push_back({l, r, i}); 
    }


    vector<int> ans(N);
    int res = 0;
    for (auto a : rg) {
      sort(a.begin(), a.end());
      const int inf = int(1e7);
      a.push_back({inf, inf, -1});      
      int mn = inf;
      int p = 0;
      for (int i = 0; i < int(a.size()); ++i) {
        auto[l, r, id] = a[i];
        if (l > mn) {
          while (p < i) {
            ans[a[p][2]] = mn;
            ++p;
          }
          res += 1;
          mn = inf;
        } 
        mn = min(mn, r);
      }
    }
    cout << res << '\n';
    for (int i = 0; i < N; ++i) {
      cout << A[i] - ans[i] << ' ' << B[i] - (M[i] - ans[i]) << '\n';
    } 
  }
}