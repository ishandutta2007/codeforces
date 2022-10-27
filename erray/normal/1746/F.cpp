// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));

struct fenwick {
  vector<long long> sum;
  int n;
  fenwick(int _n) : n(_n) {
    sum.resize(n + 1, 0);
  }
  long long get(int x) {
    x += 1;
    long long res = 0;
    while (x > 0) {
      res += sum[x];
      x -= x & -x;
    }
    return res;
  }
  void modify(int x, long long d) {
    x += 1;
    while (x <= n) {
      sum[x] += d;
      x += x & -x;
    }
  }
};

#ifdef DEBUG 
  int SS = 5;
#else 
  int SS = 120;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    --A[i];
  }    
  vector<int> T(Q), L(Q), R(Q), K(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> T[i] >> L[i] >> R[i];
    --L[i], --R[i];
    if (T[i] == 2) {
      cin >> K[i];
    }
  }
  auto all = A;
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 1) {
      all.push_back(R[i]);
    }
  }
  sort(all.begin(), all.end());
  int s;
  all.resize(s = unique(all.begin(), all.end()) - all.begin());
  auto Cp = [&](int& x) {
    x = int(lower_bound(all.begin(), all.end(), x) - all.begin());
  };
  for (auto& e : A) {
    Cp(e);
  }
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 1) {  
      debug(i, R[i]);
      Cp(R[i]);
    }
  }
  debug(A);
  vector<int> ans(Q, true);
  int it = 0;
  while (clock() < 2500 && it++ <= SS) {
    vector<int> h(s);
    for (int i = 0; i < s; ++i) {
      h[i] = rng();
    }
    debug(h);
    fenwick fenw(N);
    auto a = A;
    for (int i = 0; i < N; ++i) {
      fenw.modify(i, h[a[i]]);
    }  
    for (int i = 0; i < Q; ++i) {
      if (T[i] == 1) {
        debug(L[i], R[i]);
        fenw.modify(L[i], (long long) h[R[i]] - h[a[L[i]]]);
        a[L[i]] = R[i]; 
      } else if (ans[i]) {
        long long sum = fenw.get(R[i]) - fenw.get(L[i] - 1);
        debug(L[i], R[i], K[i], sum % K[i]);
        ans[i] &= sum % K[i] == 0;
      }
    }
  }
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 2) {
      cout << (ans[i] ? "YES" : "NO") << '\n';
    }
  }
}