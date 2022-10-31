#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 5e5;
int minp[maxn], primes[maxn], cntp;
int inv[maxn];

const int mod = (int) 1e9 + 7;

void add(int & a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

void precalc() {
  cntp = 0;
  memset(minp, -1, sizeof(minp));
  for (int i = 2; i < maxn; i++) {
    if (minp[i] == -1) {
      primes[cntp] = i;
      minp[i] = cntp;
      cntp++;
    }
    for (int j = 0; j <= minp[i]; j++) {
      int nxt = primes[j] * i;
      if (nxt > maxn) {
        break;
      }
      minp[nxt] = j;
    }
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = mult((mod - inv[mod % i]), mod / i);
  }
}

int n;
int a[maxn];
int dp[maxn], dp2[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  vector<vector<int> > v(cntp);
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    int pw = 0;
    while (cur > 1) {
      int pid = minp[cur];
      int curp = primes[pid];
      cur /= curp;
      pw++;
      if (cur % curp) {
        v[pid].pb(pw);
        pw = 0;
      }
    }
  }
  memset(dp, 0, sizeof(dp));
  dp2[0] = 1;
  for (int i = 1; i < n; i++) {
    dp2[i] = mult(dp2[i - 1], mult(n - i, inv[i]));
  }
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1];
    add(dp[i], dp2[i - 1]);
  }

  int res = 0;
  for (int i = 0; i < cntp; i++) {
    sort(v[i].begin(), v[i].end());
    for (int j = 0; j < sz(v[i]); j++) {
      add(res, mod - mult(v[i][j], dp[sz(v[i]) - j - 1]));
      add(res, mult(v[i][j], dp[n - sz(v[i]) + j]));
    }
  }
  printf("%d\n", res);
}

int main() {
  srand(rdtsc());
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