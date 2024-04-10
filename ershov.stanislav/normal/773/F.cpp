#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

int mod;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

struct comp {
  ld x, y;

  comp(ld x = 0, ld y = 0) : x(x), y(y) {}

  comp operator+(const comp & b) const {
    return comp(x + b.x, y + b.y);
  }

  comp operator-(const comp & b) const {
    return comp(x - b.x, y - b.y);
  }

  comp operator*(const comp & b) const {
    return comp(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};

int n, logn;

namespace FFT {
  const int maxn = 1 << 16;

  int rev[maxn];
  comp w[maxn];

  int wasn = -1;

  void fft(comp * a) {
    if (wasn != n) {
      wasn = n;
      rev[0] = 0;
      comp tomult;
      w[1] = 1;
      for (int i = 1, j = -1; i < n; i++) {
        if (!(i & (i - 1))) {
          j++;
          tomult = comp(cos(pi / 2 / i), sin(pi / 2 / i));
        }
        if (i < n / 2) {
          w[i * 2] = w[i];
          w[i * 2 + 1] = w[i] * tomult;
        }
        rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
      }
    }

    for (int i = 0; i < n; i++) {
      if (rev[i] < i) {
        swap(a[i], a[rev[i]]);
      }
    }

    for (int i0 = 1, pos = 1; i0 < n; i0 <<= 1) {
      for (int i = 0; i < n; i += i0) {
        for (int j = i + i0, it = 0; it < i0; it++, j++, i++) {
          comp toadd = a[j] * w[pos + it];
          a[j] = a[i] - toadd;
          a[i] = a[i] + toadd;
        }
      }
      pos += i0;
    }
  }
};

void precalc() {
}

int n0, a;

bool read() {
  if (scanf("%d%d%d", &n0, &a, &mod) < 3) {
    return false;
  }
  return true;
}

const int maxn = 1 << 16;

comp was[2][maxn];
comp now[3][maxn];

struct T {
  int a[2][maxn];

  T(int x = 0) {
    memset(a, 0, sizeof(a));
    a[0][0] = x;
  }

  void norm() {
    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n / 2; i++) {
        a[it][i] = (ll) round(now[it][i].x) % mod;
      }
    }
    vector<int> tomult[2] = {{mod - 1, mod - 2, mod - 1}, {2, 2, 1}};
    for (int pos = 0; pos < 2; pos++) {
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < sz(tomult[pos]); j++) {
          add(a[pos][i + j], (ll) round(now[2][i].x) * tomult[pos][j] % mod);
        }
      }
    }
  }

  void operator+= (const T & b) {
    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n; i++) {
        add(a[it][i], b.a[it][i]);
      }
    }
  }

  void sqr() {
    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n; i++) {
        was[it][i] = (i < n / 2) ? a[it][i] : 0;
      }
      FFT::fft(was[it]);
    }
    for (int it = 0; it < 3; it++) {
      for (int i = 0; i < n; i++) {
        now[it][i] = 0;
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < n; k++) {
          now[i + j][k] = now[i + j][k] + was[i][k] * was[j][k];
        }
      }
    }
    for (int it = 0; it < 3; it++) {
      reverse(now[it] + 1, now[it] + n);
      FFT::fft(now[it]);
      for (int i = 0; i < n; i++) {
        now[it][i] = now[it][i] * ((ld) 1 / n);
      }
    }
    norm();
  }

  void move1() {
    for (int it = 0; it < 3; it++) {
      for (int i = 0; i < n; i++) {
        if (!it) {
          now[it][i] = 0;
        } else {
          now[it][i] = (i < n / 2) ? a[it - 1][i] : 0;
        }
      }
    }
    norm();
  }

  void print() {
    eprintf("{");
    for (int i = 0; i < 10; i++) {
      eprintf("%d, ", a[0][i]);
    }
    eprintf("}{");
    for (int i = 0; i < 10; i++) {
      eprintf("%d, ", a[1][i]);
    }
    eprintf("}\n");
  }
};

int tmp[maxn];

void solve() {
  n0--;
  if (n0 & 1) {
    n0--;
  }
  if (a < 2) {
    printf("0\n");
    return;
  }
  for (n = 1, logn = 0; n < 2 * n0 + 4; n <<= 1, logn++);
  T ans(1);
  T cur(1);
  int bit = 30;
  while (!(a & (1 << bit))) {
    bit--;
  }
  for (; bit >= 2; bit--) {
    if (a & (1 << (bit - 1))) {
      T cur2 = cur;
      cur2.move1();
      ans += cur2;
    } else {
      ans += cur;
    }
    cur.sqr();
    cur.print();
    cur.move1();
    cur.print();
    if (a & (1 << (bit - 1))) {
      cur.move1();
    }
  }
  for (int i = 0; i <= n0; i++) {
    tmp[i] = 0;
  }
  tmp[0] = 1;
  tmp[1] = 2;
  tmp[2] = 1;
  for (int i = 2; i <= n0; i++) {
    add(tmp[i], tmp[i - 2]);
  }
  for (int i = 0; i <= n0; i += 2) {
    add(tmp[i], 1);
  }
  int res = 0;
  for (int i = n0; i >= 0; i -= 2) {
    add(res, ans.a[0][i]);
  }
  for (int i = 0; i <= n0; i++) {
    add(res, mult(ans.a[1][i], tmp[n0 - i]));
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}