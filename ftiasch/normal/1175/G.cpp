#include <bits/stdc++.h>

const int N = 20'001;
const int INF = 400'000'000;

struct Line {
  int k, b;

  int at(int x) const { return k * x + b; }
};

// std::ostream &operator<<(std::ostream &out, const Line &l) {
//   return out << KV(l.k) << " " KV(l.b);
// }

bool check(const Line &u, const Line &v, const Line &w) {
  return 1LL * (v.b - u.b) * (v.k - w.k) < 1LL * (w.b - v.b) * (u.k - v.k);
}

int n, a[N], dp[2][N], sufmax[N], premax[N];
Line stack[N];

void update_min(int &x, int a) { x = std::min(x, a); }

void work(const int *old_dp, int *dp, int l, int r) {
  if (l < r) {
    int m = (l + r) >> 1;
    // [l, m]
    // [m + 1, r]
    sufmax[m] = 0;
    for (int i = m; i > l; --i) {
      sufmax[i - 1] = std::max(a[i], sufmax[i]);
    }
    premax[m] = 0;
    for (int i = m + 1; i <= r; ++i) {
      premax[i] = std::max(premax[i - 1], a[i]);
    }
    // sufmax[j] <= premax[i]
    for (int i = m + 1, bot = n, j = m; i <= r; ++i) {
      // premax[i] +
      while (j >= l && sufmax[j] <= premax[i]) {
        // old_dp[j] - j * x (x = premax[i]) + i * premax[i]
        // slope +
        // query +
        const Line line{-j, old_dp[j]};
        while (bot + 1 < n && !check(line, stack[bot], stack[bot + 1])) {
          bot++;
        }
        stack[--bot] = line;
        j--;
      }
      int x = premax[i];
      while (bot + 1 < n && stack[bot].at(x) > stack[bot + 1].at(x)) {
        bot++;
      }
      update_min(dp[i], stack[bot].at(x) + i * premax[i]);
    }
    // sufmax[j] >= premax[i]
    for (int i = r, top = -1, j = l; i > m; --i) {
      // premax[i] -
      while (j <= m && sufmax[j] >= premax[i]) {
        // old_dp[j] - j * sufmax[j] + sufmax[j] * x (x = i)
        // slope -
        // query -
        Line line{sufmax[j], old_dp[j] - j * sufmax[j]};
        j++;
        while (j <= m && sufmax[j] == line.k) {
          line.b = std::min(line.b, old_dp[j] - j * sufmax[j]);
          j++;
        }
        while (top - 1 >= 0 && !check(stack[top - 1], stack[top], line)) {
          top--;
        }
        stack[++top] = line;
      }
      int x = i;
      while (top - 1 >= 0 && stack[top - 1].at(x) < stack[top].at(x)) {
        top--;
      }
      if (~top) {
        update_min(dp[i], stack[top].at(x));
      }
    }
    work(old_dp, dp, l, m);
    work(old_dp, dp, m + 1, r);
  }
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  dp[0][0] = 0;
  std::fill(dp[0] + 1, dp[0] + n + 1, INF);
  for (int j = 0; j < m; ++j) {
    std::fill(dp[(j + 1) & 1], dp[(j + 1) & 1] + (n + 1), INF);
    work(dp[j & 1], dp[(j + 1) & 1], 0, n);
    // std::cout << std::vector<int>(dp[(j + 1) & 1], dp[(j + 1) & 1] + (n + 1))
    //           << std::endl;
  }
  printf("%d\n", dp[m & 1][n]);
}