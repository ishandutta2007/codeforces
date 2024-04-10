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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<int> p;
    {
      int tn = N;
      for (int i = 2; i <= N; ++i) {
        if (tn % i == 0) {
          p.push_back(N / i);
          while (tn % i == 0) {
            tn /= i;
          }
        }
      }
    }
    int s = int(p.size());
    vector<vector<long long>> sum(s);
    multiset<long long> ms;    
    for (int i = 0; i < s; ++i) {
      sum[i].resize(p[i]);
      for (int j = 0; j < p[i]; ++j) {
        ms.insert(0);
      }
    }
    auto Add = [&](int x, int delta) {
      for (int i = 0; i < s; ++i) {
        ms.erase(ms.find(1LL * p[i] * sum[i][x % p[i]]));
        ms.insert(1LL * p[i] * (sum[i][x % p[i]] += delta));
      }
    };
    for (int i = 0; i < N; ++i) {
      Add(i, A[i]);
    }
    cout << *ms.rbegin() << '\n';
    while (Q--) {
      int P, X;
      cin >> P >> X;
      --P;
      Add(P, X - A[P]);
      A[P] = X;
      cout << *ms.rbegin() << '\n';
    }
  }
}