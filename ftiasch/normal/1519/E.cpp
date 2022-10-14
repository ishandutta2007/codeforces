#include <bits/stdc++.h>

const int N = 200'000;

struct Frac {
  Frac(long long p_ = 0, long long q_ = 1) {
    auto g = std::__gcd(p_, q_);
    p = p_ / g;
    q = q_ / g;
  }

  Frac add() const { return Frac(p + q, q); }

  long long p, q;
};

Frac operator/(const Frac &a, const Frac &b) {
  return Frac(a.p * b.q, a.q * b.p);
}

bool operator<(const Frac &a, const Frac &b) {
  return a.p != b.p ? a.p < b.p : a.q < b.q;
}

int n, edges[N << 1], head[N << 1], next[N << 1], used[N];
bool visited[N << 1];
std::map<Frac, int> slopes;
std::vector<int> groups[N << 1];

int get_id(const Frac &f) {
  int new_id = slopes.size();
  return slopes.emplace(f, new_id).first->second;
}

void dfs(int u) {
  visited[u] = true;
  for (int e = head[u]; ~e; e = next[e]) {
    int id = e >> 1;
    if (!used[id]) {
      used[id] = true;
      int v = edges[e ^ 1];
      if (visited[v]) {
        // back edge
        groups[v].push_back(id);
      } else {
        dfs(v);
        if (groups[v].size() & 1) {
          groups[v].push_back(id);
        } else {
          groups[u].push_back(id);
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    Frac x(a, b), y(c, d);
    edges[i << 1] = get_id(y / x.add());
    edges[i << 1 | 1] = get_id(y.add() / x);
  }
  int v = slopes.size();
  memset(head, -1, sizeof(head));
  for (int i = 0; i < n << 1; ++i) {
    next[i] = head[edges[i]];
    head[edges[i]] = i;
  }
  for (int i = 0; i < v; ++i) {
    dfs(i);
  }
  std::vector<std::pair<int, int>> plan;
  for (int i = 0; i < v; ++i) {
    const auto &g = groups[i];
    for (int j = 0; j + 1 < g.size(); j += 2) {
      plan.emplace_back(g[j], g[j + 1]);
    }
  }
  printf("%d\n", static_cast<int>(plan.size()));
  for (auto [a, b] : plan) {
    printf("%d %d\n", a + 1, b + 1);
  }
}