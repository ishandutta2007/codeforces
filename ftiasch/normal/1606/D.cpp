#include <bits/stdc++.h>

const int N = 5'000'000;
const int NM = 1'000'000;

int n, m;

template <typename T> struct Array2D {
  T *operator[](int i) { return buffer + (i * m); }

  T buffer[NM];
};

Array2D<int> a;

using MinMaxPair = std::pair<int, int>;

Array2D<MinMaxPair> left;

MinMaxPair make(int a) { return {a, a}; }

MinMaxPair merge(const MinMaxPair &a, const MinMaxPair &b) {
  return {std::min(a.first, b.first), std::max(a.second, b.second)};
}

MinMaxPair right[N], suffix[N + 1];
std::pair<int, int> order[N];

int plan_k;
char plan[N + 1];

bool solve() {
  for (int i = 0; i < n; ++i) {
    left[i][0] = make(a[i][0]);
    for (int j = 1; j < m; ++j) {
      left[i][j] = merge(left[i][j - 1], make(a[i][j]));
    }
  }
  for (int i = 0; i < n; ++ i) {
      right[i] = make(a[i][m - 1]);
  }
  for (int k = m - 1; k--;) {
      // [0, k) [k, m)
      for (int i = 0; i < n; ++ i) {
          order[i] = {right[i].second, i};
      }
      std::sort(order, order + n);
      suffix[n] = {INT_MAX, INT_MIN};
      for (int i = n - 1; i >= 0; -- i) {
          int r = order[i].second;
          suffix[i] = merge(suffix[i + 1], {right[r].first, left[r][k].second});
      }
      MinMaxPair prefix{INT_MAX, INT_MIN};
      for (int i = 0; i < n - 1; ++ i) {
          // <= i RED
          // > i BLUE
          int r = order[i].second;
          prefix = merge(prefix, {left[r][k].first, right[r].second});
          if (suffix[i + 1].second < prefix.first && prefix.second < suffix[i + 1].first) {
              plan_k = k;
              plan[n] = '\0';
              std::fill(plan, plan + n, 'B');
              for (int j = 0; j <= i; ++ j) {
                  plan[order[j].second] = 'R';
              }
              return true;
          }
      }
      for (int i = 0; i < n; ++ i) {
          right[i] = merge(right[i], make(a[i][k]));
      }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i] + j);
      }
    }
    if (solve()) {
      printf("YES\n%s %d\n", plan, plan_k + 1);
    } else {
      puts("NO");
    }
  }
}