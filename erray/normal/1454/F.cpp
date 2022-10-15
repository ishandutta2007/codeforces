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
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      pos[a[i]].push_back(i);
    }
    SparseTable mx(a, [&](int x, int y) {
      return max(x, y);
    });
    SparseTable mn(a, [&](int x, int y) {
      return min(x, y);
    });
    tuple<int, int, int> ans = make_tuple(-1, -1, -1);
    
    for (auto[val, all] : pos) {
      for (int i = 1; i < (int) all.size() - 1; ++i) {
        int pre = -1, suf = -1;
        {
          int low = all[0] + 1, high = all[i];
          while (low < high) {
            int mid = (low + high) >> 1;
            if (mn.get(mid, all[i]) == val) {
              high = mid;
            } else {
              low = mid + 1;
            }
          }      
          if (mx.get(0, low - 1) == val) {
            pre = low;
          }
        }
        {
          int low = all[i], high = all.back() - 1;
          while (low < high) {
            int mid = 1 + ((low + high) >> 1);
            if (mn.get(all[i], mid) == val) {
              low = mid;
            } else {
              high = mid - 1;
            }
          }      
          if (mx.get(low + 1, n - 1) == val) {
            suf = low;
          }
        }
        if (pre != -1 && suf != -1) {
          suf = n - 1 - suf;
          ans = make_tuple(pre, n - suf - pre, suf);
        }
      }
    }

    if (get<0>(ans) == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << '\n';
  }
}