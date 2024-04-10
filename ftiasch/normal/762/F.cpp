#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Tree = std::vector<std::vector<int>>;

const int N = 1'000;
const int M = 12;
const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int inverse(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int dp[N][M * 3 - 2], aux[M * 3 - 2][1 << (M - 1)];

struct Solver {
  Solver(int n_, int m_, const Tree &tree_, const Tree &topo_)
      : n{n_}, m{m_}, tree{tree_}, topo{topo_} {
    dfs(-1, 0);
  }

  void dfs(int p, int u) {
    for (int v : tree[u]) {
      if (v != p) {
        dfs(u, v);
      }
    }
    for (int i = 0; i < m * 3 - 2; ++i) {
      std::fill(aux[i], aux[i] + (1 << topo[i].size()), 0);
      aux[i][0] = 1;
    }
    for (int v : tree[u]) {
      if (v != p) {
        for (int i = 0; i < m * 3 - 2; ++i) {
          for (int mask = 1 << topo[i].size(); mask--;) {
            for (int j = 0; j < topo[i].size(); ++j) {
              if (mask >> j & 1) {
                add(aux[i][mask],
                    1LL * aux[i][mask ^ (1 << j)] * dp[v][topo[i][j]] % MOD);
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < m * 3 - 2; ++i) {
      dp[u][i] = aux[i][(1 << topo[i].size()) - 1];
      if (i < m) {
        add(result, dp[u][i]);
      }
    }
  }

  int n, m;
  const Tree &tree;
  const Tree &topo;
  int result = 0;
};

int main() {
  int n, m;
  scanf("%d", &n);
  Tree tree_s(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree_s[a].push_back(b);
    tree_s[b].push_back(a);
  }
  scanf("%d", &m);
  Tree tree_t(m);
  std::vector<int> to((m - 1) << 1);
  for (int i = 0; i < (m - 1) << 1; ++i) {
    scanf("%d", &to[i]);
    to[i]--;
  }
  for (int i = 0; i < (m - 1) << 1; ++i) {
    tree_t[to[i ^ 1]].push_back(to[i]);
  }
  Tree topo(3 * m - 2);
  for (int i = 0; i < 3 * m - 2; ++i) {
    int p = i < m ? -1 : to[(i - m) ^ 1];
    int u = i < m ? i : to[i - m];
    for (int j = 0; j < (m - 1) << 1; ++j) {
      if (to[j ^ 1] == u && to[j] != p) {
        topo[i].push_back(m + j);
      }
    }
  }
  int hom = Solver{n, m, tree_s, topo}.result;
  int aut = Solver{m, m, tree_t, topo}.result;
  printf("%d\n", static_cast<int>(1LL * hom * inverse(aut) % MOD));
}