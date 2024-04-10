#include <bits/stdc++.h>

using Linear = std::array<int, 2>;

const int N = 50;
const int MOD = 998244353;
const int INV2 = 499122177;
const int INV6 = 166374059;


int n, t, x[N], y[N], rank[N << 1], xorder[N << 1], yorder[N << 1],
    count[N << 1];
Linear dys[N << 1];

struct Comparer {
  Comparer(int t, int *a) : t(t), a(a) {}

  int v(int i) const { return a[i >> 1] + (i & 1 ? t + 1 : -t); }

  bool operator()(int i, int j) const {
    return v(i) != v(j) ? v(i) < v(j) : (i & 1) < (j & 1);
  }

  int t;
  int *a;
};

Linear boundary(int *a, int i) {
  if (i & 1) {
    return {a[i >> 1] + 1, 1};
  } else {
    return {a[i >> 1], MOD - 1};
  }
}

int add(int x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
  return x;
}

void update(int &x, int a) { x = add(x, a); }

Linear subtract(const Linear &a, const Linear &b) {
  return {add(a[0], MOD - b[0]), add(a[1], MOD - b[1])};
}

int sum1(int n)
{
  return n * (n - 1LL) % MOD * INV2 % MOD;
}

int sum2(int n) 
{
  return n * (n - 1LL) % MOD * (n + n - 1) % MOD * INV6 % MOD;
}

int main() {
  while (scanf("%d%d", &n, &t) == 2) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", x + i, y + i);
    }
    std::vector<int> time{0, t, t + 1};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (x[i] < x[j]) {
          time.push_back(x[j] - x[i] >> 1);
        }
        if (y[i] < y[j]) {
          time.push_back(y[j] - y[i] >> 1);
        }
      }
    }
    std::sort(time.begin(), time.end());
    time.erase(std::unique(time.begin(), time.end()), time.end());
    std::iota(xorder, xorder + (n << 1), 0);
    std::iota(yorder, yorder + (n << 1), 0);
    memset(count, 0, sizeof(count));
    int result = 0;
    for (int k = 0; k + 1 < time.size(); ++k) {
      // [time[k], time[k + 1])
      int t0 = time[k];
      int t1 = time[k + 1];
      std::sort(xorder, xorder + (n << 1), Comparer{t0, x});
      std::sort(yorder, yorder + (n << 1), Comparer{t0, y});
      for (int i = 0; i < n << 1; ++i) {
        rank[yorder[i]] = i;
      }
      for (int j = 1; j < n << 1; ++j) {
        dys[j] = subtract(boundary(y, yorder[j]), boundary(y, yorder[j - 1]));
      }
      int quad[]{0, 0, 0};
      for (int _i = 0; _i < n << 1; ++_i) {
        int i = xorder[_i];
        int delta = i & 1 ? -1 : 1;
        if (_i) {
          Linear dx = subtract(boundary(x, i), boundary(x, xorder[_i - 1]));
          for (int j = 1; j < n << 1; ++j) {
            if (count[j - 1]) {
              update(quad[0], 1LL * dx[0] * dys[j][0] % MOD);
              update(quad[1],
                     (1LL * dx[0] * dys[j][1] + 1LL * dx[1] * dys[j][0]) % MOD);
              update(quad[2], 1LL * dx[1] * dys[j][1] % MOD);
            }
          }
        }
        for (int j = rank[i & ~1]; j < rank[i | 1]; ++j) {
          count[j] += delta;
        }
      }
      int sum = 1LL * (t1 - t0) * quad[0] % MOD;
      update(sum, 1LL * (sum1(t1) + MOD - sum1(t0)) * quad[1] % MOD);
      update(sum, 1LL * (sum2(t1) + MOD - sum2(t0)) * quad[2] % MOD);
      update(result, t0 == t ? 1LL * t * sum % MOD : MOD - sum);
      if (t0 == t) {
        break;
      }
    }
    printf("%d\n", result);
  }
}