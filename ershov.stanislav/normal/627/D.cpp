#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 5e5;
int n, k;
int a[maxn];
vector<int> tree[maxn];
int mid;
pair<int, bool> dp[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    tree[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  return true;
}

void dfs1(int v, int par = -1) {
  int sum = 0, mx = 0;
  bool all = true;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    dfs1(to, v);
    all &= dp[to].second;
    if (dp[to].second) {
      sum += dp[to].first;
    } else {
      mx = max(dp[to].first, mx);
    }
  }
  dp[v] = mp(sum + mx + 1, all);
  if (a[v] < mid) {
    dp[v] = mp(0, 0);
  }
}

bool ok;

void solve(int v, int par = -1, int cnt = 0, int canall = 1) {
  int m = sz(tree[v]);
  vector<int> sumpref(m + 1), sumsuff(m + 1), mxpref(m + 1), mxsuff(m + 1), allpref(m + 1), allsuff(m + 1);
  allpref[0] = 1, allsuff[m] = 1;
  for (int i = 0; i < m; i++) {
    sumpref[i + 1] = sumpref[i];
    mxpref[i + 1] = mxpref[i];
    allpref[i + 1] = allpref[i];
    if (tree[v][i] != par) {
      if (dp[tree[v][i]].second == true) {
        sumpref[i + 1] += dp[tree[v][i]].first;
      } else {
        mxpref[i + 1] = max(mxpref[i + 1], dp[tree[v][i]].first);
        allpref[i + 1] = false;
      }
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    sumsuff[i] = sumsuff[i + 1];
    mxsuff[i] = mxsuff[i + 1];
    allsuff[i] = allsuff[i + 1];
    if (tree[v][i] != par) {
      if (dp[tree[v][i]].second == true) {
        sumsuff[i] += dp[tree[v][i]].first;
      } else {
        mxsuff[i] = max(mxsuff[i + 1], dp[tree[v][i]].first);
        allsuff[i] = false;
      }
    }
  }
  int mxup = 0, sumup = 0;
  if (canall) {
    sumup += cnt;
  } else {
    mxup += cnt;
  }
  if (dp[v].first != 0) {
    if (sumup + sumpref[m] + max(mxup, mxpref[m]) + 1 >= k) {
      ok = true;
    }
  }
  for (int i = 0; i < m; i++) {
    if (tree[v][i] == par) {
      continue;
    }
    if (dp[v].first != 0) {
      solve(tree[v][i], v, sumup + sumpref[i] + sumsuff[i + 1] + 1 + max(mxup, max(mxpref[i], mxsuff[i + 1])), canall & allpref[i] & allsuff[i + 1]);
    } else {
      solve(tree[v][i], v, 0, 0);
    }
  }
}

void solve() {
  ll l = 1, r = 1e6 + 100;
  while (l < r - 1) {
    mid = (l + r) / 2;
    ok = false;
    dfs1(0);
    /*for (int i = 0; i < n; i++) {
      eprintf("(%d %d), ", dp[i].first, dp[i].second);
    }
    eprintf("\n");*/
    solve(0);
    if (ok) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%d\n", l);
}

int main() {
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}