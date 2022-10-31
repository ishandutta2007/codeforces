#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

struct big {
  static const int k = 4;
  static const ll mx = 1e9;

  ll a[k];
  big (int num = 0) {
    a[0] = num;
    for (int i = 1; i < k; i++) {
      a[i] = 0;
    }
  }

  big operator+(const big & y) const {
    big ans;
    for (int i = 0, add = 0; i < k; i++) {
      ans.a[i] = a[i] + y.a[i] + add;
      add = ans.a[i] / mx;
      ans.a[i] %= mx;
    }
    return ans;
  }

  big operator*(const int & y) const {
    big ans;
    ll add = 0;
    for (int i = 0; i < k; i++) {
      ans.a[i] = a[i] * y + add;
      add = ans.a[i] / mx;
      ans.a[i] %= mx;
    }
    return ans;
  }

  bool operator<(const big & y) const {
    for (int i = k - 1; i >= 0; i--) {
      if (a[i] != y.a[i]) {
        return a[i] < y.a[i];
      }
    }
    return false;
  }
};

const int MOD = (int) 1e9 + 7;
const int primes[3] = {69206017, 70254593, 81788929};
int revprime[3], prodprime[3];
big bigprodprime[3], bigprodall;
int prodall;
const int maxn = 1 << 17;
int roots[3];

inline void add(int & a, int b, int mod = MOD) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

inline int mult(int a, int b, int mod = MOD) {
  return (ll) a * b % mod;
}

int power(int a, int b, int mod = MOD) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = mult(ans, a, mod);
    }
    a = mult(a, a, mod);
    b >>= 1;
  }
  return ans;
}

int getroot(int p) {
  int i;
  for (i = 2; power(i, (p - 1) / 2, p) != 1; i++);
  int topower = p - 1;
  while (topower % 2 == 0) {
    topower /= 2;
  }
  i = power(i, topower, p);
  while (power(i, maxn, p) != 1) {
    i = mult(i, i, p);
  }
  return i;
}

void precalc() {
  for (int i = 0; i < 3; i++) {
    roots[i] = getroot(primes[i]);
  }
  prodall = 1;
  bigprodall = big(1);
  for (int i = 0; i < 3; i++) {
    prodall = mult(prodall, primes[i]);
    bigprodall = bigprodall * primes[i];
  }
  for (int i = 0; i < 3; i++) {
    int prod = 1;
    int prod2 = 1;
    big prodbig(1);
    for (int j = 0; j < 3; j++) {
      if (j != i) {
        prod = mult(prod, primes[j], primes[i]);
        prod2 = mult(prod2, primes[j], MOD);
        prodbig = prodbig * primes[j];
      }
    }
    prodprime[i] = prod2;
    bigprodprime[i] = prodbig;
    revprime[i] = power(prod, primes[i] - 2, primes[i]);
  }
}

namespace FFT {
  int c[maxn], d[maxn];
  int n, logn, rev[maxn];
  int p, root;

  void init() {
    rev[0] = 0;
    for (int i = 1, j = -1; i < n; i++) {
      if (!(i & (i - 1))) {
        j++;
      }
      rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
    }
  }

  void fft(int * a, bool back) {
    for (int i = 0; i < n; i++) {
      if (rev[i] < i) {
        swap(a[i], a[rev[i]]);
      }
    }
    for (int j0 = 1; j0 < n; j0 <<= 1) {
      int tomult;
      if (!back) {
        tomult = power(root, maxn / 2 / j0, p); 
      } else {
        tomult = power(root, maxn - maxn / 2 / j0, p);
      }
      for (int i = 0; i < n; i += j0) {
        int cur = 1;
        for (int j = i + j0, r = i + j0; i < r; i++, j++) {
          int toadd = mult(cur, a[j], p);
          a[j] = a[i];
          add(a[j], p - toadd, p);
          add(a[i], toadd, p);

          cur = mult(cur, tomult, p);
        }
      }
    }
  }

  void multfft(int * a1, int * a2, int * ans) {
    for (int i = 0; i < n; i++) {
      c[i] = a1[i];
      d[i] = a2[i];
    }
    fft(c, 0);
    fft(d, 0);
    for (int i = 0; i < n; i++) {
      c[i] = mult(c[i], d[i], p);
    }
    fft(c, 1);
    int revn = power(n, p - 2, p);
    for (int i = 0; i < n; i++) {
      ans[i] = mult(c[i], revn, p);
    }
  }

  int tmpa[3][maxn], tmpb[3][maxn], tmpans[3][maxn];

  void multbig(int _n, int _logn, int * a1, int * a2, int * ans) {
    n = _n, logn = _logn;
    init();
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < n; i++) {
        tmpa[j][i] = a1[i] % primes[j];
        tmpb[j][i] = a2[i] % primes[j];
      }
      p = primes[j], root = roots[j];
      multfft(tmpa[j], tmpb[j], tmpans[j]);
    }
    /*for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        eprintf("%d%c", tmpans[i][j], " \n"[j == n - 1]);
      }
    }*/

    for (int i = 0; i < n; i++) {
      int cur = 0;
      big curbig;
      for (int j = 0; j < 3; j++) {
        int tomult = mult(revprime[j], tmpans[j][i], primes[j]);
        int prod = mult(prodprime[j], tomult, MOD);
        curbig = curbig + bigprodprime[j] * tomult;
        add(cur, prod);
      }
      big now;
      while (!(curbig < now + bigprodall)) {
        now = now + bigprodall;
        add(cur, MOD - prodall);
      }
      ans[i] = cur;
    }
  }
}

ll n;
int k;
int a[maxn];
int ans[maxn], tmp[maxn];

bool read() {
  if (scanf(LLD "%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  if (n > k) {
    printf("0\n");
    return;
  }
  int m, logm;
  for (m = 1, logm = 0; m <= k; m <<= 1, logm++);
  m <<= 1, logm++;
  vector<int> inv(m);
  for (int i = 1; i < m; i++) {
    inv[i] = power(i, MOD - 2);
  }
  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i < m / 2; i++) {
    a[i] = mult(a[i - 1], inv[i]);
  }
  for (int i = 1; i < m / 2; i++) {
    ans[i] = 0;
  }
  ans[0] = 1;
  {
    int p = n;
    int tomult = 2;
    while (p) {
      if (p & 1) {
        for (int i = 0, cur = 1; i < m; i++, cur = mult(cur, tomult)) {
          ans[i] = mult(ans[i], cur);
        }
        FFT::multbig(m, logm, a, ans, ans);
        for (int i = m / 2; i < m; i++) {
          ans[i] = 0;
        }
      }
      for (int i = 0, cur = 1; i < m; i++, cur = mult(cur, tomult)) {
        tmp[i] = mult(a[i], cur);
      }
      FFT::multbig(m, logm, a, tmp, a);
      for (int i = m / 2; i < m; i++) {
        a[i] = 0;
      }
      p >>= 1;
      tomult = mult(tomult, tomult);
    }
  }
  int res = 0;
  for (int i = 0, tomult = 1; i <= k; i++) {
    add(res, mult(ans[i], tomult));
    tomult = mult(tomult, k - i);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}