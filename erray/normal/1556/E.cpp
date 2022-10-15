// author: erray
#include <bits/stdc++.h>
 
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
  int n, q;
  cin >> n >> q;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    d[i] = x - d[i];
  }
  
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + d[i];
  }

  SparseTable mx(pref, [&](auto x, auto y) {
    return max(x, y);
  });

  SparseTable mn(pref, [&](auto x, auto y) {
    return min(x, y);
  });

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if (pref[r + 1] != pref[l] || mn.get(l + 1, r + 1) < pref[l]) {
      cout << -1;
    } else {
      cout << mx.get(l + 1, r + 1) - pref[l];
    }
    cout << '\n';
  }
}