/*
 * author:  ADMathNoob
 * created: 08/01/21 10:35:13
 * problem: https://codeforces.com/contest/1548/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  const F f;

  SparseTable(const vector<T>& a, const F& _f) : f(_f) {
    n = (int) a.size();
    assert(n > 0);
    int max_log = __lg(n) + 1;
    mat.resize(max_log);
    mat[0] = a;
    for (int lg = 1; lg < max_log; lg++) {
      mat[lg].resize(n - (1 << lg) + 1);
      for (int i = 0; i <= n - (1 << lg); i++) {
        mat[lg][i] = f(mat[lg - 1][i], mat[lg - 1][i + (1 << (lg - 1))]);
      }
    }
  }

  T get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    int lg = __lg(rr - ll + 1);
    return f(mat[lg][ll], mat[lg][rr - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
      d[i] = abs(a[i + 1] - a[i]);
    }
    SparseTable<long long> st(d, [](long long x, long long y) {
      return gcd(x, y);
    });
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int low = i - 1, high = n - 2;
      while (low < high) {
        int mid = (low + high + 1) / 2;
        if (st.get(i, mid) >= 2) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      ans = max(ans, low - i + 2);
    }
    cout << ans << '\n';
  }
  return 0;
}