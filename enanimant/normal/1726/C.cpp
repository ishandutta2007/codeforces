/*
 * author:  ADMathNoob
 * created: 09/06/22 10:35:10
 * problem: https://codeforces.com/contest/1726/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  const int n;
  vector<vector<T>> mat;
  const F f;

  SparseTable(const vector<T>& a, const F& f_) : n(a.size()), f(f_) {
    assert(n > 0);
    const int max_log = __lg(n) + 1;
    mat.resize(max_log);
    mat[0] = a;
    for (int lg = 1; lg < max_log; lg++) {
      mat[lg].resize(n - (1 << lg) + 1);
      for (int i = 0; i <= n - (1 << lg); i++) {
        mat[lg][i] = f(mat[lg - 1][i], mat[lg - 1][i + (1 << (lg - 1))]);
      }
    }
  }

  T get(int ll, int rr) const {
    assert(0 <= ll && ll <= rr && rr < n);
    const int lg = __lg(rr - ll + 1);
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
    vector<int> a(2 * n);
    vector<int> s(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
      char c;
      cin >> c;
      a[i] = (c == '(' ? +1 : -1);
      s[i + 1] = s[i] + a[i];
    }
    int mn = *min_element(s.begin(), s.end());
    int mx = *max_element(s.begin(), s.end());
    const SparseTable<int> st(s, [&](int x, int y) {
      return min(x, y);
    });
    vector<vector<int>> ids(mx - mn + 1);
    for (int i = 0; i <= 2 * n; i++) {
      ids[s[i] + mn].push_back(i);
    }
    vector<vector<int>> g(2 * n);
    int ans = 0;
    for (int x = 0; x <= mx - mn; x++) {
      const auto& v = ids[x];
      int value = x + mn;
      int sz = v.size();
      int beg = 0;
      while (beg < sz) {
        int end = beg;
        while (end + 1 < sz && st.get(v[beg], v[end + 1]) == value) {
          ++end;
        }
        if (beg < end) {
          ans += 1;
        }
        beg = end + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}