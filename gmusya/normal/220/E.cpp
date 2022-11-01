#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

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
  int n;
  ll k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  {
    map <int, int> tmp;
    for (int i = 0; i < n; i++)
      tmp[a[i]] = 0;
    int cnt = 0;
    for (auto &now : tmp)
      now.second = cnt++;
    for (int i = 0; i < n; i++)
      a[i] = tmp[a[i]];
  }
  fenwick_tree left(n), right(n);
  ll inv = 0;
  for (int i = 0; i < n; i++) {
    inv += i - left.get(a[i]);
    left.upd(a[i], 1);
  }
  int l = n - 1;
  ll ans = 0;
  for (int r = n - 1; r >= 0; r--) {
    if (l == r) {
      left.upd(a[r], -1);
      inv -= left.get(n - 1) - left.get(a[r]);
      inv -= right.get(a[r] - 1);
      l--;
    }
    right.upd(a[r], 1);
    inv += left.get(n - 1) - left.get(a[r]);
    inv += right.get(a[r] - 1);
    while (l >= 0 && inv > k) {
      inv -= right.get(a[l] - 1);
      inv -= left.get(n - 1) - left.get(a[l]);
      left.upd(a[l], -1);
      l--;
    }
    ans += l + 1;
  }
  cout << ans;
  return 0;
}