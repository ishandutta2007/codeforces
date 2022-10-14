#include <bits/stdc++.h>

const int N = 300001;

int n, q, a[N];
std::vector<int> tree[N];
uint64_t x[N];

struct Node;

using Tree = Node *;

Tree null, sum[N];

struct Node {
  static Tree merge(Tree a, Tree b) { return new Node{a, b, a->s ^ b->s}; }

  Tree insert(int l, int r, int k, uint64_t v) {
    if (l == r) {
      return new Node{null, null, s ^ v};
    } else {
      int m = (l + r) >> 1;
      if (k <= m) {
        return merge(left->insert(l, m, k, v), right);
      } else {
        return merge(left, right->insert(m + 1, r, k, v));
      }
    }
  }

  Tree left, right;
  uint64_t s;
};

using Tree4 = std::array<Tree, 4>;

Tree4 get_left(const Tree4 &t) {
  return {t[0]->left, t[1]->left, t[2]->left, t[3]->left};
}

Tree4 get_right(const Tree4 &t) {
  return {t[0]->right, t[1]->right, t[2]->right, t[3]->right};
}

uint64_t get_s(const Tree4 &t) { return t[0]->s ^ t[1]->s ^ t[2]->s ^ t[3]->s; }

uint64_t get_s(const Tree4 t, int l, int r, int a, int b) {
  if (b < l || r < a) {
    return 0;
  }
  if (a <= l && r <= b) {
    return get_s(t);
  }
  int m = (l + r) >> 1;
  return get_s(get_left(t), l, m, a, b) ^ get_s(get_right(t), m + 1, r, a, b);
}

int lower[N], upper[N], parent[N], dsu[N], result[N];
bool visited[N];
std::vector<std::pair<int, int>> queries[N];

int find(int u) {
  if (dsu[u] != u) {
    dsu[u] = find(dsu[u]);
  }
  return dsu[u];
}

void dfs(int u) {
  int p = parent[u];
  sum[u] = sum[p]->insert(1, n, a[u], x[a[u]]);
  for (int v : tree[u]) {
    if (v != p) {
      parent[v] = u;
      dfs(v);
    }
  }
  visited[u] = true;
  for (auto &&q : queries[u]) {
    int v = q.first;
    int i = q.second;
    if (visited[v]) {
      int w = find(v);
      Tree4 t{sum[u], sum[v], sum[w], sum[parent[w]]};
      if (get_s(t, 1, n, lower[i], upper[i]) == 0) {
        result[i] = -1;
      } else {
        int l = 1;
        int r = n;
        while (l < r) {
          int m = (l + r) >> 1;
          bool dir;
          if (upper[i] <= m) {
            dir = false;
          } else if (m < lower[i]) {
            dir = true;
          } else if (get_s(get_left(t), l, m, lower[i], upper[i]) == 0) {
            dir = true;
          } else {
            dir = false;
          }
          if (dir) {
            l = m + 1;
            t = get_right(t);
          } else {
            r = m;
            t = get_left(t);
          }
        }
        result[i] = l;
      }
    }
  }
  dsu[u] = p;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  std::mt19937_64 gen{0};
  for (int i = 1; i <= n; ++i) {
    x[i] = gen();
  }
  tree[0].push_back(1);
  for (int i = 0, x, y; i < n - 1; ++i) {
    scanf("%d%d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  for (int i = 0, u, v; i < q; ++i) {
    scanf("%d%d%d%d", &u, &v, lower + i, upper + i);
    queries[u].emplace_back(v, i);
    if (u != v) {
      queries[v].emplace_back(u, i);
    }
  }
  parent[1] = 0;
  std::iota(dsu, dsu + (n + 1), 0);
  null = new Node{nullptr, nullptr, 0};
  null->left = null->right = null;
  sum[0] = null;
  dfs(1);
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}