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

const int maxn = 26;
int n;
int a[maxn];
char s[500000];

int gcd(int a, int b) {
  if (!b) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

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
  int mn = inf, cntmn = 0;
  int mni = -1;
  int gcdall = 0;
  int sumall = 0;
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    sumall += a[i];
    int pw = 0;
    while (!(cur & 1)) {
      cur /= 2;
      pw++;
    }
    if (pw < mn) {
      mn = pw;
      mni = i;
      cntmn = 0;
    }
    if (pw == mn) {
      cntmn++;
    }
    gcdall = gcd(gcdall, cur);
  }
  int x;
  if (cntmn == 1) {
    x = mn;
  } else {
    x = max(0, mn - 1);
  }
  int todel = gcdall * (1 << x);
  int ans = todel;
  if (cntmn > 1 && mn == 0) {
    ans = 0;
  }
  if ((sumall / todel) % 2 == 0) {
    ans *= 2;
  }
  for (int i = 0; i < n; i++) {
    a[i] /= todel;
  }
  int curlen = 0;
  for (int i = 0; i < n; i++) {
    if (i == mni) {
      continue;
    }
    for (int j = 0; j < a[i] / 2; j++) {
      s[curlen++] = 'a' + i;
    }
  }
  for (int j = 0; j < a[mni]; j++) {
    s[curlen++] = 'a' + mni;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == mni) {
      continue;
    }
    for (int j = 0; j < (a[i] + 1) / 2; j++) {
      s[curlen++] = 'a' + i;
    }
  }
  s[curlen] = 0;
  printf("%d\n", ans);
  for (int i = 0; i < todel; i++) {
    printf("%s", s);
  }
  printf("\n");
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