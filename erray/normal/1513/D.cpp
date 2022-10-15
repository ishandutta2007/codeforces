// author: erray
#include <bits/stdc++.h>
 
using namespace std;

struct dsu {
  vector<int> par, sz;
  dsu(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  int size(int v) {
    return sz[get(v)];
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, ex;
    cin >> n >> ex;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto x, auto y) {
      return a[x] < a[y];
    });

    long long ans = 0;
    int added = 0;   
    dsu d(n);
    for (auto i : ord) {
      if (a[i] >= ex) {
        continue;
      }
      
      {
        int p = i;
        while (p < n - 1 && a[p + 1] % a[i] == 0 && d.unite(i, p + 1)) {
          ++p;
          ++added;
          ans += a[i];
        }
      }

      {
        int p = i;
        while (p > 0 && a[p - 1] % a[i] == 0 && d.unite(i, p - 1
        )) {
          --p;
          ++added;
          ans += a[i];
        }
      }
    } 
    cout << ans + (n - 1 - added) * 1LL * ex << '\n';
  }
}