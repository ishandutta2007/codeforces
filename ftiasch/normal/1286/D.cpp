#include <bits/stdc++.h>

const int N = 100000;
const int MOD = 998244353;

struct Mat {
  Mat() { memset(m, 0, sizeof(m)); }

  int *operator[](int i) { return m[i]; }
  const int *operator[](int i) const { return m[i]; }

  int m[2][2];
};

Mat operator*(const Mat &a, const Mat &b) {
  Mat c;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c[i][j] = (1LL * a[i][0] * b[0][j] + 1LL * a[i][1] * b[1][j]) % MOD;
    }
  }
  return c;
}

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

struct Frac {
  int mod() const { return 1LL * p * inv(q) % MOD; }

  int p, q;
};

bool operator<(const Frac &a, const Frac &b) {
  return 1LL * a.p * b.q < 1LL * b.p * a.q;
}

int n, x[N], v[N], p[N];
Mat mat[N], pd[N << 1];
std::pair<Frac, int> events[N * 3];

int get_id(int l, int r) { return l + r | l != r; }

void build(int l, int r) {
  int id = get_id(l, r);
  if (l == r) {
    pd[id] = mat[l];
  } else {
    int m = l + r >> 1;
    build(l, m);
    build(m + 1, r);
    pd[id] = pd[get_id(l, m)] * pd[get_id(m + 1, r)];
  }
}

void modify(int l, int r, int k) {
  int id = get_id(l, r);
  if (l == r) {
    pd[id] = mat[k];
  } else {
    int m = l + r >> 1;
    if (k <= m) {
      modify(l, m, k);
    } else {
      modify(m + 1, r, k);
    }
    pd[id] = pd[get_id(l, m)] * pd[get_id(m + 1, r)];
  }
}

int main() {
  scanf("%d", &n);
  int inv_100 = inv(100);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", x + i, v + i, p + i);
    p[i] = 1LL * inv_100 * p[i] % MOD;
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  // 0 - left, 1 - right
  for (int i = 0; i + 1 < n; ++i) {
    mat[i][0][1] = p[i + 1];
    int dx = x[i + 1] - x[i];
    events[i * 3] = {{dx, v[i + 1] + v[i]}, i << 2 | 1};
    events[i * 3 + 1] = {
        v[i] < v[i + 1] ? Frac{dx, v[i + 1] - v[i]} : Frac{1, 0}, i << 2 | 0};
    events[i * 3 + 2] = {
        v[i] > v[i + 1] ? Frac{dx, v[i] - v[i + 1]} : Frac{1, 0}, i << 2 | 3};
  }
  std::sort(events, events + (3 * (n - 1)));
  build(0, n - 2);
  int root = get_id(0, n - 2);
  int result = 0;
  int rest_prob = (1LL * p[0] * (pd[root][0][0] + pd[root][0][1]) +
                   1LL * (1 + MOD - p[0]) * (pd[root][1][0] + pd[root][1][1])) %
                  MOD;
  for (int _ = 3 * (n - 1) - 1; _ >= 0; --_) {
    int i = events[_].second >> 2;
    int x = events[_].second & 1;
    int y = events[_].second >> 1 & 1;
    mat[i][x][y] = y ? p[i + 1] : (1 + MOD - p[i + 1]) % MOD;
    modify(0, n - 2, i);
    int prob = (1LL * (1 + MOD - p[0]) * (pd[root][0][0] + pd[root][0][1]) +
                1LL * p[0] * (pd[root][1][0] + pd[root][1][1])) %
               MOD;
    if (events[_].first.q) {
      result =
          (result + 1LL * events[_].first.mod() * (prob + MOD - rest_prob)) %
          MOD;
    }
    rest_prob = prob;
  }
  printf("%d\n", result);
}