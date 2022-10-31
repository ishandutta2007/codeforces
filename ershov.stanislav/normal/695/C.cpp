#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);


void precalc() {
}

struct point {
  int x, y;

  void read() {
    assert(scanf("%d%d", &x, &y) == 2);
  }
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}

  inline point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  inline long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }

  inline bool operator < (const point &p) const {
    if (y != p.y) {
      return y < p.y;
    }
    return x < p.x;
  }
};

bool inside(point a, point b, point p) {
  if ((b - a) ^ (p - a)) {
    return 0;
  }
  if (b < a) {
    swap(a, b);
  }
  if (p < a || b < p) {
    return 0;
  }
  return 1;
}

const int maxn = 1000 + 10;
point ps[maxn], qs[maxn];

int k, n;

int read() {
  if (scanf("%d%d", &k, &n) < 2) {
    return 0;
  }
  for (int i = 0; i < k; ++i) {
    qs[i].read();
  }
  for (int i = 0; i < n; ++i) {
    ps[i].read();
  }
  return 1;
}

const int maxk = 7;
int betw[maxk][maxn][maxk];
int cnt[maxk][maxn];

map<pair<long long, int>, int> mem;

int Q;

long long getHash(const vector<int> &people) {
  long long res = 0;
  for (int i = 0; i < sz(people); ++i) {
    res *= Q;
    res += people[i] + 1;
  }
  return res;
}

int tmp[maxk];

int solve(vector<int> people, int mask) {
  int szmask = __builtin_popcount(mask);
  int cnt = sz(people);
  if (szmask < cnt) {
    return 0;
  }
  if (cnt == 0) {
    return 1;
  }

  long long hash = getHash(people);
  auto iter = mem.find(mp(hash, mask));
  if (iter != mem.end()) {
    return iter->second;
  }
  for (int x = 0; x < k; ++x) {
    if (!((mask >> x) & 1)) {
      continue;
    }
    for (int i = 0; i < sz(people); ++i) {
      int *ar = betw[x][people[i]];
      int cntar = ::cnt[x][people[i]];
      if (szmask - 1 < max(cntar, sz(people) - 1)) {
        continue;
      }
      for (int j = 0; j < sz(people); ++j) {
        if (j == i) {
          continue;
        }
        tmp[j - (j >= i)] = people[j];
      }
      vector<int> npeople(sz(people) - 1 + cntar);
      merge(ar, ar + cntar, tmp, tmp + sz(people) - 1, npeople.begin());
      npeople.resize(unique(npeople.begin(), npeople.end()) - npeople.begin());
      if (solve(npeople, mask ^ (1 << x))) {
        return mem[mp(hash, mask)] = 1;
      }
    }
  }
  return mem[mp(hash, mask)] = 0;
}

void solve() {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        if (k == j) {
          continue;
        }
        if (cnt[i][j] == ::k) {
          break;
        }
        if (inside(qs[i], ps[j], ps[k])) {
          betw[i][j][cnt[i][j]++] = k;
        }
      }
    }
  }

  mem.clear();
  int res = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> people;
    people.pb(i);
    res += solve(people, (1 << k) - 1);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
  Q = rnd((int) 1e9) + (int) 5e8;
#ifdef LOCAL
  assert(freopen(TASK ".out", "w", stdout));
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}