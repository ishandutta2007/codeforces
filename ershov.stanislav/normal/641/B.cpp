#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

const int maxn = 110;
int n, m, q;
int a[maxn][maxn];
int vals[maxn * maxn + 10];

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = i * maxn + j;
    }
  }
  memset(vals, 0, sizeof(vals));
  for (int it = 0; it < q; it++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int r;
      scanf("%d", &r);
      r--;
      for (int i = 0; i + 1 < m; i++) {
        swap(a[r][i], a[r][i + 1]);
      }
    } else if (t == 2) {
      int c;
      scanf("%d", &c);
      c--;
      for (int i = 0; i + 1 < n; i++) {
        swap(a[i][c], a[i + 1][c]);
      }
    } else {
      int r, c, x;
      scanf("%d%d%d", &r, &c, &x);
      r--, c--;
      vals[a[r][c]] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d%c", vals[i * maxn + j], " \n"[j == m - 1]);
    }
  }
}

int main() {
  srand(rdtsc());
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