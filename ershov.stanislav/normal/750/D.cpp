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

void precalc() {
}

int gox[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int goy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int maxn = 1000;
int n;
int used[maxn][maxn];
int t[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", t + i);
  }
  return true;
}

void solve() {
  memset(used, 0, sizeof(used));
  vector<pair<pair<int, int>, int> > cur(1, mp(mp(maxn / 2, maxn / 2), 0));
  for (int i = 0; i < n; i++) {
    vector<pair<pair<int, int>, int> > ncur;
    for (auto p : cur) {
      int x = p.first.first;
      int y = p.first.second;
      int dir = p.second;
      for (int j = 0; j < t[i]; j++) {
        x += gox[dir];
        y += goy[dir];
        used[x][y] = true;
      }
      ncur.pb(mp(mp(x, y), (dir + 1) % 8));
      ncur.pb(mp(mp(x, y), (dir + 7) % 8));
    }
    sort(ncur.begin(), ncur.end());
    ncur.resize(unique(ncur.begin(), ncur.end()) - ncur.begin());
    cur = ncur;
  }
  int res = 0;
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      res += used[i][j];
    }
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}