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

const int maxn = 1100;

int n;
pair<string, string> s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    s[i].first = s1.substr(0, 3);
    s[i].second = s1.substr(0, 2) + s2[0];
  }
  return true;
}

int ans[maxn];
map<string, vector<int> > cnt;

set<string> used;

void dfs(string s) {
  if (used.find(s) != used.end()) {
    return;
  }
  used.insert(s);
  for (auto i : cnt[s]) {
    ans[i] = 1;
    dfs(::s[i].second);
  }
}

void solve() {
  used.clear();
  cnt.clear();
  for (int i = 0; i < n; i++) {
    cnt[s[i].first].pb(i);
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) {
    if (sz(cnt[s[i].first]) > 1) {
      ans[i] = 1;
      dfs(s[i].second);
    }
  }
  set<string> bad;
  vector<string> toprint;
  for (int i = 0; i < n; i++) {
    toprint.pb(ans[i] ? s[i].second : s[i].first);
    if (bad.find(toprint.back()) != bad.end()) {
      printf("NO\n");
      return;
    }
    bad.insert(toprint.back());
  }
  printf("YES\n");
  for (auto s : toprint) {
    printf("%s\n", s.c_str());
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