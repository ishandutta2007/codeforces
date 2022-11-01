#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct fenwick_tree {
    int n;
    vector <int> t;
    explicit fenwick_tree(int _n) {
      n = _n;
      t.resize(n);
    }
    void upd(int pos, int val) {
      while (pos < n) {
        t[pos] += val;
        pos |= pos + 1;
      }
    }
    int get(int pos) {
      int result = 0;
      while (pos != -1) {
        result += t[pos];
        pos &= pos + 1;
        pos--;
      }
      return result;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n * m; ++i) {
      mp[a[i]] = 0;
    }
    int cnt = 0;
    for (auto &now : mp) {
      now.second = cnt++;
    }
    for (int i = 0; i < n * m; ++i) {
      a[i] = mp[a[i]];
    }
    fenwick_tree ft(cnt);
    int res = 0;
    for (int x : a) {
      res += ft.get(x - 1);
      ft.upd(x, 1);
    }
    cout << res << '\n';
  }
  return 0;
}