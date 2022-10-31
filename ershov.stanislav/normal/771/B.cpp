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

void precalc() {
}

const int maxn = 55;
int n, k;
int vals[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n - k + 1; i++) {
    char str[100];
    scanf("%s", str);
    if (!strcmp(str, "YES")) {
      vals[i] = 1;
    } else {
      vals[i] = 0;
    }
  }
  return true;
}

void solve() {
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    string cur;
    cur.pb('A' + i % 26);
    cur.pb('a' + i / 26);
    names[i] = cur;
  }
  vector<string> ans;
  set<string> used;
  for (int i = 0; i < k - 1; i++) {
    ans.pb(names[i]);
    used.insert(names[i]);
  }
  for (int i = k - 1; i < n; i++) {
    if (vals[i - k + 1]) {
      for (auto s : names) {
        if (used.find(s) == used.end()) {
          ans.pb(s);
          break;
        }
      }
    } else {
      ans.pb(ans[i - k + 1]);
    }
    used.erase(ans[i - k + 1]);
    used.insert(ans[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("%s%c", ans[i].c_str(), " \n"[i == n - 1]);
  }
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
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}