#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

struct fenwick_tree {
  int n;
  vector <int> t;
  fenwick_tree(int _n) {
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
    int res = 0;
    while (pos != -1) {
      res += t[pos];
      pos &= pos + 1;
      pos--;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> p(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }
  vector <vector <int>> pairs(n);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) {
      int l = p[i], r = p[j];
      if (l > r)
        swap(l, r);
      pairs[r].push_back(l);
    }
  vector <vector <pii>> queries(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    queries[r].push_back({l, i});
  }
  fenwick_tree ft(n);
  vector <int> ans(q, -1);
  for (int i = 0; i < n; i++) {
    for (int x : pairs[i])
      ft.upd(x, 1);
    for (auto [pos, id] : queries[i])
      ans[id] = ft.get(n - 1) - ft.get(pos - 1);
  }
  for (auto &now : ans)
    cout << now << '\n';
  return 0;
}