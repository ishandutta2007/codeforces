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

const int maxn = 510;
int n, k;
char s[maxn][maxn];
int col[maxn][maxn];
int sizes[maxn * maxn], cursizes[maxn * maxn];
int cntcols;

bool isgood(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
  if (!isgood(x, y) || s[x][y] == 'X') {
    return;
  }
  if (col[x][y] != -1) {
    return;
  }
  col[x][y] = cntcols;
  sizes[cntcols]++;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  return true;
}

bool used[maxn * maxn];
int todel[maxn * maxn];
int cnttodel;
int curans;

void makedel(int x, int y) {
  int curcol = col[x][y];
  if (curcol == -1) {
    return;
  }
  if (used[curcol]) {
    return;
  }
  used[curcol] = true;
  todel[cnttodel++] = curcol;
  curans += cursizes[curcol];
}

void solve() {
  memset(sizes, 0, sizeof(sizes));
  memset(col, -1, sizeof(col));
  cntcols = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (col[i][j] == -1 && s[i][j] != 'X') {
        dfs(i, j);
        cntcols++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i + k <= n; i++) {
    memcpy(cursizes, sizes, cntcols * sizeof(int));
    for (int i0 = i; i0 < i + k; i0++) {
      for (int j0 = 0; j0 < k; j0++) {
        if (col[i0][j0] != -1) {
          cursizes[col[i0][j0]]--;
        }
      }
    }
    for (int j = 0; j + k <= n; j++) {
      curans = k * k;
      cnttodel = 0;
      if (i) {
        for (int j0 = j; j0 < j + k; j0++) {
          makedel(i - 1, j0);
        }
      }
      if (i + k < n) {
        for (int j0 = j; j0 < j + k; j0++) {
          makedel(i + k, j0);
        }
      }
      if (j) {
        for (int i0 = i; i0 < i + k; i0++) {
          makedel(i0, j - 1);
        }
      }
      if (j + k < n) {
        for (int i0 = i; i0 < i + k; i0++) {
          makedel(i0, j + k);
        }
      }
      ans = max(ans, curans);
      for (int r = 0; r < cnttodel; r++) {
        used[todel[r]] = false;
      }
      if (j + k < n) {
        for (int i0 = i; i0 < i + k; i0++) {
          cursizes[col[i0][j]]++;
          cursizes[col[i0][j + k]]--;
        }
      }
    }
  }
  printf("%d\n", ans);
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