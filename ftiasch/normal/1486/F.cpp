#include <bits/stdc++.h>

struct IO {
  IO(FILE *in = stdin) : in(in) {}

  int next_char() {
    if (position == length) {
      position = 0, length = fread(buffer, 1, LENGTH, in);
    }
    if (position == length) {
      eof = true;
      return -1;
    }
    return buffer[position++];
  }

  int next_uint() {
    int c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x;
  }

  int next_int() {
    int s = 1, c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    if (c == '-') {
      s = -1, c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x * s;
  }

  void next_string(char *s) {
    int c = next_char();
    while (c <= 32) {
      c = next_char();
    }
    for (; c > 32; c = next_char()) {
      *s++ = c;
    }
    *s = 0;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  int position = 0, length = 0;
  bool eof = false;
  FILE *in;
};

const int N = 300000;

int n, m, first_edge[N], edge[N << 1], next_edge[N << 1], degree[N],
    first_path[N], path[N << 1], next_path[N << 1], parent[N], dfs_order[N],
    LCA[N], children[N][2];

struct {
  int count, current_child[N], dsu[N];

  int find(int u) { // return the root
    if (dsu[u] == -1 || dsu[u] == u) {
      return u;
    }
    return dsu[u] = find(dsu[u]);
  }

  void dfs(int u) {
    dfs_order[count++] = u;
    for (int iterator = first_edge[u]; ~iterator;
         iterator = next_edge[iterator]) {
      int v = edge[iterator];
      if (v != parent[u]) {
        current_child[u] = v;
        parent[v] = u;
        dfs(v);
      }
    }
    current_child[u] = -1;
    dsu[u] = u;
    for (int iterator = first_path[u]; ~iterator;
         iterator = next_path[iterator]) {
      int v = path[iterator];
      if (~dsu[v]) {
        int id = iterator >> 1;
        int child = find(v);
        LCA[id] = parent[child];
        children[id][0] = child;
        children[id][1] = current_child[LCA[id]];
        if (iterator & 1) {
          std::swap(path[iterator], path[iterator ^ 1]);
        }
      }
    }
    for (int iterator = first_edge[u]; ~iterator;
         iterator = next_edge[iterator]) {
      int v = edge[iterator];
      if (v != parent[u]) {
        dsu[v] = u;
      }
    }
  }
} tarjan;

int point_count[N], point_sum[N], touch_top_count[N], touch_bot_count[N],
    touch_sum[N], sorted_touch[2][N], sorting_count[N + 1];

template <int t> int key(int i);

template <> int key<0>(int i) { return children[i][0] + 1; }

template <> int key<1>(int i) { return children[i][1] + 1; }

template <int t> void radix_sort(int m) {
  memset(sorting_count, 0, sizeof(*sorting_count) * (n + 1));
  for (int i = 0; i < m; ++i) {
    sorting_count[key<t>(sorted_touch[t + 1 & 1][i])]++;
  }
  for (int i = 1; i <= n; ++i) {
    sorting_count[i] += sorting_count[i - 1];
  }
  for (int i = m; i--;) {
    int e = sorted_touch[t + 1 & 1][i];
    sorted_touch[t & 1][--sorting_count[key<t>(e)]] =
        sorted_touch[t + 1 & 1][i];
  }
}

int main() {
  IO io;
  n = io.next_int();
  for (int i = 0; i < (n - 1) << 1; ++i) {
    edge[i] = io.next_int() - 1;
  }
  memset(degree, -1, sizeof(*degree) * n);
  memset(first_edge, -1, sizeof(*first_edge) * n);
  degree[0] = 0;
  for (int i = 0; i < (n - 1) << 1; ++i) {
    degree[edge[i]]++;
    next_edge[i] = first_edge[edge[i ^ 1]];
    first_edge[edge[i ^ 1]] = i;
  }
  m = io.next_int();
  for (int i = 0; i < m << 1; ++i) {
    path[i] = io.next_int() - 1;
  }
  memset(first_path, -1, sizeof(*first_path) * n);
  for (int i = 0; i < m << 1; ++i) {
    if (path[i] != path[i ^ 1]) {
      next_path[i] = first_path[path[i ^ 1]];
      first_path[path[i ^ 1]] = i;
    }
  }
  memset(tarjan.dsu, -1, sizeof(*tarjan.dsu) * n);
  parent[0] = -1;
  tarjan.dfs(0);
  long long result = 0;
  for (int i = 0; i < m << 1; i += 2) {
    int v = path[i];
    int u = path[i ^ 1];
    int w = LCA[i >> 1];
    // printf("LCA(%d, %d)=%d %d %d\n", v + 1, u + 1, w + 1, children[i >> 1][0]
    // + 1, children[i >> 1][1] + 1);
    if (v == u) {
      result += point_count[v]; // point - point
      point_count[v]++;
    } else {
      touch_top_count[w]++;
      touch_bot_count[children[i >> 1][0]]++;
      if (u != w) {
        touch_bot_count[children[i >> 1][1]]++;
      }
      // touch_top_count[u] - touch_bot_count[v] = # of paths P
      // * parent[u] \in P
      // * u \in P
      // * v \notin P
    }
  }
  point_sum[0] = touch_sum[0] = 0;
  for (int i = 1; i < n; ++i) {
    int u = dfs_order[i];
    int p = parent[u];
    point_sum[u] = point_sum[p] + point_count[u];
    touch_sum[u] = touch_sum[p] + (touch_top_count[u] - touch_bot_count[u]);
  }
  int touch_count = 0;
  for (int i = 0; i < m << 1; i += 2) {
    int v = path[i];
    int u = path[i ^ 1];
    int w = LCA[i >> 1];
    if (v != u) {
      // path * point
      result += point_sum[v] + point_sum[u] - 2 * point_sum[w] + point_count[w];
      // {internal, leaf} * touch
      result +=
          touch_sum[v] - touch_sum[w] + touch_bot_count[children[i >> 1][0]];
      if (u != w) {
        result +=
            touch_sum[u] - touch_sum[w] + touch_bot_count[children[i >> 1][1]];
      }
      // touch * touch
      // To ensure children[i >> 1][0] > children[i >> 1][1]
      std::sort(children[i >> 1], children[i >> 1] + 2, std::greater<int>());
      sorted_touch[0][touch_count++] = i >> 1;
    }
  }
  radix_sort<1>(touch_count);
  radix_sort<0>(touch_count);
  long long touch_pairs = 0;
  for (int i = 0; i < touch_count;) {
    int index = sorted_touch[0][i];
    int occ = 0;
    while (i + occ < touch_count &&
           children[index][0] == children[sorted_touch[0][i + occ]][0] &&
           children[index][1] == children[sorted_touch[0][i + occ]][1]) {
      occ++;
    }
    int v = children[index][0];
    int u = children[index][1];
    touch_pairs += static_cast<long long>(touch_top_count[LCA[index]] -
                                          touch_bot_count[v] +
                                          (~u ? occ - touch_bot_count[u] : 0)) *
                   occ;
    i += occ;
  }
  std::cout << result + touch_pairs / 2 << std::endl;
}