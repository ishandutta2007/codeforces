#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
const int gox[] = {1, 0, -1, 0}, goy[] = {0, 1, 0, -1};
const char goc[] = "DRUL";
int n, m, k;
char c[maxn][maxn];
int sx, sy;

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

int d[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == 'X') {
        sx = i;
        sy = j;
        c[i][j] = '.';
      }
      c[i][j] = (c[i][j] == '*');
    }
  }
  {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d[i][j] = inf;
      }
    }
    d[sx][sy] = 0;
    vector< pair<int, int> > q;
    q.push_back(make_pair(sx, sy));
    for (int l = 0; l < sz(q); l++) {
      int x = q[l].first, y = q[l].second;
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + gox[dir], ny = y + goy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !c[nx][ny] && d[nx][ny] == inf) {
          d[nx][ny] = d[x][y] + 1;
          q.push_back(make_pair(nx, ny));
        }
      }
    }
  }
  string ans;
  int x = sx, y = sy;
  for (int i = 0; i < k; i++) {
    int bdir = -1;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && !c[nx][ny] && d[nx][ny] <= k - i - 1 && (d[nx][ny] & 1) == ((k - i - 1) & 1)) {
        if (bdir == -1 || goc[dir] < goc[bdir]) {
          bdir = dir;
        }
      }
    }
    if (bdir == -1) {
      printf("IMPOSSIBLE\n");
      return;
    }
    ans += goc[bdir];
    x += gox[bdir];
    y += goy[bdir];
  }
  assert(x == sx && y == sy);
  printf("%s\n", ans.c_str());
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}