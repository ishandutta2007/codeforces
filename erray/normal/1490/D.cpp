// author: erray
#include<bits/stdc++.h>
 
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class SparseTable {
  public:
  int sz, lg;
  vector<vector<T>> table;
  F cal;
  SparseTable() { }
  SparseTable(vector<T> v, F _cal) : cal(_cal) {
    sz = (int) v.size();
    lg = 32 - __builtin_clz(sz);
    table.resize(lg);
    table[0] = v;
    for (int i = 1; i < lg; ++i) {
      table[i].resize(sz - (1 << i) + 1);
      assert(sz - (1 << i) + 1 >= 0);
      for (int j = 0; j < (int) table[i].size(); ++j) {
        table[i][j] = cal(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < sz && l <= r);
    int clg = 31 - __builtin_clz(r - l + 1);
    return cal(table[clg][l], table[clg][r - (1 << clg) + 1]);
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> ans(n);
    function<void(int, int, int)> solve = [&](int l, int r, int x) {
      if (l > r) {
        return;
      }
      
      int mx = -1, ind = -1;
      for (int i = l; i <= r; ++i) {
        if (mx < a[i]) {
          mx = a[i];
          ind = i;
        } 
      }

      ans[ind] = x;
      solve(l, ind - 1, x + 1);
      solve(ind + 1, r, x+ 1);
    };

    solve(0, n - 1, 0);
    for (auto e : ans) {
      cout << e << ' ';
    }
    
    cout << '\n';
  }
}