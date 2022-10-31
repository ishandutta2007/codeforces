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

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = 998244353;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int power(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, a);
    }
    a = mult(a, a);
    p >>= 1;
  }
  return res;
}

namespace FFT {
  const int maxlog = 16;
  const int maxn = 1 << maxlog;

  int n, logn;
  int rev[maxn];

  int a[maxn], b[maxn];
  int w[2 * maxn];
  
  int roots[maxlog + 1];

  bool wasinit = false;
  int wasn = -1;

  void init() {
    if (wasn != n) {
      wasn = n;
      int & cur = roots[0];
      for (cur = 2; ; cur++) {
        if (power(cur, (mod - 1) / 2) != 1) {
          cur = power(cur, (mod - 1) / (1 << maxlog));
          break;
        }
      }
      for (int i = 1; i <= maxlog; i++) {
        roots[i] = mult(roots[i - 1], roots[i - 1]);
      }
      rev[0] = 0;
      w[1] = 1;
      for (int i = 1, j = -1, cur = 0; i < n; i++) {
        if (!(i & (i - 1))) {
          j++;
          cur = roots[max(0, maxlog - (j + 2))];
        }
        w[2 * i] = w[i];
        w[2 * i + 1] = mult(w[i], cur);
        rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
      }
    }
  }

  void fft(int * a, bool back) {
    if (back) {
      reverse(a + 1, a + n);
      int tomult = power((mod + 1) / 2, logn);
      for (int i = 0; i < n; i++) {
        a[i] = mult(a[i], tomult);
      }
    }

    for (int i = 0; i < n; i++) {
      if (rev[i] < i) {
        swap(a[i], a[rev[i]]);
      }
    }

    for (int i1 = 1, cur = 1; i1 < n; i1 <<= 1) {
      for (int i = 0; i < n; i += i1) {
        for (int it = 0, j = i + i1; it < i1; i++, j++, it++) {
          int toadd = mult(a[j], w[cur + it]);
          a[j] = a[i];
          add(a[i], toadd);
          add(a[j], mod - toadd);
        }
      }
      cur += i1;
    }
  }

  int multfft(int n1, const int * a1, int n2, const int * a2, int * ans) {
    for (n = 1, logn = 0; n < n1 + n2 - 1; n <<= 1, logn++);
    init();
    for (int i = 0; i < n; i++) {
      a[i] = (i < n1) ? a1[i] : 0;
      b[i] = (i < n2) ? a2[i] : 0;
    }
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
      a[i] = mult(a[i], b[i]);
    }
    fft(a, true);
    for (int i = 0; i < n1 + n2 - 1; i++) {
      add(ans[i], a[i]);
    }
    return n1 + n2 - 1;
  }
};

const int maxn = 1 << 15;

int tmp[3][maxn * 2];

struct magic {
  int a[2][maxn];

  magic() {
    memset(a, 0, sizeof(a));
  }

  magic operator*(const magic & b) const {
    magic ans;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        FFT::multfft(maxn, a[i], maxn, b.a[j], tmp[i + j]);
      }
    }
    for (int i = 0; i < maxn; i++) {
      if (i + 1 < maxn) {
        add(tmp[0][i + 1], tmp[2][i]);
        add(tmp[1][i + 1], tmp[2][i]);
      }
      add(tmp[1][i], tmp[2][i]);
    }
    for (int i = 0; i < maxn; i++) {
      ans.a[0][i] = tmp[0][i];
      ans.a[1][i] = tmp[1][i];
    }
    return ans;
  }
};

magic get(int n) {
  magic a, res;
  res.a[0][0] = 1;
  a.a[1][0] = 1;
  while (n) {
    if (n & 1) {
      res = res * a;
    }
    a = a * a;
    n >>= 1;
  }
  return res;
}

void precalc() {
}

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  magic res = get(n);
  for (int i = 1; i <= k; i++) {
    int cur = res.a[0][i];
    add(cur, res.a[1][i]);
    if (i > 0) {
      add(cur, res.a[1][i - 1]);
    }
    printf("%d%c", cur, " \n"[i == k]);
  }
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}