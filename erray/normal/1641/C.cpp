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
  int N, Q;
  cin >> N >> Q;
  vector<int> T(Q), L(Q), R(Q), X(Q), J(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> T[i];
    if (T[i] == 0) {
      cin >> L[i] >> R[i] >> X[i];
      --L[i], --R[i];
    } else {
      cin >> J[i];
      --J[i];
    }
  }
  vector<vector<int>> event(N + 1);
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 0 && X[i] == 0) {
      event[L[i]].push_back(i);
      event[R[i] + 1].push_back(~i);
    }
  }

  debug(event);

  vector<bool> bad(N); 
  vector<int> t(N, -1);
  set<int> st;
  int next = 0;
  for (int i = 0; i < N; ++i) {
    for (auto e : event[i]) {
      if (e < 0) {
        st.erase(~e);
      } else {
        st.insert(e);
      }
    }
    if (!st.empty()) {
      bad[i] = true;
      t[i] = (*st.begin());
    }
  }

  debug(bad, t);
  vector<int> inds;
  for (int i = 0; i < N; ++i) {
    if (!bad[i]) {
      inds.push_back(i);
    }
  }

  vector<int> pref(N + 1);
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + bad[i];
  }

  SparseTable tb(t, [&](int x, int y) {
    return max(x, y);
  });
  debug(inds);

  vector<int> act(N, Q + 1);
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 0 && X[i] == 1 && pref[R[i] + 1] - pref[L[i]] == (R[i] - L[i])) {
      int id = *lower_bound(inds.begin(), inds.end(), L[i]);
      act[id] = min(act[id], max(i, tb.get(L[i], R[i])));     
    }
  }

  debug(act);
  debug(t);
  debug(bad);
  for (int i = 0; i < Q; ++i) {
    if (T[i] == 1) {
      int x = J[i];
      if (act[x] < i) {
        cout << "YES";
      } else if (bad[x] && t[x] < i) {
        cout << "NO";
      } else {
        cout << "N/A";
      }
      cout << '\n';
    }
  }
}