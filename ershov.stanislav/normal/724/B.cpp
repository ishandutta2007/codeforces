#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

const int maxn = 50;
int n, m;
int a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i] + j);
      a[i][j]--;
    }
  }
  return true;
}

vector<int> id;

bool check(vector<int> perm) {
  for (int i = 0; i < n; i++) {
    vector<int> cur(m);
    for (int j = 0; j < m; j++) {
      cur[j] = perm[a[i][j]];
    }
    bool ok = false;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        vector<int> ncur = id;
        swap(ncur[k], ncur[j]);
        if (ncur == cur) {
          ok = true;
          break;
        }
      }
    }
    if (!ok) {
      return false;
    }
  }
  return true;
}

void solve() {
  id.resize(m);
  for (int i = 0; i < m; i++) {
    id[i] = i;
  }
  if (check(id)) {
    printf("YES\n");
    return;
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      vector<int> cur = id;
      swap(cur[i], cur[j]);
      if (check(cur)) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
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