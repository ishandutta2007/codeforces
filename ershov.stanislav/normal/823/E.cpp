#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;

#define sz(a) (int) (a).size()

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 405;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int c[maxn][maxn];
int f[maxn][maxn];

void solve() {
  memset(c, 0, sizeof(c));
  for (int i = 0; i <= n + 1; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
  }
  memset(f, 0, sizeof(f));
  f[1][0] = 1;
  f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= n - i + 1; j++) {
      for (int l = 0; l <= j; l++) {
        add(f[i][j], mul(mul(2 * j + 1, c[j][l]), mul(f[i - 1][l], f[i - 1][j - l])));
      }
      for (int l = 0; l <= j - 1; l++) {
        add(f[i][j], mul(mul(2 * j, c[j - 1][l]), mul(f[i - 1][l + 1], f[i - 1][j - 1 - l + 1])));
      }
      for (int l = 0; l <= j - 1; l++) {
        add(f[i][j], mul(mul(2 * j, c[j - 1][l]), mul(f[i - 1][l + 2], f[i - 1][j - 1 - l])));
      }
      for (int l = 0; l <= j - 1; l++) {
        add(f[i][j], mul(mul(j, c[j - 1][l]), mul(f[i - 1][l], f[i - 1][j - 1 - l])));
      }
    }
  }
  printf("%d\n", f[n][1]);
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}