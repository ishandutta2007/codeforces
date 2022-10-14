#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

using Long = long long;

struct Node;

Node *null;

struct Node {
  Node *insert(int l, int r, int k, int cap, int rate) {
    if (k < l || r <= k) {
      return this;
    }
    if (l + 1 == r) {
      return new Node{sum_cap + cap, sum_rate + rate, null, null};
    }
    int m = (l + r) >> 1;
    return new Node{sum_cap + cap, sum_rate + rate,
                    left->insert(l, m, k, cap, rate),
                    right->insert(m, r, k, cap, rate)};
  }

  std::pair<int, Long> take(int elapsed, int l, int r, int a, int b, Long hp) {
    if (a <= l && r <= b) {
      // fully-covered
      Long mana = sum_cap + sum_rate * elapsed;
      if (l + 1 == r) {
        // leave
        if (mana <= hp) {
          return {r, mana};
        } else {
          return {l, 0};
        }
      } else if (mana <= hp) {
        // non-leave
        return {r, mana};
      }
    }
    int m = (l + r) >> 1;
    Long taken = 0;
    if (a < m) {
      auto [to, left_taken] = left->take(elapsed, l, m, a, b, hp);
      taken += left_taken;
      if (to < m) {
        return {to, taken};
      }
    }
    if (m < b) {
      auto [to, right_taken] = right->take(elapsed, m, r, a, b, hp - taken);
      taken += right_taken;
      if (to < b) {
        return {to, taken};
      }
    }
    return {b, taken};
  }

  Long sum_cap, sum_rate;
  Node *left, *right;
};

int main() {
  null = new Node{0, 0, nullptr, nullptr};
  null->left = null->right = null;
  int n;
  scanf("%d", &n);
  std::vector<int> cap(n), rate(n), full(n);
  std::vector<std::pair<int, int>> order(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &cap[i], &rate[i]);
    full[i] = cap[i] / rate[i];
    order[i] = {full[i], i};
  }
  std::sort(order.begin(), order.end());
  using Seg = std::tuple<int, int, int>;
  std::vector<Seg> segs;
  for (int i = n; i--;) {
    segs.emplace_back(i + 1, 0, cap[i]);
  }
  std::vector<Node *> tree(n + 1);
  tree[0] = null;
  for (int i = 0; i < n; ++i) {
    tree[0] = tree[0]->insert(0, n, i, 0, rate[i]);
  }
  for (int i = 0; i < n; ++i) {
    int k = order[i].second;
    tree[i + 1] = tree[i]->insert(0, n, k, cap[k], -rate[k]);
  }
  // std::cout << KV(segs) << std::endl;
  // elapsed
  // full[i] >= elapsed, elpased * rate[i]
  // full[i] <  elapsed, cap[i]
  int q;
  scanf("%d", &q);
  Long result = 0;
  while (q--) {
    int now;
    Long hp;
    scanf("%d%lld", &now, &hp);
    // std::cout << "Q " << KV(now) << KV(hp) << std::endl;
    int begin = 0;
    while (!segs.empty() && hp > 0) {
      auto [end, t0, mana0] = segs.back();
      int elapsed = now - t0;
      // std::cout << "> " << KV(segs.back()) << KV(elapsed) << KV(hp)
      // << std::endl;
      segs.pop_back();
      if (begin + 1 == end) {
        int mana =
            std::min<Long>(mana0 + 1LL * rate[begin] * elapsed, cap[begin]);
        // std::cout << "partial " << KV(mana) << std::endl;
        if (hp >= mana) {
          hp -= mana;
        } else {
          mana -= hp;
          hp = 0;
          segs.emplace_back(end, now, mana);
          break;
        }
      } else {
        Node *root = tree[std::lower_bound(order.begin(), order.end(),
                                           std::make_pair(elapsed, 0)) -
                          order.begin()];
        auto [to, taken] = root->take(elapsed, 0, n, begin, end, hp);
        // std::cout << "full " << KV(to) << KV(taken) << std::endl;
        hp -= taken;
        if (to < end) {
          if (to + 1 < end) {
            segs.emplace_back(end, t0, mana0);
          }
          int mana = std::min<Long>(1LL * rate[to] * elapsed, cap[to]);
          mana -= hp;
          hp = 0;
          segs.emplace_back(to + 1, now, mana);
          begin = to;
          break;
        }
      }
      begin = end;
    }
    if (begin > 0) {
      segs.emplace_back(begin, now, 0);
    }
    // std::cout << "=== " << KV(hp) << KV(segs) << std::endl;
    result += hp;
  }
  printf("%lld\n", result);
}