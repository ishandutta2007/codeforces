#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct segment_tree {
  int n;
  vector <ll> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <ll> &a) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  int firstright(int v, int tl, int tr, int pos, ll k) {
    if (tr < pos)
      return -1;
    if (t[v] < k)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int ans = firstright(v * 2, tl, tm, pos, k);
    if (ans == -1)
      ans = firstright(v * 2 + 1, tm + 1, tr, pos, k);
    return ans;
  }
  void build(vector <ll> &a) {
    build(1, 0, n - 1, a);
  }
  int firstright(int pos, ll k) {
    return firstright(1, 0, n - 1, pos, k);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + a[i];
  segment_tree se(n);
  se.build(a);
  vector <pair <int, int>> ans;
  for (int l = 0; l < n; l++) {
    int pos = l + 1;
    while (true) {
      ll s = sum[pos] - sum[l];
      int newpos = se.firstright(pos + 1, s - a[l]);
      if (newpos == -1)
        break;
      if ((a[newpos] ^ a[l]) == sum[newpos - 1] - sum[l])
        ans.push_back({l, newpos});
      swap(pos, newpos);
    }
  }
  cout << ans.size() << '\n';
  return 0;
}