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

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 2e6 + 100;
int n, m;
int h[maxn];
int MOD;
vector<pair<int, int> > ab[maxn];

int add(int a, int b) {
  int ans = (a + b) % MOD;
  if (ans >= MOD) {
    ans -= MOD;
  }
  return ans;
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", h + i); 
    ab[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    ab[a].pb(mp(b, i));
  }
  return true;
}

void solve() {
  vector<int> maxlenl(n), cntl(n);
  vector<vector<int> > maxlenl2(n);
  {
    vector<int> dp(n + 1, INF);
    vector<vector<int> > sumpref(n + 1, vector<int> (1, 0));
    vector<int> sumall(n + 1);
    vector<vector<int> > was(n + 1);
    dp[0] = 0;
    sumall[0] = 1;
    was[0].pb(0);
    for (int i = 0; i < n; i++) {
      for (int r = 0; r < sz(ab[i]); r++) {
        maxlenl2[i].pb((int) (lower_bound(dp.begin(), dp.end(), ab[i][r].first) - dp.begin()));
      }
      int j = (int) (lower_bound(dp.begin(), dp.end(), h[i]) - dp.begin());
      int k = (int) (upper_bound(was[j - 1].begin(), was[j - 1].end(), h[i], greater<int>()) - was[j - 1].begin());
      int cursum = add(sumall[j - 1], MOD - sumpref[j - 1][k]);
      sumall[j] = add(sumall[j], cursum);
      sumpref[j].pb(sumall[j]);
      was[j].pb(h[i]);
      maxlenl[i] = j;
      cntl[i] = cursum;
      dp[j] = h[i];
    }
  }
  vector<int> maxlenr(n), cntr(n);
  vector<vector<int> > maxlenr2(n);
  {
    vector<int> dp(n + 1, -INF);
    vector<vector<int> > sumpref(n + 1, vector<int> (1));
    vector<int> sumall(n + 1);
    vector<vector<int> > was(n + 1);
    dp[0] = INF;
    sumall[0] = 1;
    was[0].pb(INF);
    for (int i = n - 1; i >= 0; i--) {
      /*for (int i = 0; i < n; i++) {
        eprintf("%d%c", dp[i], " \n" [i == n - 1]);
      }*/
      for (int r = 0; r < sz(ab[i]); r++) {
        maxlenr2[i].pb((int) (lower_bound(dp.begin(), dp.end(), ab[i][r].first, greater<int> ()) - dp.begin()));
      }
      int j = (int) (lower_bound(dp.begin(), dp.end(), h[i], greater<int>()) - dp.begin());
      int k = (int) (upper_bound(was[j - 1].begin(), was[j - 1].end(), h[i]) - was[j - 1].begin());
      int cursum = add(sumall[j - 1], MOD - sumpref[j - 1][k]);
      sumall[j] = add(sumall[j], cursum);
      sumpref[j].pb(sumall[j]);
      was[j].pb(h[i]);
      maxlenr[i] = j;
      cntr[i] = cursum;
      dp[j] = h[i];
    }
  }
  int longest = 0, cntall = 0;
  for (int i = 0; i < n; i++) {
    if (longest < maxlenl[i]) {
      longest = maxlenl[i];
      cntall = 0;
    }
    if (longest == maxlenl[i]) {
      cntall = add(cntall, cntl[i]);
    }
  }
  vector<int> ans(m);
  for (int t = 0; t < n; t++) {
    for (int r = 0; r < sz(ab[t]); r++) {
      int a = t, b = ab[t][r].first;
      int curans = 0;
      if (longest != maxlenl[a] + maxlenr[a] - 1 || mult(cntl[a], cntr[a]) != cntall) {
        curans = longest;
      }
        curans = max(curans, maxlenl2[a][r] + maxlenr2[a][r] - 1);
        //eprintf("%d %d\n", maxlenl2[a][r], maxlenr2[a][r]);
      ans[ab[t][r].second] = max(curans, longest - 1);
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
  }
}

bool isprime(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  srand(rdtsc());
  MOD = (int) 1e9 + rnd(1e6);
  while (!isprime(MOD)) {
    MOD++;
  }
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