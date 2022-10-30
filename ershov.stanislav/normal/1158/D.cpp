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

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

struct point {
  int x, y;

  point () : x(0), y(0) {}

  point (int x, int y) : x(x), y(y) {}

  point operator-(const point & b) {
    return point(x - b.x, y - b.y);
  }

  ll operator^(const point & b) {
    return (ll) x * b.y - (ll) y * b.x;
  }
};

point getPoint() {
  int x, y;
  scanf("%d%d", &x, &y);
  return point(x, y);
}

void precalc() {
}

const int maxn = 1e4;
int n;
point ps[maxn];
char s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i] = getPoint();
  }
  scanf("%s", s);
  return true;
}

int used[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  vector<int> ans;
  {
    int cur = 0;
    for (int i = 1; i < n; i++) {
      if (ps[i].x < ps[cur].x || (ps[i].x == ps[cur].x && ps[i].y < ps[cur].y)) {
        cur = i;
      }
    }
    ans.pb(cur);
    used[cur] = 1;
  }
  for (int step = 0; step < n - 2; step++) {
    int cur = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        if (cur == -1) {
          cur = i;
        } else {
          ll val = (ps[cur] - ps[ans.back()]) ^ (ps[i] - ps[ans.back()]);
          if (s[step] == 'L') {
            if (val < 0) {
              cur = i;
            }
          }
          if (s[step] == 'R') {
            if (val > 0) {
              cur = i;
            }
          }
        }
      }
    }
    ans.pb(cur);
    used[cur] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      ans.pb(i);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
  }
}

int main() {
  precalc();

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}