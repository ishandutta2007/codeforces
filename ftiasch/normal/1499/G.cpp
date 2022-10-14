#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 400'001;

int global_hash = 0;

struct Entry {
  int parent, diff, hash[2];
} dsu[N];

struct End {
  bool exists() const { return pair; }

  void clear() { pair = 0; }

  int root_edge, color, pair;
} end[N];

int merge(int e, int f) {
  assert(dsu[e].parent == e);
  assert(dsu[f].parent == f);
  if (e != f) {
    add(dsu[e].hash[0], dsu[f].hash[0]);
    add(dsu[e].hash[1], dsu[f].hash[1]);
    dsu[f].parent = e;
    dsu[f].diff ^= dsu[e].diff;
  }
  return e;
}

void flip(int x) {
  int e = end[x].root_edge;
  int y = end[x].pair;
  assert(dsu[e].parent == e);
  add(global_hash, MOD - dsu[e].hash[1]);
  add(global_hash, dsu[e].hash[0]);
  dsu[e].diff ^= 1;
  std::swap(dsu[e].hash[0], dsu[e].hash[1]);
  end[x].color ^= 1;
  end[y].color ^= 1;
}

void singleton(int e, int c, int h) {
  dsu[e].parent = e;
  dsu[e].diff = c;
  dsu[e].hash[c] = h;
  add(global_hash, dsu[e].hash[1]);
}

void add_edge(int e, int x, int y, int h) {
  if (end[y].exists()) {
    std::swap(x, y);
  }
  if (end[y].exists()) {
    // x odd y odd
    int x_p = end[x].pair;
    if (end[x].pair != y) {
      int c = end[x].color;
      int y_p = end[y].pair;
      singleton(e, c ^ 1, h);
      if (end[y].color != c) {
        flip(y);
      }
      end[x_p].root_edge = end[y_p].root_edge =
          merge(e, merge(end[x].root_edge, end[y].root_edge));
      end[x_p].pair = y_p;
      end[y_p].pair = x_p;
    } else {
      int c = end[x].color;
      assert(end[y].color == c);
      singleton(e, c ^ 1, h);
    }
    end[x].clear();
    end[y].clear();
  } else if (end[x].exists()) {
    // x odd y even
    int f = end[x].root_edge;
    int c = end[x].color;
    int x_p = end[x].pair;
    singleton(e, c ^ 1, h);
    end[x_p].root_edge = end[y].root_edge = merge(e, f);
    end[x_p].pair = y;
    end[y].color = c ^ 1;
    end[y].pair = x_p;
    end[x].clear();
  } else {
    // x even y even
    singleton(e, 1, h);
    end[x] = {e, 1, y};
    end[y] = {e, 1, x};
  }
}

int color_cache[N];

int get_color(int e) {
  if (color_cache[e] == -1) {
    int p = dsu[e].parent;
    if (p == e) {
      color_cache[e] = dsu[e].diff;
    } else {
      color_cache[e] = get_color(p) ^ dsu[e].diff;
    }
  }
  return color_cache[e];
}

int main() {
  int n1, n2, m;
  scanf("%d%d%d", &n1, &n2, &m);
  int edge_hash = 1;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    add(edge_hash, edge_hash);
    add_edge(i, x, n1 + y, edge_hash);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      add(edge_hash, edge_hash);
      add_edge(++m, x, n1 + y, edge_hash);
      printf("%d\n", global_hash);
      fflush(stdout);
    } else {
      memset(color_cache, -1, sizeof(int) * (m + 1));
      int count = 0;
      for (int i = 1; i <= m; ++i) {
        count += get_color(i);
      }
      printf("%d", count);
      for (int i = 1; i <= m; ++i) {
        if (get_color(i)) {
          printf(" %d", i);
        }
      }
      puts("");
      fflush(stdout);
    }
  }
}