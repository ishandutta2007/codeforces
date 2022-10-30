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

const int maxn = 1e6 + 100;

int n;
int nxt[maxn];
int used[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", nxt + i);
    nxt[i]--;
  }
  return true;
}

int ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    used[i + 1] = 0;
  }
  int cur = 1;
  for (int i = 0; i < n; i++) {
    while (used[cur]) {
      cur++;
    }
    if (nxt[i] == -2) {
      nxt[i] = i + 1;
    }
    ans[i] = cur + nxt[i] - i - 1;
    if (used[ans[i]]) {
      printf("-1\n");
      return;
    }
    used[ans[i]] = 1;
  }
  vector<int> st;
  ans[n] = n + 1;
  st.pb(n);
  for (int i = n - 1; i >= 0; i--) {
    while (ans[st.back()] < ans[i]) {
      st.pop_back();
    }
    if (nxt[i] != st.back()) {
      printf("-1\n");
      return;
    }
    st.pb(i);
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
}

int main() {
  precalc();

  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}