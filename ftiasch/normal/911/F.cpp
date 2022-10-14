#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n;
std::vector<int> tree[N];

void dfs(std::vector<int> &d, int p, int u) {
  d[u] = ~p ? d[p] + 1 : 0;
  for (int v : tree[u]) {
    if (v != p) {
      dfs(d, u, v);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::vector<int> du(n), dv(n);
  dfs(du, -1, 0);
  int u = std::max_element(du.begin(), du.end()) - du.begin();
  dfs(du, -1, u);
  int v = std::max_element(du.begin(), du.end()) - du.begin();
  dfs(dv, -1, v);
  std::vector<bool> on_diameter(n);
  std::vector<int> diameter(du[v] + 1);
  for (int w = 0; w < n; ++w) {
    on_diameter[w] = (du[w] + dv[w] == du[v]);
    if (on_diameter[w]) {
      diameter[du[w]] = w;
    }
  }
  std::vector<int> deg(n);
  for (int w = 0; w < n; ++w) {
    deg[w] = tree[w].size();
  }
  std::vector<int> queue;
  for (int w = 0; w < n; ++w) {
    if (!on_diameter[w] && deg[w] == 1) {
      queue.push_back(w);
    }
  }
  for (size_t head = 0; head < queue.size(); ++head) {
    int u = queue[head];
    for (int v : tree[u]) {
      deg[v]--;
      if (deg[v] == 1 && !on_diameter[v]) {
        queue.push_back(v);
      }
    }
  }
  long long result = 0;
  std::vector<std::pair<int, int>> plan;
  for (int w : queue) {
    if (du[w] > dv[w]) {
      result += du[w];
      plan.emplace_back(w, u);
    } else {
      result += dv[w];
      plan.emplace_back(w, v);
    }
  }
  for (int i = diameter.size(); i-- > 1;) {
      result += i;
      plan.emplace_back(diameter[i], diameter[0]);
  }
  printf("%lld\n", result);
  for (auto [x, y] : plan) {
      printf("%d %d %d\n", x + 1, y + 1, x + 1);
  }
}