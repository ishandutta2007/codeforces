#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

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

void precalc() {
}

const int maxn = 135;

struct matrix {
  unsigned a[maxn][maxn];

  matrix() {
    memset(a, 0, sizeof(a));
  }

  matrix operator*(const matrix & b) const {
    matrix res;
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        for (int k = 0; k < maxn; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j];
        }
      }
    }
    return res;
  }
};

matrix power(matrix a, int p) {
  matrix res;
  for (int i = 0; i < maxn; i++) {
    res.a[i][i] = 1;
  }
  while (p) {
    if (p & 1) {
      res = res * a;
    }
    a = a * a;
    p >>= 1;
  }
  return res;
}

int n, p, q;

bool read() {
  if (scanf("%d%d%d", &n, &p, &q) < 3) {
    return false;
  }
  return true;
}

unsigned binoms[maxn];

void solve() {
  p = min(n - 1, p);
  matrix a;
  for (int i = 0; i <= p; i++) {
    a.a[i][i] = a.a[i + 1][i] = 1;
  }
  a = power(a, n);
  for (int i = 0; i <= p; i++) {
    binoms[i] = a.a[i][0];
  }
  unsigned res = 0;
  for (unsigned i = 1; i <= (unsigned) q; i++) {
    unsigned curres = 0;
    for (unsigned cur = 1, j = 0; j <= (unsigned) p; j++) {
      curres += cur * binoms[j];
      cur = cur * i;
    }
    res ^= curres * (unsigned) i;
  }
  printf("%u\n", res);
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}