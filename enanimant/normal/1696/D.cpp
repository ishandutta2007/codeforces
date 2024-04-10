/*
 * author:  ADMathNoob
 * created: 06/25/22 07:35:34
 * problem: https://codeforces.com/contest/1696/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    SparseTable<int> st_min(nums, [&](int i, int j) {
      return (a[i] < a[j] ? i : j);
    });
    SparseTable<int> st_max(nums, [&](int i, int j) {
      return (a[i] > a[j] ? i : j);
    });
    int at = 0;
    int ans = 0;
    while (at < n - 1) {
      if (a[at] < a[at + 1]) {
        int low = at + 1;
        int high = n - 1;
        while (low < high) {
          int mid = (low + high + 1) / 2;
          int mn = a[st_min.get(low, mid)];
          if (mn < a[at]) {
            high = mid - 1;
          } else {
            low = mid;
          }
        }
        int to = st_max.get(at, low);
        at = to;
      } else {
        int low = at + 1;
        int high = n - 1;
        while (low < high) {
          int mid = (low + high + 1) / 2;
          int mx = a[st_max.get(low, mid)];
          if (mx > a[at]) {
            high = mid - 1;
          } else {
            low = mid;
          }
        }
        int to = st_min.get(at, low);
        at = to;
      }
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}