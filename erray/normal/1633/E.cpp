#undef _GLIBCXX_DEBUG
// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n);
    sz.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    sz[x] += sz[y];
    par[y] = x;
    return true;
  }
  int size(int v) {
    return sz[get(v)];
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> E(M);
  for (int i = 0; i < M; ++i) {
    cin >> E[i][1] >> E[i][2] >> E[i][0];
    --E[i][1], --E[i][2];
  }
  sort(E.begin(), E.end());
  vector<int> ds;
  for (int i = 0; i < M; ++i) {
    for (int j = i; j < M; ++j) {
      ds.push_back((E[i][0] + E[j][0]) / 2 + 1);
    }
  }
  ds.push_back(0);
  sort(ds.begin(), ds.end());
  ds.erase(unique(ds.begin(), ds.end()), ds.end());

  int P, K, A, B, C;
  cin >> P >> K >> A >> B >> C;
  vector<int> Q(K);
  for (int i = 0; i < P; ++i) {
    cin >> Q[i];
  }
  for (int i = P; i < K; ++i) {
    Q[i] = (1LL * Q[i - 1] * A + B) % C; 
  }
  sort(Q.begin(), Q.end());
  debug(Q);
  int p = 0;
  int coeff = 0;
  long long cons = 0; 
  long long ans = 0;
  for (auto x : Q) {
    bool ch = false;
    while (p < int(ds.size()) && ds[p] <= x) {
      ++p;
      ch = true;
    }   
    debug(p);

    if (ch) {
      for (int i = 0; i < M; ++i) {
        int pi = i;
        while (pi > 0 && pair{abs(ds[p - 1] - E[pi][0]), -E[pi][0]} < pair{abs(ds[p - 1] - E[pi - 1][0]), -E[pi - 1][0]}) {
          swap(E[pi], E[pi - 1]);
          --pi;
        }
      }

      debug(E);
      coeff = 0;
      cons = 0;
      DSU d(N);
      for (auto[w, v, u] : E) {
        if (d.unite(v, u)) {
          if (w <= x) {
            coeff += 1;
            cons -= w;
          } else {
            coeff -= 1;
            cons += w;
          }
        }
      }
    }

    debug(cons, coeff);
    long long res = cons + 1LL * coeff * x;
    ans ^= res;
  }
  cout << ans << '\n';
}