// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par;
  vector<int> size;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    size.resize(n, 1);
  }

  int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[y] = x;
    size[x] += size[y];
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    DSU d(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      --B[i];
      d.unite(A[i], B[i]);
    }

    int odd = 0;
    for (int i = 0; i < N; ++i) {
      if (d.get(i) == i) {
        debug(d.size[i]);
      }
      odd += (d.get(i) == i && d.size[i] % 2 == 1);
    }

    long long ans = 0;
    for (int i = 0; i < (N - odd) / 2; ++i) {
      ans += 2 * (N - 2 * i - 1);
    }
    cout << ans << '\n';
  }
}