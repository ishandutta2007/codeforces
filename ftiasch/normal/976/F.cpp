#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 2000;

int a, b, m, head[N], from[N], to[N], next[N], deg[N + N], limit, match_x[N],
    now, visit[N], used[N], current_x[N], current_y[N];
std::vector<int> match_y[N];

bool find(int u) {
  if (visit[u] == now) {
    return false;
  }
  visit[u] = now;
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    int v = to[iterator];
    if (!used[iterator]) {
      if (static_cast<int>(match_y[v].size()) < limit) {
        used[iterator] = true;
        match_y[v].push_back(iterator);
        return true;
      }
      for (int &back : match_y[v]) {
        if (find(from[back])) {
          used[iterator] = true;
          used[back] = false;
          back = iterator;
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d%d", &a, &b, &m);
  memset(head, -1, sizeof(head));
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    deg[u]++;
    deg[a + v]++;
    from[i] = u;
    to[i] = v;
    next[i] = head[u];
    head[u] = i;
  }
  int min_deg = *std::min_element(deg, deg + (a + b));
  puts("0");
  memset(visit, -1, sizeof(visit));
  for (limit = 1; limit <= min_deg; ++limit) {
    for (int u = 0; u < a; ++u) {
      while (match_x[u] < limit) {
        if (find(u)) {
          now++;
          match_x[u]++;
        } else {
          break;
        }
      }
    }
    memset(current_x, 0, sizeof(*current_x) * a);
    memset(current_y, 0, sizeof(*current_y) * b);
    std::vector<int> plan;
    for (int i = 0; i < m; ++i) {
      if (used[i]) {
        current_x[from[i]]++;
        current_y[to[i]]++;
        plan.push_back(i);
      }
    }
    for (int i = 0; i < m; ++i) {
      if (!used[i] &&
          (current_x[from[i]] < limit || current_y[to[i]] < limit)) {
        current_x[from[i]]++;
        current_y[to[i]]++;
        plan.push_back(i);
      }
    }
    printf("%d", static_cast<int>(plan.size()));
    for (int i : plan) {
      printf(" %d", i + 1);
    }
    puts("");
  }
}