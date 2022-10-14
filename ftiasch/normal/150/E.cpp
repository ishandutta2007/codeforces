#include <bits/stdc++.h>

namespace {

using Pair = std::pair<int, int>;

template <typename T> void update_max(T &x, T a) { x = std::max(x, a); }

const int N = 100'000;

int n, min_len, max_len, b;
std::vector<Pair> tree[N];
Pair prefer[N];

struct Path {
  void reserve() {
    value.resize(max_size);
    range_max.resize(max_size);
    queue.resize(max_size + 1);
  }

  void clear() {
    size = head = tail = 0;
    std::fill(range_max.begin(), range_max.end(), std::make_pair(-N, 0));
  }

  void auto_inc(int& x) {
    x = x == max_size ? 0 : x + 1;
  }

  void auto_dec(int& x) {
    x = x == 0 ? max_size : x - 1;
  }

  Pair queue_tail() const {
    return tail == 0 ? queue[max_size] : queue[tail - 1];
  }

  void push(Pair p) {
    int i = size++;
    value[i] = p;
    if (head != tail && i - queue[head].second == b) {
      auto_inc(head);
    }
    while (head != tail && queue_tail().first <= p.first) {
      auto_dec(tail);
    }
    queue[tail] = {p.first, i};
    auto_inc(tail);
    update_max(range_max[i], value[queue[head].second]);
  }

  void repush(const Path *q) {
    size -= q->size;
    while (head != tail && queue_tail().second >= size) {
      auto_dec(tail);
    }
    int offset = size;
    for (int i = 0; i < q->size; ++i) {
      push(std::max(value[offset + i], q->value[i]));
    }
  }

  Pair get_range_max(int d) const { return range_max[size - d]; }
  Pair get_value(int d) const { return value[size - d]; }

  int max_size = 0, size, head, tail;
  std::vector<Pair> value, range_max, queue;
};

Path *path[N];

int prepare(int p, int u) { // = height
  std::pair<int, Pair> candidate(0, {u, 0});
  for (auto [v, w] : tree[u]) {
    if (v != p) {
      update_max(candidate, {prepare(u, v), {v, w}});
    }
  }
  prefer[u] = candidate.second;
  int v = prefer[u].first;
  if (v == u) {
    path[u] = new Path();
  } else {
    path[u] = path[v];
  }
  path[u]->max_size++;
  return candidate.first + 1;
}

int limit;
Pair plan;

bool update_plan(int s, int a, int b) {
  if (s < 0) {
    return false;
  }
  plan = {a, b};
  return true;
}

int pm1(int w) { return w >= limit ? 1 : -1; }

bool check(int p, int u, int sum_u) {
  // std::cerr << KV(p) << " " << KV(u) << " " << KV(sum_u) << std::endl;
  auto [prefer_v, prefer_w] = prefer[u];
  if (prefer_v == u) {
    // a leaf
    path[u]->clear();
    path[u]->push({sum_u, u});
    return false;
  }
  if (check(u, prefer_v, sum_u + pm1(prefer_w))) {
    return true;
  }
  for (auto [v, w] : tree[u]) {
    if (v != p && v != prefer_v) {
      if (check(u, v, sum_u + pm1(w))) {
        return true;
      }
      // min_len - j <= path[u]->size
      for (int j = std::max(min_len - path[u]->size, 1);
           j <= path[v]->size && j < min_len; ++j) {
        auto [sum_heavy, heavy] = path[u]->get_range_max(min_len - j);
        auto [sum_light, light] = path[v]->get_value(j);
        if (update_plan(sum_heavy + sum_light - 2 * sum_u, heavy, light)) {
          return true;
        }
      }
      auto ptr = path[u]->head;
      for (int j = min_len; j <= path[v]->size && j < max_len; ++j) {
        auto q = path[u]->queue[ptr].second;
        if ((path[u]->size - q) + j == max_len + 1) {
          path[u]->auto_inc(ptr);
        }
        auto [sum_heavy, heavy] = path[u]->value[q];
        auto [sum_light, light] = path[v]->get_value(j);
        if (update_plan(sum_heavy + sum_light - 2 * sum_u, heavy, light)) {
          return true;
        }
      }
      path[u]->repush(path[v]);
    }
  }
  if (path[u]->size >= min_len) {
    auto [sum_v, v] = path[u]->get_range_max(min_len);
    if (update_plan(sum_v - sum_u, u, v)) {
      return true;
    }
  }
  path[u]->push({sum_u, u});
  return false;
}

bool check(int l) {
  // std::cerr << "checking " << l << std::endl;
  limit = l;
  return check(-1, 0, 0);
}

} // namespace

int main() {
  scanf("%d%d%d", &n, &min_len, &max_len);
  b = max_len - min_len + 1;
  std::vector<int> values;
  values.reserve(n - 1);
  // std::cerr << "graph {\n";
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);
    values.push_back(c);
    // std::cerr << a << " -- " << b << " [label=\"" << c << "\"]" << std::endl;
  }
  // std::cerr << "}\n";
  prepare(-1, 0);
  for (int u = 0; u < n; ++u) {
    if (prefer[u].first == u) {
      path[u]->reserve();
    }
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int low = -1;
  int high = values.size();
  while (low + 1 < high) {
    int middle = (low + high) >> 1;
    if (check(values[middle])) {
      low = middle;
    } else {
      high = middle;
    }
  }
  check(values[low]);
  printf("%d %d\n", plan.first + 1, plan.second + 1);
  // printf("%d\n", low == -1 ? -1 : values[low]);
}