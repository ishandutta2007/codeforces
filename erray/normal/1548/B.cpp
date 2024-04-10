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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      d[i] = gcd(a[i] - a[i + 1], a[i + 1] - a[i]);  
    }
    SparseTable<long long> st(d, [&](long long x, long long y) {
      return gcd(x, y);
    });
    int ans = 1;
    int p = 0;
    for (int i = 0; i < n - 1; ++i) {
      while (p <= i && st.get(p, i) == 1) {
        ++p;
      }
      ans = max(ans, i - p + 2);   
    }
    cout << ans << '\n';
  }
}