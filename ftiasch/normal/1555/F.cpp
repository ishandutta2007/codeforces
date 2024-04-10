#include <bits/stdc++.h>

const int N = 300000;
const int M = 500000;
const int D = 20;

int n, m, dsu[N], a[M], b[M], w[M], parent[N], depth[N], sum[N], jump[N][D],
    dfs_count, pos[N], size[N];
bool on_tree[M];
std::vector<std::pair<int, int>> tree[N];

int find(int u) {
  if (dsu[u] != u) {
    dsu[u] = find(dsu[u]);
  }
  return dsu[u];
}

void dfs(int p, int u) {
  parent[u] = p;
  jump[u][0] = p;
  for (int i = 1; i < D; ++i) {
    if (jump[u][i - 1] == -1) {
      jump[u][i] = -1;
    } else {
      jump[u][i] = jump[jump[u][i - 1]][i - 1];
    }
  }
  pos[u] = dfs_count++;
  size[u] = 1;
  for (auto &&[v, w] : tree[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      sum[v] = sum[u] ^ w;
      dfs(u, v);
      size[u] += size[v];
    }
  }
}

int fenwick[N];

template <int delta> void add(int k) {
  for (; k < n; k += ~k & k + 1) {
    fenwick[k] += delta;
  }
}

int ask(int k) {
  int result = 0;
  for (; k >= 0; k -= ~k & k + 1) {
    result += fenwick[k];
  }
  return result;
}

void cover(int u) {
  add<1>(pos[u]);
  add<-1>(pos[u] + size[u]);
}

int getLCA(int u, int v) {
  if (depth[u] > depth[v]) {
    std::swap(u, v);
  }
  for (int i = D; i--;) {
    if ((depth[v] - depth[u]) >> i & 1) {
      v = jump[v][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = D; i--;) {
    if (jump[u][i] != jump[v][i]) {
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return parent[u];
}

int main() {
  scanf("%d%d", &n, &m);
  std::iota(dsu, dsu + n, 0);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", a + i, b + i, w + i);
    a[i]--;
    b[i]--;
    if (find(a[i]) != find(b[i])) {
      on_tree[i] = true;
      tree[a[i]].emplace_back(b[i], w[i]);
      tree[b[i]].emplace_back(a[i], w[i]);
      dsu[find(a[i])] = find(b[i]);
    }
  }
  memset(depth, -1, sizeof(depth));
  for (int r = 0; r < n; ++r) {
    if (depth[r] == -1) {
      depth[r] = sum[r] = 0;
      dfs(-1, r);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (on_tree[i]) {
      puts("YES");
    } else {
      // int u = a[i];
      // int v = b[i];
      int LCA = getLCA(a[i], b[i]);
      int count = ask(pos[a[i]]) + ask(pos[b[i]]) - 2 * ask(pos[LCA]);
      // while (u != v) {
      //   if (depth[u] < depth[v]) {
      //     std::swap(u, v);
      //   }
      //   count += COVER[u];
      //   u = parent[u];
      // }
      if (count > 0 || (sum[a[i]] ^ sum[b[i]] ^ w[i]) != 1) {
        puts("NO");
      } else {
        puts("YES");
        int u = a[i];
        int v = b[i];
        while (u != v) {
          if (depth[u] < depth[v]) {
            std::swap(u, v);
          }
          cover(u);
          // COVER[u] = true;
          u = parent[u];
        }
      }
    }
  }
}