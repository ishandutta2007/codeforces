#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

ll dp[2][30][1 << 7];

void solve() {
  n--, m--;
  bool f1 = false, f2 = false;
  int c1 = 0;
  vector<int> digits;
  while (m) {
    digits.pb(m % 7);
    m /= 7;
    f2 = true;
  }
  if (!f2) {
    digits.pb(0);
  }
  while (n) {
    digits.pb(n % 7);
    n /= 7;
    f1 = true;
    c1++;
  }
  if (!f1) {
    c1++;
    digits.pb(0);
  }
  reverse(digits.begin(), digits.end());
  /*eprintf("%d\n", c1);
  for (int i = 0; i < sz(digits); i++) {
    eprintf("%d%c", digits[i], " \n"[i == sz(digits) - 1]);
  }*/
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int l = 0; l < sz(digits); l++) {
    for (int t = 0; t < 2; t++) {
      for (int mask = 0; mask < (1 << 7); mask++) {
        if (dp[t][l][mask]) {
        } else {
          continue;
        }
        int curr = (!t ? digits[l] : 6);
        for (int i = 0; i <= curr; i++) {
          if (!((mask >> i) & 1)) {
            dp[(t || i < curr) && (l != c1 - 1)][l + 1][mask | (1 << i)] += dp[t][l][mask];
          }
        }
      }
    }
  }
  ll res = 0;
  for (int t = 0; t < 2; t++) {
    for (int mask = 0; mask < (1 << 7); mask++) {
      res += dp[t][sz(digits)][mask];
    }
  }
  printf(LLD "\n", res);
}

int main() {
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