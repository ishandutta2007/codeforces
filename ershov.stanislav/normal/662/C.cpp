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

void precalc() {
}

const int maxn = 1e6;
const int maxm = 21;
int n, m;
vector<int> a;
char s[maxn];

bool read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  a = vector<int> (n);
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++) {
      a[j] *= 2;
      a[j] += (s[j] == '1');
    }
  }
  return true;
}

ll c[1 << 20], d[1 << 20];

void make(ll * arr) {
  for (int j0 = 1; j0 < (1 << m); j0 <<= 1) {
    for (int i = 0; i < (1 << m); i += j0) {
      for (int it = 0, j = i + j0; it < j0; i++, j++, it++) {
        ll na = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = na;
      }
    }
  }
}

void solve() {
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  for (int i = 0; i < n; i++) {
    c[a[i]]++;
  }
  for (int i = 0; i < (1 << m); i++) {
    int cnt = __builtin_popcount(i);
    d[i] = min(cnt, m - cnt);
  }
  make(c);
  make(d);
  for (int i = 0; i < (1 << m); i++) {
    c[i] = c[i] * d[i];
  }
  make(c);
  int mn = inf;
  for (int i = 0; i < (1 << m); i++) {
    mn = min((ll) mn, c[i] / (1 << m));
  }
  printf("%d\n", mn);
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