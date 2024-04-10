#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int value[N], left[N], right[N];
std::set<int> ok;

void dfs(int u, int l, int r) {
  if (~u) {
    if (l <= value[u] && value[u] <= r) {
      ok.insert(value[u]);
    }
    dfs(left[u], l, std::min(r, value[u] - 1));
    dfs(right[u], std::max(l, value[u] + 1), r);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<bool> is_root(n, true);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &value[i], &left[i], &right[i]);
    if (~left[i]) {
      is_root[--left[i]] = false;
    }
    if (~right[i]) {
      is_root[--right[i]] = false;
    }
  }
  int root = std::find(is_root.begin(), is_root.end(), true) - is_root.begin();
  dfs(root, 0, 1'000'000'000);
  int result = n;
  for (int i = 0; i < n; ++ i) {
      result -= ok.count(value[i]);
  }
  printf("%d\n", result);
}