#include <bits/stdc++.h>

const int N = 200'000;

int n, parent[N], depth[N], c[N];
std::vector<int> tree[N];

void prepare(int p, int u) {
  parent[u] = p;
  depth[u] = ~p ? depth[p] + 1 : 0;
  for (int v : tree[u]) {
    if (v != p) {
      c[u]++;
      prepare(u, v);
    }
  }
}

using Query = std::tuple<int, int, int>;

Query queries[N];

struct CandidateEntry {
  int c;
  std::list<int>::iterator iterator;
};

bool operator<(const CandidateEntry &u, const CandidateEntry &v) {
  return u.c > v.c;
}

int queue[N + N];

struct {
  int timestamp, value;
} dp[N];

void add(int clock, int v) { dp[v] = {clock, c[v]}; }

int result[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  prepare(-1, 0);
  int q;
  scanf("%d", &q);
  for (int i = 0, v, k; i < q; ++i) {
    scanf("%d%d", &v, &k);
    queries[i] = {k, v - 1, i};
  }
  std::sort(queries, queries + q);
  std::list<int> candidates;
  std::vector<CandidateEntry> remove_order(n);
  {
    std::vector<std::pair<int, int>> order(n);
    for (int v = 0; v < n; ++v) {
      order[v] = {depth[v], v};
    }
    std::sort(order.begin(), order.end(), std::greater<std::pair<int, int>>());
    for (auto &&[_, v] : order) {
      candidates.emplace_back(v);
    }
    auto iterator = candidates.begin();
    for (auto &&[_, v] : order) {
      remove_order[v] = {c[v], iterator};
      iterator++;
    }
    std::sort(remove_order.begin(), remove_order.end());
  }
  for (int l = 0; l < q;) {
    int k = std::get<0>(queries[l]) + 1;
    int r = l;
    while (r < q && std::get<0>(queries[r]) + 1 == k) {
      r++;
    }
    while (!remove_order.empty() && remove_order.back().c <= k) {
      candidates.erase(remove_order.back().iterator);
      remove_order.pop_back();
    }
    auto iterator = candidates.begin();
    int head = n;
    int tail = n;
    while (iterator != candidates.end() || head < tail) {
      if (head == tail) {
        add(k, queue[--head] = *(iterator++));
      }
      int cur_depth = depth[queue[head]];
      while (iterator != candidates.end() && depth[*iterator] == cur_depth) {
        int v = *(iterator++);
        if (dp[v].timestamp != k) {
          add(k, queue[--head] = v);
        }
      }
      while (head < tail && depth[queue[head]] == cur_depth) {
        int v = queue[head++];
        if (dp[v].value > k) {
          int p = parent[v];
          if (~p) {
            if (dp[p].timestamp != k) {
              add(k, queue[tail++] = p);
            }
            dp[p].value += dp[v].value - k;
          }
        }
      }
    }
    for (int i = l; i < r; ++i) {
      auto [_, v, id] = queries[i];
      result[id] = dp[v].timestamp == k ? dp[v].value : c[v];
    }
    l = r;
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}