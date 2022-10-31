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
const ld eps = 1e-11;
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

const int mod = (int) 1e9 + 7;
const int maxn = 2e5;
int inv[maxn];
int powers[maxn], powers25[maxn];
int fact[maxn], invfact[maxn];

void add(int & a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int getc(int n, int i) {
  return mult(fact[n], mult(invfact[i], invfact[n - i]));
}

void precalc() {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = mod - mult(inv[mod % i], mod / i);
  }
  powers[0] = 1;
  for (int i = 1; i < maxn; i++) {
    powers[i] = mult(powers[i - 1], 26);
  }
  powers25[0] = 1;
  for (int i = 1; i < maxn; i++) {
    powers25[i] = mult(powers25[i - 1], 25);
  }
  fact[0] = invfact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mult(fact[i - 1], i);
    invfact[i] = mult(invfact[i - 1], inv[i]);
  }
}

const int K = 300;
int q, m;
char s[maxn];
int len[maxn], n[maxn];
  
bool read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  scanf("%s", s);
  int curlen = strlen(s);
  m = 0;
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", s);
      curlen = strlen(s);
    } else {
      int d;
      scanf("%d", &d);
      len[m] = curlen;
      n[m] = d;
      m++;
    }
  }
  return true;
}

int dp[maxn];

void solve() {
  int waslen = -1;
  for (int i = 0; i < m; i++) {
    if (n[i] < len[i]) {
      printf("0\n");
      continue;
    }
    if (len[i] < K) {
      int ans = powers[n[i]];
      for (int j = 0; j < len[i]; j++) {
        add(ans, mod - mult(powers25[n[i] - j], getc(n[i], j)));
      }
      printf("%d\n", ans);
    } else {
      int curlen = len[i];
      if (waslen != curlen) {
        dp[0] = 0;
        for (int i = 1; i < maxn; i++) {
          dp[i] = mult(dp[i - 1], 26);
          if (i - curlen >= 0) {
            add(dp[i], mult(powers25[i - curlen], getc(i - 1, curlen - 1)));
          }
        }
        waslen = curlen;
      }
      printf("%d\n", dp[n[i]]);
    }
  }
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