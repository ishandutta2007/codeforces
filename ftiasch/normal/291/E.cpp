#include <bits/stdc++.h>

struct Solver
{
  Solver(int n) : child(n)
  {
    for (int i = 1, p; i < n; ++ i) {
      std::string s;
      std::cin >> p >> s;
      child[p - 1].emplace_back(i, s);
    }
    std::string p;
    std::cin >> p;
    m = p.size();
    go.resize(m + 1);
    std::vector<int> fail(m + 1);
    go[0][p[0] - 'a'] = 1;
    fail[1] = 0;
    for (int i = 1; i <= m; ++ i) {
      go[i] = go[fail[i]];
      int ch = p[i] - 'a';
      if (i < m) {
        go[i][ch] = i + 1;
        fail[i + 1] = go[fail[i]][ch];
      }
    }
    dfs(0, 0, "");
  }

  void dfs(int u, int p, const std::string& s)
  {
    for (auto&& c : s) {
      p = go[p][c - 'a'];
      result += p == m;
    }
    for (auto&& e : child[u]) {
      dfs(e.first, p, e.second);
    }
  }

  int m, result = 0;
  std::vector<std::vector<std::pair<int, std::string>>> child;
  std::vector<std::array<int, 26>> go;
};

int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  while (std::cin >> n) {
    Solver solver(n);
    std::cout << solver.result << std::endl;
  }
}