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

const int maxn = 1e6 + 100;
int n, k;
int c[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  return true;
}

bool checkprime(int p, int r) {
  bool res = false;
  for (int i = 0; i < n; i++) {
    int curcnt = 0;
    int cur = c[i];
    while (cur % p == 0) {
      curcnt++;
      cur /= p;
    }
    if (curcnt >= r) {
      res = true;
      break;
    }
  }
  return res;
}

void solve() {
  vector<pair<int, int> > primes;
  for (int i = 2; i * i <= k; i++) {
    int curcnt = 0;
    while (k % i == 0) {
      k /= i;
      curcnt++;
    }
    if (curcnt) {
      primes.eb(i, curcnt);
    }
  }
  if (k > 1) {
    primes.eb(k, 1);
  }
  bool res = true;
  for (auto i : primes) {
    res &= checkprime(i.first, i.second);
  }
  printf(res ? "Yes\n" : "No\n");
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