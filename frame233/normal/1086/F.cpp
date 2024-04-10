// yzctxdy!!!
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, i2 = (mod + 1) / 2, i6 = i2 / 3;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline void fma(int &x, const int y, const int z) {x = (x + 1ll * y * z) % mod;}

const int N = 105;
const int inf = 0x3f3f3f3f;
int n, t, x[N], y[N], id[N];

int calc(int t) {
  vector<int> p;
  for (int i = 1; i <= n; ++i) {
    p.emplace_back(y[i] - t);
    p.emplace_back(y[i] + t + 1);
  }
  sort(p.begin(), p.end()), p.erase(unique(p.begin(), p.end()), p.end());
  int ans = 0;
  for (int i = 0; i < p.size() - 1; ++i) {
    int l = p[i], r = p[i + 1], cur = 0;
    for (int o = 1, rp = -inf; o <= n; ++o) {
      int i = id[o];
      if (y[i] - t >= r || y[i] + t < l) continue;
      int itst = x[i] + t - max(rp, x[i] - t - 1);
      add(cur, itst);
      rp = x[i] + t;
    } 
    fma(ans, cur, r - l);
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &t);
  if (!t) return puts("0"), 0;
  vector<int> p = {0, t};
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    id[i] = i;
    for (int j = 1; j < i; ++j) {
      int cur = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
      p.emplace_back((cur + 1) / 2);
    }
  }
  sort(id + 1, id + n + 1, [&](int i, int j) {
    return x[i] < x[j];
  });
  sort(p.begin(), p.end()), p.erase(unique(p.begin(), p.end()), p.end());
  int ans = 0;
  for (int i = 0; i < p.size() - 1; ++i) {
    int l = p[i], r = p[i + 1], m = r - l;
    if (r - l <= 3) {
      for (int i = l; i < r; ++i) add(ans, calc(i));
    } else {
      int x = calc(l), y = calc(l + 1), z = calc(l + 2);
      sub(z, y), sub(y, x), sub(z, y);
      fma(ans, m, x);
      fma(ans, int(1ll * m * (m - 1) / 2 % mod), y);
      fma(ans, i2, Mul(z, Sub(Mul(i6, Mul(m - 1, Mul(m, 2 * m - 1))), 1ll * m * (m - 1) / 2 % mod)));
    }
    if (r == t) break;
  }
  printf("%d\n", Sub(Mul(t, calc(t)), ans));
  return 0;
}