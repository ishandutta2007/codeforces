#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, target[N], q[N], jump[2][N], result[N];
bool income[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", jump[0] + i);
    jump[0][i]--;
    income[jump[0][i]] = true;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", target + i);
    target[i]--;
  }
  int min_leave = n, leaves = 0;
  for (int i = n; i--;) {
    if (!income[i]) {
      min_leave = i;
      leaves++;
    }
  }
  int steps = target[min_leave] >= n ? (target[min_leave] - n) / leaves + 1 : 0;
  std::iota(q, q + n, 0);
  for (int k = 0; steps >> k; ++k) {
    if (steps >> k & 1) {
      for (int i = 0; i < n; ++i) {
        q[i] = jump[k & 1][q[i]];
      }
    }
    for (int i = 0; i < n; ++i) {
      jump[(k + 1) & 1][i] = jump[k & 1][jump[k & 1][i]];
    }
  }
  // lower_bound[i] = target[q[i]];
  std::set<int> candidates;
  for (int i = 0; i < n; ++i) {
    candidates.emplace(i);
  }
  std::fill(result, result + n, -1);
  for (int i = 0; i < n; ++i) {
    int v = target[q[i]];
    auto iterator = candidates.find(v);
    if (iterator != candidates.end()) {
      result[i] = v;
      candidates.erase(iterator);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!~result[i]) {
      auto iterator = candidates.lower_bound(target[q[i]]);
      assert(iterator != candidates.end());
      result[i] = *iterator;
      candidates.erase(iterator);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i] + 1, " \n"[i + 1 == n]);
  }
}