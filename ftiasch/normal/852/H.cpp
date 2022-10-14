#include <bits/stdc++.h>

using LL = long long;

const int N = 200;

bool ok[N][N];
short o[N], ord[N][N], next[N][N], turn[N][N];
LL area[N][N], dp[2][N][N];

struct Point {
  bool quad() const { return x ? x > 0 : y > 0; }

  Point operator-() { return {-x, -y}; }

  Point &operator+=(const Point &o) {
    x += o.x, y += o.y;
    return *this;
  }

  Point &operator-=(const Point &o) {
    x -= o.x, y -= o.y;
    return *this;
  }

  int x, y;
} p[N];

bool operator<(const Point &a, const Point &b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}

Point operator-(Point a, const Point &b) { return a -= b; }

LL det(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

void update(LL &x, LL a) { x = std::max(x, a); }

bool byarg(const Point &a, const Point &b) {
  return a.quad() == b.quad() ? det(a, b) > 0 : a.quad() < b.quad();
};

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    LL result = 0;
    while (n >= 3) {
      {
        int i = std::min_element(p, p + n) - p;
        std::swap(p[0], p[i]);
      }
      Point p0 = p[0];
      for (int i = 0; i < n; ++i) {
        p[i] -= p0;
      }
      std::sort(p + 1, p + n, byarg);
      memset(ok, 0, sizeof(ok));
      memset(next, -1, sizeof(next));
      memset(turn, -1, sizeof(turn));
      std::iota(ord[0], ord[0] + n - 1, 1);
      for (int i = 1; i < n; ++i) {
        turn[0][i] = i + 1 < n ? i + 1 : -1;
        std::iota(o, o + n, 0);
        std::swap(o[i], o[n - 1]);
        std::sort(o, o + n - 1, [&](int j, int k) {
          Point a = j < i ? p[i] - p[j] : p[j] - p[i];
          Point b = k < i ? p[i] - p[k] : p[k] - p[i];
          return byarg(a, b);
        });
        int t0 = std::find(o, o + n - 1, 0) - o, t = t0, count = n - 1 - i,
            last = -1, lowest = n;
        do {
          if (t-- == 0) {
            t = n - 2;
          }
          int j = o[t];
          if (j < i) {
            next[j][i] = last;
          } else {
            ord[i][--count] = j;
            if (j < lowest) {
              lowest = j, ok[i][j] = true;
            }
            turn[i][j] = last;
            last = j;
          }
        } while (t != t0);
        assert(count == 0);
      }
      for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          area[i][j] = det(p[i], p[j]);
        }
      }
      memset(dp, -1, sizeof(dp));
      dp[0][0][1] = 0;
      for (int k = 2; k <= m; ++k) {
        memset(dp[k + 1 & 1], -1, sizeof(dp[k + 1 & 1]));
        for (int i = 0; i < n; ++i) {
          for (int p = 0; p < n - 1 - i; ++p) {
            int j = ord[i][p];
            LL v = dp[k & 1][i][j];
            if (~v) {
              if (~turn[i][j]) {
                update(dp[k & 1][i][turn[i][j]], v);
              }
              if (i == 0 || ok[i][j]) {
                v += area[i][j];
                if (k < m) {
                  if (~next[i][j]) {
                    update(dp[k + 1 & 1][j][next[i][j]], v);
                  }
                } else {
                  update(result, v);
                }
              }
            }
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        p[i] += p0;
      }
      std::swap(p[0], p[--n]);
    }
    std::cout << (result >> 1) << (result & 1 ? ".50" : ".00") << std::endl;
  }
}