//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
  int n;
  vector<int64_t> a;
public:
  inline void add(int v, int64_t delta) {
    for (; v < n; v |= v+1) {
      a[v] += delta;
    }
  }
  
  inline int64_t sum(int v) {
    int64_t res = 0;
    for (; v >= 0; v &= v+1, v--) {
      res += a[v];
    }
    return res;
  }
  
  inline int64_t sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
  
  FenwickTree(int n)
    : n(n), a(n, 0) {
  }
};

int main() {
  int n; cin >> n;
  int64_t q; cin >> q;
  map<int, int> mp;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mp[v[i]] = 42;
  }
  int k = 0;
  for (auto &it : mp) {
    it.second = k++;
  }
  for (auto &it : v) {
    it = mp[it];
  }
  int64_t ans = 0, inv = 0;
  
  int l = 0, r = 0;
  FenwickTree fl(k), fr(k);
  for (int i = n-1; i >= 0; --i) {
    inv += fr.sum(v[i]-1);
    fr.add(v[i], +1);
  }
  
  auto incR = [&]() {
    int el = v[r++];
    inv -= fl.sum(k-1) - fl.sum(el);
    inv -= fr.sum(el-1);
    fr.add(el, -1);
  };
  
  auto incL = [&]() {
    int el = v[l++];
    inv += fl.sum(k-1) - fl.sum(el);
    inv += fr.sum(el-1);
    fl.add(el, +1);
  };
  
  while (l < n) {
    while (r < n && inv > q) {
      incR();
    }
    if (l != 0 && r != n) {
      ans += n-r;
    }
    if (l == r) {
      incR();
    }
    incL();
  }
  
  cout << ans << endl;
  return 0;
}