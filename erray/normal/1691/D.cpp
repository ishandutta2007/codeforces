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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<long long> pref(N + 1);
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i] + A[i];
    }
    vector<long long> suf(N + 1);
    for (int i = N - 1; i >= 0; --i) {
      suf[i] = suf[i + 1] + A[i];
    }
    auto max_func = [&](long long x, long long y) {
      return max(x, y);
    };
    SparseTable pref_mx(pref, max_func);
    SparseTable suf_mx(suf, max_func);
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return A[x] > A[y];
    });
    set<int> st = {-1, N};
    bool ok = true;
    for (auto i : ord) {
      auto it = st.lower_bound(i);
      int R = *it;
      int L = *prev(it);
      long long p = pref_mx.get(i + 1, R) - pref[i + 1];
      long long s = suf_mx.get(L + 1, i) - suf[i];
      debug(i, L, R, p, s);
      ok &= (p + s + A[i] <= A[i]);
      st.insert(i);  
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}