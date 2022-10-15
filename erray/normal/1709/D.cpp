// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  vector<vector<T>> a;
  vector<int> logs;
  int n;
  F op;
  SparseTable() { }
  SparseTable(vector<T> _a, F _op) : op(_op) {
    n = int(_a.size());
    int lg = 32 - __builtin_clz(n);
    a.resize(lg); 
    a[0] = _a;
    for (int j = 1; j < lg; ++j) {
      int size = n - (1 << j) + 1;
      a[j].resize(size);
      for (int i = 0; i < size; ++i) {
        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);
      }
    }
    logs.resize(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      logs[i] = logs[(i >> 1)] + 1;
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = logs[r - l + 1];;
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i];
  }
  SparseTable st(A, [&](int x, int y) {
    return max(x, y);
  });
  int Q;
  cin >> Q;
  while (Q--) {
    int XS, YS, XF, YF, K;
    cin >> XS >> YS >> XF >> YF >> K;
    --XS, --YS, --XF, --YF;
    XS = N - 1 - XS, XF = N - 1 - XF;
    cout << ((XS - XF) % K == 0 && (YS - YF) % K == 0 && N - st.get(min(YF, YS), max(YF, YS)) > (XS % K) ? "YES" : "NO") << '\n';
  }
}