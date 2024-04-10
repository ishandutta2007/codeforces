// August 25, 2019
// https://codeforces.com/contest/1208/problem/E

/*
Submit this the next morning.

rip my Master rating, as I expected... :(
*/


#include <bits/stdc++.h>

using namespace std;


template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
  int n;
  vector<vector<int>> t;
  F f;

  SparseTable(const vector<T>& a, const F& _f) : f(_f) {
    n = (int) a.size();
    int max_log = 32 - __builtin_clz(n);
    t.resize(max_log);
    t[0] = a;
    for (int i = 1; i < max_log; i++) {
      t[i].resize(n - (1 << i) + 1);
      for (int j = 0; j <= n - (1 << i); j++) {
        t[i][j] = f(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T get(int ll, int rr) const {
    int lg = 31 - __builtin_clz(rr - ll + 1);
    return f(t[lg][ll], t[lg][rr - (1 << lg) + 1]);
  }
};


const int W = 1000005;


long long res[W];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int arrs, w;
  cin >> arrs >> w;
  while (arrs--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    SparseTable<int> st(a, [](int x, int y) {
      return max(x, y);
    });
    for (int i = 0; i < w; i++) {
      int l = max(i - (w - n), 0);
      int r = min(i, n - 1);
      int best = st.get(l, r);
      if (i >= n || i < w - n) {
        best = max(best, 0); // can put nothing in this column
      }
      res[i] += best;
      if (i == n && w >= 2 * n) {
        i = w - n;
      }
      res[i + 1] -= best;
    }
  }
  for (int i = 0; i < w; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << res[i];
    res[i + 1] += res[i];
  }
  cout << '\n';


  return 0;
}