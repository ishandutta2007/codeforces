// #include "debug.h"

#include <bits/stdc++.h>

const int N = 200'001;
const int MOD = 1'000'000'007;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int n, depth[N], bottom[N], top[N], mu[N], phi[N], coef[N];
std::vector<int> tree[N], divisors[N], multiples[N];

int prepare(int p, int u) {
  depth[u] = depth[p] + 1;
  int size = 1;
  std::pair<int, int> candidate{0, u};
  for (int d : divisors[u]) {
    multiples[d].push_back(u);
  }
  for (int v : tree[u]) {
    if (v != p) {
      int size_v = prepare(u, v);
      size += size_v;
      candidate = std::max(candidate, std::make_pair(size_v, bottom[v]));
    }
  }
  bottom[u] = candidate.second;
  top[bottom[u]] = p;
  return size;
}

int lca(int a, int b) {
  while (bottom[a] != bottom[b]) {
    if (depth[top[a]] > depth[top[b]]) {
      a = top[a];
    } else {
      b = top[b];
    }
  }
  return depth[a] < depth[b] ? a : b;
}

int main() {
  scanf("%d", &n);
  {
    std::vector<int> value(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &value[i]);
    }
    for (int i = 0, a, b; i < n - 1; ++i) {
      scanf("%d%d", &a, &b);
      a = value[a];
      b = value[b];
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
  }
  for (int d = 1; d <= n; ++d) {
    multiples[d].reserve(n / d);
    for (int i = d; i <= n; i += d) {
      divisors[i].push_back(d);
    }
  }
  prepare(0, 1);
  for (int u = 1; u <= n; ++u) {
    top[u] = top[bottom[u]];
  }
  mu[1] = 1;
  for (int d = 1; d <= n; ++d) {
    for (int i = d + d; i <= n; i += d) {
      mu[i] -= mu[d];
    }
  }
  for (int d = 1; d <= n; ++d) {
    for (int i = d, r = 1; i <= n; i += d, r++) {
      phi[i] += mu[d] * r;
    }
  }
  for (int d = 1; d <= n; ++d) {
    add(coef[d], 1LL * d * inv(phi[d]) % MOD);
    for (int i = d + d; i <= n; i += d) {
      add(coef[i], MOD - coef[d]);
    }
  }
  int result = 0;
  std::vector<std::pair<int, int>> stack;
  stack.reserve(n);
  for (int d = 1; d <= n; ++d) {
    int sub_total = 0;
    int sum_phi = 0;
    for (int u : multiples[d]) {
      add(sum_phi, phi[u]);
    }
    for (int u : multiples[d]) {
      if (stack.empty()) {
        stack.emplace_back(u, phi[u]);
      } else {
        int w = lca(stack.back().first, u);
        int pop_v = 0, pop_sum = 0;
        while (!stack.empty() && depth[w] < depth[stack.back().first]) {
          auto [v, sum_v] = stack.back();
          stack.pop_back();
          if (pop_v) {
            add(sub_total, 1LL * (depth[pop_v] - depth[v]) * pop_sum % MOD *
                               (sum_phi + MOD - pop_sum) % MOD);
          }
          pop_v = v;
          add(pop_sum, sum_v);
        }
        if (stack.empty() || stack.back().first != w) {
          stack.emplace_back(w, 0);
        }
        if (pop_v) {
          add(sub_total, 1LL * (depth[pop_v] - depth[w]) * pop_sum % MOD *
                             (sum_phi + MOD - pop_sum) % MOD);
          add(stack.back().second, pop_sum);
        }
        stack.emplace_back(u, phi[u]);
      }
    }
    int pop_v = 0, pop_sum = 0;
    while (!stack.empty()) {
      auto [v, sum_v] = stack.back();
      stack.pop_back();
      if (pop_v) {
        add(sub_total, 1LL * (depth[pop_v] - depth[v]) * pop_sum % MOD *
                           (sum_phi + MOD - pop_sum) % MOD);
      }
      pop_v = v;
      add(pop_sum, sum_v);
    }
    add(result, 1LL * coef[d] * sub_total % MOD);
  }
  printf("%d\n",
         static_cast<int>(1LL * result * inv(n * (n - 1LL) / 2 % MOD) % MOD));
}