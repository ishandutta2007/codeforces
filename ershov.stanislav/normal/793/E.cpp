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

const int maxn = 5100;

int n;
int good[4];
vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree.clear();
  tree.resize(n);
  for (int i = 0; i < 4; i++) {
    scanf("%d", good + i);
    good[i]--;
  }
  for (int i = 1; i < n; i++) {
    int pr;
    scanf("%d", &pr);
    pr--;
    tree[pr].pb(i);
  }
  return true;
}

int cnt[maxn];
int see[maxn];

int a, b;

vector<int> va, vb;

void dfs(int v) {
  cnt[v] = !sz(tree[v]);
  see[v] = 0;
  for (int i = 0; i < 4; i++) {
    if (v == good[i]) {
      see[v] |= (1 << i);
    }
  }
  for (auto to : tree[v]) {
    dfs(to);
    cnt[v] += cnt[to];
    see[v] |= see[to];
  }
  if (v != 0) {
    for (auto to : tree[v]) {
      if (see[to] == see[v]) {
        continue;
      }
      if (see[v] == 1) {
        va.pb(cnt[to]);
      } else if (see[v] == 2) {
        b += cnt[to];
        va.pb(cnt[to]);
      } else if (see[v] == 4) {
        a += cnt[to];
        vb.pb(cnt[to]);
      } else if (see[v] == 8) {
        vb.pb(cnt[to]);
      }
    }
  } else {
    for (auto to : tree[v]) {
      if (see[to]) {
        continue;
      }
      va.pb(cnt[to]);
      vb.pb(cnt[to]);
    }
  }
}

int dp[maxn];

void solve() {
  a = 0, b = 0;
  va.clear();
  vb.clear();
  dfs(0);
  int need = (cnt[0] - 4) / 2;
  if (cnt[0] & 1) {
    printf("NO\n");
    return;
  }
  if (a > need || b > need) {
    printf("NO\n");
    return;
  }
  {
    a = need - a;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto x : va) {
      for (int i = maxn - 1 - x; i >= 0; i--) {
        if (dp[i]) {
          dp[i + x] = 1;
        }
      }
    }
    if (!dp[a]) {
      printf("NO\n");
      return;
    }
  }
  {
    b = need - b;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto x : vb) {
      for (int i = maxn - 1 - x; i >= 0; i--) {
        if (dp[i]) {
          dp[i + x] = 1;
        }
      }
    }
    if (!dp[b]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
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