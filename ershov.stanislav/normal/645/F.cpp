#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

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

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  int ans = a + b;
  if (ans >= MOD) {
    ans -= MOD;
  }
  return ans;
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

int power(int a, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = mult(ans, a);
    }
    p >>= 1;
    a = mult(a, a);
  }
  return ans;
}

const int maxn = 2e6 + 100;
int n, k, q;
int a[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n + q; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  vector<int> c(n + q);
  c[k - 1] = 1;
  for (int j = k; j < n + q; j++) {
    c[j] = mult(c[j - 1], mult(j, power(j - k + 1, MOD - 2)));
  }
  int curans = 0;
  vector<int> cnt(maxn);
  vector<int> phi(maxn);
  for (int i = 1; i < maxn; i++) {
    phi[i] = i;
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = i * 2; j < maxn; j += i) {
      phi[j] -= phi[i];
    }
  }
  for (int i = 0; i < n + q; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        curans = add(curans, mult(phi[j], c[cnt[j]]));
        cnt[j]++;
        if (j * j < a[i]) {
          int nj = a[i] / j;
          curans = add(curans, mult(phi[nj], c[cnt[nj]]));
          cnt[nj]++;
        }
      }
    }
    if (i >= n) {
      printf("%d\n", curans);
    }
  }
}

int main() {
  srand(rdtsc());
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