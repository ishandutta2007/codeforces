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

const int maxn = 5e5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

vector<int> bad;

bool check(int i) {
  if (i & 1) {
    return a[i] > a[i + 1];
  } else {
    return a[i] < a[i + 1];
  }
}

int solve(int i, int j) {
  swap(a[i], a[j]);
  int res = 1;
  if (i < n - 1 && !check(i)) {
    res = 0;
  }
  if (i > 0 && !check(i - 1)) {
    res = 0;
  }
  if (j < n - 1 && !check(j)) {
    res = 0;
  }
  if (j > 0 && !check(j - 1)) {
    res = 0;
  }
  for (auto k : bad) {
    if (!check(k)) {
      res = 0;
    }
  }
  swap(a[i], a[j]);
  return res;
}

void solve() {
  bad.clear();
  for (int i = 0; i + 1 < n; i++) {
    if (!check(i)) {
      bad.pb(i);
    }
  }
  if (sz(bad) >= 5) {
    printf("0\n");
    return;
  }
  int res = 0;
  vector<pair<int, int> > check;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      int c = bad[0] + i;
      int d = j;
      if (c == d) {
        continue;
      }
      if (c > d) {
        swap(c, d);
      }
      check.eb(c, d);
    }
  }
  sort(check.begin(), check.end());
  check.resize(unique(check.begin(), check.end()) - check.begin());
  for (auto i : check) {
    res += solve(i.first, i.second);
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