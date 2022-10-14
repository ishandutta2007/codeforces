// #include "debug.h"

#include <bits/stdc++.h>

const int N = 3000;
const int M = 3000;

int n, m, head[N], to[M << 1], next[M << 1], dfn[N], low[N], size[N],
    child_index[N], number_of_odd, parity[N], dsu[N];
bool used[M], connected[N];
std::vector<int> children[N], plan;

void prepare(int &&clock, int p, int u) {
  low[u] = dfn[u] = clock++;
  size[u] = 1;
  int number_of_child = 0;
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    int v = to[iterator];
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      if (~dfn[v]) {
        // back
        low[u] = std::min(low[u], dfn[v]);
      } else {
        children[u].push_back(v);
        child_index[v] = ++number_of_child;
        // tree
        prepare(std::move(clock), u, v);
        low[u] = std::min(low[u], low[v]);
        size[u] += size[v];
      }
    }
  }
}

int find_root(int u) {
  if (dsu[u] != u) {
    dsu[u] = find_root(dsu[u]);
  }
  return dsu[u];
}

int get_component_id(int u, int v) {
  assert(u != v);
  if (dfn[v] < dfn[u] || dfn[u] + size[u] <= dfn[v]) {
    return 0;
  }
  int subtree = find_root(v);
  return low[subtree] < dfn[u] ? 0 : child_index[subtree];
}

void euler(int u) {
  while (~head[u]) {
    int iterator = head[u];
    head[u] = next[head[u]];
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      euler(to[iterator]);
    }
  }
  plan.push_back(u);
}

void make_plan(int c, const std::vector<int> &star_edge_indexes) {
  memset(used, 0, sizeof(*used) * m);
  for (int i : star_edge_indexes) {
    used[i >> 1] = true;
  }
  memset(head, -1, sizeof(*head) * n);
  for (int i = 0; i < m << 1; ++i) {
    if (!used[i >> 1]) {
      next[i] = head[to[i ^ 1]];
      head[to[i ^ 1]] = i;
    }
  }
  memset(used, 0, sizeof(*used) * m);
  euler(c);
  plan.push_back(-1);
  for (int i : star_edge_indexes) {
    int v = to[i];
    plan.push_back(v);
    plan.push_back(c);
  }
}

bool work(int u) {
  // std::cerr << __FUNCTION__ << " " << KV(u) << std::endl;
  for (int v : children[u]) {
    if (work(v)) {
      return true;
    }
  }
  int number_of_child = children[u].size();
  memset(connected, 0, sizeof(*connected) * (number_of_child + 1));
  int current_number_of_odd = number_of_odd - parity[u];
  int current_parity_of_u = 0;
  std::vector<int> star_edge_indexes;
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    int v = to[iterator];
    if (parity[v]) {
      // remove (u, v)
      // parity[v] changes
      current_number_of_odd--;
      star_edge_indexes.push_back(iterator);
    } else {
      // add (u, v)
      current_parity_of_u ^= 1;
      connected[get_component_id(u, v)] = true;
    }
  }
  current_number_of_odd += current_parity_of_u;
  int number_of_disconneted = 0;
  // children components
  bool connected_to_root = false;
  int one_of_disconnected;
  for (int i = 1; i <= number_of_child; ++i) {
    int v = children[u][i - 1];
    if (!connected[i]) {
      if (low[v] < dfn[u]) {
        connected_to_root = true;
      } else if (size[v] > 1) {
        number_of_disconneted++;
        one_of_disconnected = i;
      }
    }
  }
  // the root component
  if (!connected[0] && (n - size[u] > 1 || connected_to_root)) {
    number_of_disconneted++;
    one_of_disconnected = 0;
  }
  // std::cerr << KV(u) << KV(number_of_disconneted) << KV(current_number_of_odd) << KV(one_of_disconnected) << std::endl;
  if (number_of_disconneted == 0) {
    if (current_number_of_odd == 0 ||
        current_number_of_odd == 2 && current_parity_of_u) {
      make_plan(u, star_edge_indexes);
      return true;
    }
  } else if (number_of_disconneted == 1 && current_number_of_odd == 0) {
    auto found = std::find_if(
        star_edge_indexes.begin(), star_edge_indexes.end(), [&](int i) {
          return get_component_id(u, to[i]) == one_of_disconnected;
        });
    if (found != star_edge_indexes.end()) {
      star_edge_indexes.erase(found);
      make_plan(u, star_edge_indexes);
      return true;
    }
  }
  for (int v : children[u]) {
    dsu[v] = u;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
    parity[to[i]] ^= 1;
  }
  number_of_odd = std::accumulate(parity, parity + n, 0);
  memset(head, -1, sizeof(int) * n);
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  if (number_of_odd == 0) {
    euler(0);
  } else if (number_of_odd == 2) {
    int c = 0;
    while (!parity[c]) {
      c++;
    }
    euler(c);
  } else {
    memset(dfn, -1, sizeof(*dfn) * n);
    prepare(0, -1, 0);
    std::iota(dsu, dsu + n, 0);
    work(0);
  }
  {
    int size = plan.size();
    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
      printf("%d%c", ~plan[i] ? plan[i] + 1 : -1, " \n"[i + 1 == size]);
    }
  }
}