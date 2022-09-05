#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

const ll mod = 998244353;
const ll mmod = mod * mod;

int n, m, k;

struct mat {
  ll m[200][200];
  mat() {
    for (int i = 0; i < 2 * n; i++)
      for (int j = 0; j < 2 * n; j++)
        m[i][j] = 0;
  }
  mat operator*(const mat & o) {
    mat r;
    for (int i = 0; i < 2 * n; i++)
      for (int j = 0; j < 2 * n; j++)
        for (int k = 0; k < 2 * n; k++) {
          r.m[i][k] += m[i][j] * o.m[j][k];
          if (r.m[i][k] > mmod)
            r.m[i][k] -= mmod;
        }
    for (int i = 0; i < 2 * n; i++)
      for (int j = 0; j < 2 * n; j++)
        r.m[i][j] %= mod;
    return r;
  }
};

mat pf(mat x, int k) {
  mat r;
  for (int i = 0; i < 2 * n; i++)
    r.m[i][i] = 1;
  while (k) {
    if (k & 1)
      r = r * x;
    x = x * x;
    k >>= 1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m >> k;
  mat t;
  for (int i = 0; i < n; i++)
    t.m[n + i][i] = 1, t.m[i][n + i] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b, a--, b--;
    t.m[a][b]++;
    t.m[a][n + a]--;
    t.m[b][a]++;
    t.m[b][n + b]--;
  }
  for (int i = 0; i < 2 * n; i++)
    for (int j = 0; j < 2 * n; j++)
      if (t.m[i][j] < 0)
        t.m[i][j] += mod;
  mat x = pf(t, k - 1);
  ll res = 0;
  for (int i = 0; i < n; i++)
    res -= x.m[n + i][i];
  x = x * t;
  for (int i = 0; i < n; i++)
    res += x.m[i][i];
  res %= mod;
  res += mod;
  res %= mod;
  cout << res << "\n";
}