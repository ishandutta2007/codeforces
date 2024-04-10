/*
 * author:  ADMathNoob
 * created: 11/28/21 09:35:20
 * problem: https://codeforces.com/contest/1609/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;  // get that inverse Ackermann time complexity
  vector<int> v;   // version
  int comps;
  int ver;

  Dsu(int _n) : n(_n) {
    p.resize(n, -1);
    sz.resize(n, 1);
    v.resize(n, 0);
    comps = n;
    ver = 0;
  }

  inline int get(int x) {
    if (v[x] != ver) {
      p[x] = -1;
      sz[x] = 1;
      v[x] = ver;
    }
    return (p[x] == -1 ? x : (p[x] = get(p[x])));
  }

  inline bool same(int x, int y) {
    return (get(x) == get(y));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    --comps;
    return true;
  }

  inline void reset() {
    comps = n;
    ++ver;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> x(d), y(d);
  for (int i = 0; i < d; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  for (int k = 1; k <= d; k++) {
    Dsu ds(n);
    int added = 0;
    for (int i = 0; i < k; i++) {
      added += ds.unite(x[i], y[i]);
    }
    vector<int> sizes;
    for (int i = 0; i < n; i++) {
      if (ds.get(i) == i) {
        sizes.push_back(ds.sz[i]);
      }
    }
    sort(sizes.rbegin(), sizes.rend());
    int rem = k - added;
    int ans = sizes[0];
    for (int i = 1; i <= rem; i++) {
      ans += sizes[i];
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}