#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;
const int V = N + N;

int q;

using Edge = std::pair<int, int>;

std::vector<Edge> events[N << 1];

int get_id(int l, int r) { return (l + r) | (l != r); }

void add_edge(int l, int r, int a, int b, const Edge &e) {
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    events[get_id(l, r)].push_back(e);
  } else {
    int m = (l + r) >> 1;
    add_edge(l, m, a, b, e);
    add_edge(m + 1, r, a, b, e);
  }
}

using Pair = std::pair<int, int>;

int parent[V];
Pair stat[V];
long long result[N];

int size(const Pair &p) { return p.first + p.second; }

long long weight(const Pair &p) { return 1LL * p.first * p.second; }

int find(int u) {
  while (u != parent[u]) {
    u = parent[u];
  }
  return u;
}

int hist_len;
std::pair<int, int> hist[V];

long long merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return 0;
  }
  if (size(stat[a]) < size(stat[b])) {
    std::swap(a, b);
  }
  hist[hist_len++] = {a, b};
  long long delta = -weight(stat[a]) - weight(stat[b]);
  parent[b] = a;
  stat[a].first += stat[b].first;
  stat[a].second += stat[b].second;
  delta += weight(stat[a]);
  return delta;
}

void work(int l, int r, long long cur) {
  int cp = hist_len;
  for (auto [a, b] : events[get_id(l, r)]) {
    cur += merge(a, b);
  }
  if (l == r) {
    result[l] = cur;
  } else {
    int m = (l + r) >> 1;
    work(l, m, cur);
    work(m + 1, r, cur);
  }
  while (hist_len > cp) {
    auto [a, b] = hist[--hist_len];
    parent[b] = b;
    stat[a].first -= stat[b].first;
    stat[a].second -= stat[b].second;
  }
}

int main() {
  scanf("%d", &q);
  std::map<Edge, int> edges;
  for (int i = 0, x, y; i < q; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    Edge e{x, N + y};
    auto [iterator, flag] = edges.emplace(e, i);
    if (!flag) {
      add_edge(0, q - 1, iterator->second, i - 1, e);
      edges.erase(iterator);
    }
  }
  for (auto [e, enter] : edges) {
    add_edge(0, q - 1, enter, q - 1, e);
  }
  std::iota(parent, parent + V, 0);
  std::fill(stat, stat + N, Pair{1, 0});
  std::fill(stat + N, stat + V, Pair{0, 1});
  work(0, q - 1, 0);
  for (int i = 0; i < q; ++i) {
    printf("%lld%c", result[i], " \n"[i + 1 == q]);
  }
}