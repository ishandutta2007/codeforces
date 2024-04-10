#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;

int n, parent[N];
std::pair<int, int> s[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

bool merge(int a, int b) {
  if (find(a) == find(b)) {
    return false;
  }
  parent[find(a)] = find(b);
  return true;
}

std::vector<int> tree[N << 2];

int get_id(int l, int r) { return (l + r) | (l != r); }

void add(int l, int r, int a, int b, int i) {
  if (b < l || r < a) {
    return;
  }
  int id = get_id(l, r);
  if (a <= l && r <= b) {
    tree[id].push_back(i);
  } else {
    int m = (l + r) >> 1;
    add(l, m, a, b, i);
    add(m + 1, r, a, b, i);
  }
}

bool check() {
  std::sort(s, s + n);
  std::iota(parent, parent + n, 0);
  for (int i = n; i--;) {
    int y = s[i].second;
    {
      int l = 0;
      int r = (n << 1) - 1;
      while (true) {
        int id = get_id(l, r);
        for (int j : tree[id]) {
          if (!merge(i, j)) {
            return false;
          }
        }
        if (l == r) {
          break;
        }
        int m = (l + r) >> 1;
        if (y <= m) {
          r = m;
        } else {
          l = m + 1;
        }
      }
    }
    add(0, (n << 1) - 1, s[i].first, s[i].second, i);
  }
  for (int i = 0; i < n; ++i) {
    if (find(0) != find(i)) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    s[i] = {a - 1, b - 1};
  }
  puts(check() ? "YES" : "NO");
}