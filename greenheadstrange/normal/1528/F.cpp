// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) { return (long long)x * y % md; }

inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      res = mul(res, x);
    }
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}

namespace ntt {
int base = 1, root = -1, max_base = -1;
vector<int> rev = {0, 1}, roots = {0, 1};

void init() {
  int temp = md - 1;
  max_base = 0;
  while (temp % 2 == 0) {
    temp >>= 1;
    ++max_base;
  }
  root = 2;
  while (true) {
    if (power(root, 1 << max_base) == 1 &&
        power(root, 1 << max_base - 1) != 1) {
      break;
    }
    ++root;
  }
}

void ensure_base(int nbase) {
  if (max_base == -1) {
    init();
  }
  if (nbase <= base) {
    return;
  }
  assert(nbase <= max_base);
  rev.resize(1 << nbase);
  for (int i = 0; i < 1 << nbase; ++i) {
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << nbase - 1;
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = power(root, 1 << max_base - 1 - base);
    for (int i = 1 << base - 1; i < 1 << base; ++i) {
      roots[i << 1] = roots[i];
      roots[i << 1 | 1] = mul(roots[i], z);
    }
    ++base;
  }
}

void dft(vector<int> &a) {
  int n = a.size(), zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i<rev[i]>> shift) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = mul(a[j + k + i], roots[i + k]);
        a[j + k] = (x + y) % md;
        a[j + k + i] = (x + md - y) % md;
      }
    }
  }
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int sz = 1 << nbase;
  a.resize(sz);
  b.resize(sz);
  bool equal = a == b;
  dft(a);
  if (equal) {
    b = a;
  } else {
    dft(b);
  }
  int inv_sz = inv(sz);
  for (int i = 0; i < sz; ++i) {
    a[i] = mul(mul(a[i], b[i]), inv_sz);
  }
  reverse(a.begin() + 1, a.end());
  dft(a);
  a.resize(need);
  return a;
}

vector<int> inverse(vector<int> a) {
  int n = a.size(), m = n + 1 >> 1;
  if (n == 1) {
    return vector<int>(1, inv(a[0]));
  } else {
    vector<int> b = inverse(vector<int>(a.begin(), a.begin() + m));
    int need = n << 1, nbase = 0;
    while (1 << nbase < need) {
      ++nbase;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    dft(a);
    dft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; ++i) {
      a[i] = mul(mul(md + 2 - mul(a[i], b[i]), b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    dft(a);
    a.resize(n);
    return a;
  }
}
} // namespace ntt

using ntt::inverse;
using ntt::multiply;

vector<int> &operator+=(vector<int> &a, const vector<int> &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    add(a[i], b[i]);
  }
  return a;
}

vector<int> operator+(const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c += b;
}

vector<int> &operator-=(vector<int> &a, const vector<int> &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    sub(a[i], b[i]);
  }
  return a;
}

vector<int> operator-(const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c -= b;
}

vector<int> &operator*=(vector<int> &a, const vector<int> &b) {
  if (min(a.size(), b.size()) < 128) {
    vector<int> c = a;
    a.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < c.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        add(a[i + j], mul(c[i], b[j]));
      }
    }
  } else {
    a = multiply(a, b);
  }
  return a;
}

vector<int> operator*(const vector<int> &a, const vector<int> &b) {
  vector<int> c = a;
  return c *= b;
}

int n, k;
ll f[maxn], g[maxn];
int main() {
  scanf("%d%d", &n, &k);
  f[0] = 1;
  g[0] = 1;
  for (int i = 1; i <= k; i++) {
    f[i] = f[i - 1] * i % mod;
    g[i] = ksm(f[i], mod - 2);
  }
  vi f1(k + 1, 0), g1(k + 1, 0);
  for (int i = 0; i <= k; i++) {
    f1[i] = ksm(mod - 1, i) * g[i] % mod;
    g1[i] = ksm(i, k) * g[i] % mod;
  }
  vi s = f1 * g1;
  ll r = 1, ans = 0;
  for (int i = 0; i <= k && i <= n; i++) {
    ans = (ans + s[i] * ksm(n + 1, n - i) % mod * r) % mod;
    r = r * (n - i) % mod;
  }
  printf("%lld\n", ans);
}