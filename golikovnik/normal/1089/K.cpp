#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int const INF = 1e6 + 5;
  struct node {
    int64_t sum{};
    int64_t max{};
    int64_t add{};

    node() = default;
  };
  vector<node> tree(4 * INF);

  auto join = [](node a, node b) -> node {
    assert(!a.add);
    assert(!b.add);
    return {a.sum + b.sum, max(a.max, b.max), 0};
  };
  auto pull = [&](int v) {
    tree[v] = join(tree[2 * v], tree[2 * v + 1]);
  };
  auto push = [&](int v, int l, int r) {
    tree[v].max += tree[v].add;
    if (l + 1 != r) {
      tree[2 * v].add += tree[v].add;
      tree[2 * v + 1].add += tree[v].add;
    }
    tree[v].add = 0;
  };
  function<node(int, int, int, int, int)> tree_get =
    [&](int v, int l, int r, int ql, int qr) -> node {
      push(v, l, r);
      if (l >= qr || ql >= r) {
        return node();
      }
      if (ql <= l && r <= qr) {
        assert(!tree[v].add);
        return tree[v];
      }
      auto m = (l + r) / 2;
      return join(tree_get(2 * v, l, m, ql, qr),
                  tree_get(2 * v + 1, m, r, ql, qr));
  };
  function<void(int, int, int, int, node)> tree_set =
    [&](int v, int l, int r, int at, node x) {
      push(v, l, r);
      if (l + 1 == r) {
        tree[v] = x;
        return;
      }
      int m = (l + r) / 2;
      if (at < m) {
        tree_set(2 * v, l, m, at, x);
        push(2 * v + 1, m, r);
      } else {
        tree_set(2 * v + 1, m, r, at, x);
        push(2 * v, l, m);
      }
      pull(v);
  };
  function<void(int, int, int, int, int, int64_t)> tree_add =
    [&](int v, int l, int r, int ql, int qr, int64_t d) {
      push(v, l, r);
      if (ql >= r || l >= qr) {
        return;
      }
      if (ql <= l && r <= qr) {
        tree[v].add += d;
        push(v, l, r);
        return;
      }
      int m = (l + r) / 2;
      tree_add(2 * v, l, m, ql, qr, d);
      tree_add(2 * v + 1, m, r, ql, qr, d);
      pull(v);
  };

  int q;
  cin >> q;
  vector<pair<int, int64_t>> qs;
  while (q--) {
    char type;
    cin >> type;
    if (type == '+') {
      int t;
      int64_t d;
      cin >> t >> d;
      auto suff = tree_get(1, 0, INF, t, INF);
      auto to_set = suff.sum + d + t;
      tree_set(1, 0, INF, t, {d, to_set, 0});
      tree_add(1, 0, INF, 0, t, d);
      qs.emplace_back(t, d);
    } else if (type == '-') {
      int i;
      cin >> i;
      --i;
      auto[t, d] = qs[i];
      tree_add(1, 0, INF, 0, t, -d);
      tree_set(1, 0, INF, t, {0, 0, 0});
      qs.emplace_back(0, 0);
    } else {
      int t;
      cin >> t;
      auto mx = tree_get(1, 0, INF, 0, t + 1).max;
      auto s = tree_get(1, 0, INF, t + 1, INF).sum;
      cout << max<int64_t>(0, mx - s - t) << '\n';
      qs.emplace_back(0, 0);
    }
  }
  return 0;
}