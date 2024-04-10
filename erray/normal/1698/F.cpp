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
                   
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      --B[i];
    }
    
    auto Pairs = [&](vector<int> x) {
      multiset<array<int, 2>> ms;
      x.push_back(N);
      x.insert(x.begin(), -1);
      for (int i = 0; i < int(x.size()) - 1; ++i) {
        int l = x[i], r = x[i + 1];
        ms.insert({min(l, r), max(l, r)});
      }             
      return ms;
    };

    if (Pairs(A) != Pairs(B)) {
      cout << "NO\n";
      continue; 
    }
    cout << "YES\n";
    vector<pair<int, int>> ans;
    auto Rev = [&](int l, int r) {
      assert(0 <= l && l <= r && r < N);
      reverse(A.begin() + l, A.begin() + r + 1);
      ans.push_back({l, r});
    };

    for (int i = 0; i < N - 2; ++i) {
      if (A[i + 1] != B[i + 1]) {
        auto Find = [&] {
          if (A[i + 1] == B[i + 1]) {
            return true;
          }
          int p = i + 2;
          while (p < N && pair{B[i], B[i + 1]} != pair{A[p], A[p - 1]}) {
            ++p;
          }          
          if (p < N) {
            Rev(i, p);
            return true;
          } else {
            return false;
          }
        };

        if (!Find()) {
          int p = N - 2;
          while (pair{B[i], B[i + 1]} != pair{A[p], A[p + 1]}) {
            --p;
          }
          [&] {
          for (int l = i + 1; l <= p; ++l) {
            for (int r = p + 1; r < N; ++r) {
              if (A[l] == A[r]) {
                Rev(l, r);
                return;  
              }
            }
          }
          }();
          assert(Find());
        }
      } 
    }

    assert(A == B);
    cout << int(ans.size()) << '\n';
    for (auto[l, r] : ans) {
      cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }
}