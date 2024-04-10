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

const int maxn = 1e5 + 100;
const int maxm = 3000;
const int MOD = (int) 1e9 + 7;
int n, m;
int dp[maxm][maxm];
char s[maxn];

void add(int & a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

void precalc() {
  dp[0][0] = 1;
  for (int i = 1; i < maxm; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0) {
        add(dp[i][j], dp[i - 1][j - 1]);
      }
      if (j < i) {
        add(dp[i][j], dp[i - 1][j + 1]);
      }
    }
  }
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  swap(n, m);
  scanf("%s", s);
  return true;
}

void solve() {
  int balance = 0;
  int mn = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      balance++;
    } else {
      balance--;
    }
    mn = min(mn, balance);
  }
  int ans = 0;
  for (int i = 0; i <= m - n; i++) {
    for (int j = max(0, -mn); j <= i; j++) {
      if (j + balance >= 0 && j + balance < maxm) {
        add(ans, mult(dp[i][j], dp[m - n - i][j + balance]));
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  precalc();

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