#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

using namespace std;

int mod = 1000000007;
int n, x[202], y[202];
bool f[202][202];

int sgn(long long x) {
  return (x > 0) - (x < 0);
}

int cw(int a, int b, int c) {
  return sgn(1LL * (x[b] - x[a]) * (y[c] - y[a]) - 1LL * (y[b] - y[a]) * (x[c] - x[a]));
}

bool has(int a, int b, int c, int d) {
  return cw(a, b, c) * cw(a, b, d) < 0 && cw(c, d, a) * cw(c, d, b) < 0;
}

double dist(int a, int b) {
  return sqrt(1.0 * (x[a] - x[b]) * (x[a] - x[b]) + 1.0 * (y[a] - y[b]) * (y[a] - y[b]));
}

bool on(int a, int b, int c) {
  return cw(a, b, c) == 0 && fabs(dist(a, b) - dist(a, c) - dist(b, c)) < 1e-7;
}

long long calcS(const vector<pair<int, int> >& v) {
  long long s = 0;
  for (int i = 0; i < v.size(); ++i) {
    s += 1LL * v[i].first * v[(i + 1) % v.size()].second - 1LL * v[i].second * v[(i + 1) % v.size()].first;
  }
  return s > 0 ? s : -s;
}

bool isInside(int a, int b) {
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i)
    v.push_back(make_pair(x[i], y[i]));
  long long s = calcS(v);

  v.clear();
  for (int i = a; ; ++i) {
    if (i == n) i = 0;
    v.push_back(make_pair(x[i], y[i]));
    if (i == b) break;
  }
  s -= calcS(v);

  v.clear();
  for (int i = b; ; ++i) {
    if (i == n) i = 0;
    v.push_back(make_pair(x[i], y[i]));
    if (i == a) break;
  }
  s -= calcS(v);
  return s == 0;
}

bool ok(int a, int b) {
  bool ret = true;
  if ((a + 1) % n != b && (b + 1) % n != a) {
    for (int i = 0; i < n; ++i) {
      if (a != i && a != (i + 1) % n && b != i && b != (i + 1) % n) {
        if (has(a, b, i, i + 1)) {
          ret = false;
          break;
        }
      }
    }
    if (!isInside(a, b))
      ret = false;
  }
  for (int i = 0; i < n; ++i) {
    if (i != a && i != b && on(a, b, i))
      ret = false;
  }
  return f[a][b] = f[b][a] = ret;
}

int dp[202][202];

int nx(int i) {
  if (i + 1 < n) return i + 1;
  return 0;
}

int solve(int l, int r) {
  // cout << l << "  " << r << endl;
  if (dp[l][r] != -1) return dp[l][r];
  // if (l == r) puts("fuck");
  if (l == r) return 1;
  if (nx(l) == r) return dp[l][r] = 1;
  int ret = 0;
  // for (int i = nx(nx(l)); ; i = nx(i)) {
  //   if (f[l][i] && f[nx(l)][i]) {
  //     ret = (ret + 1LL * solve(nx(l), i) * solve(i, r)) % mod;
  //   }
  //   if (i == r) break;
  // }
  for (int i = nx(l); ; i = nx(i)) {
    if (i == r) break;
    if (f[l][i] && f[r][i]) {
      ret = (ret + 1LL * solve(l, i) * solve(i, r)) % mod;
    }
  }
  // cout << l << "  " << r << " " << ret << endl;
  return dp[l][r] = ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  x[n] = x[0]; y[n] = y[0];
  for (int i = 0; i < n; ++i) {
    f[i][i] = 0;
    for (int j = i + 1; j < n; ++j) {
      ok(i, j);
      // cout << i << "  " << j << " " << f[i][j] << endl;
    }
  }
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  // for (int i = 2; i < n; ++i) {
  //   if (f[0][i] && f[1][i]) {
  //     // cout << "Q: " << 1 << " " << i << " " << 0 << endl;
  //     ans = (ans + 1LL * solve(1, i) * solve(i, 0)) % mod;
  //     // cout << ans << endl;
  //   }
  // }
  ans = solve(0, n - 1);
  printf("%d\n", ans);
  return 0;
}