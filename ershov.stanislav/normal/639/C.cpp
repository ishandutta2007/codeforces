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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 9e5 + 100;
int n, k;
ll a[maxn];
ll b[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n + 1; i++) {
    scanf(LLD, a + i);
    b[i] = a[i];
  }
  return true;
}

void solve() {
  int res = 0;
  ll add = 0;
  int cnt = 0;
  for (int i = 0; i < n + 1 || add; i++) {
    cnt++;
    ll na = ((a[i] + add) % 2 + 2) % 2;
    add = (a[i] + add - na) / 2;
    a[i] = na;
    if (i > 2e5 + 1000) {
      break;
    }
  }
  /*for (int i = 0; i < cnt; i++) {
    eprintf("%d%c", (int) a[i], " \n"[i == cnt - 1]);
  }*/
  if (cnt > 2e5 + 100) {
    for (int i = cnt - 1; i >= 0; i--) {
      a[i]--;
    }
    for (int i = 0; ; i++) {
      if (!a[i]) {
        a[i]--;
        break;
      }
      a[i] = 0;
    }
    while (a[cnt - 1] == 0) {
      cnt--;
    }
  }
  ll cur = 0;
  for (int i = cnt - 1; i >= 0; i--) {
    if (a[i]) {
      res = 0;
    }
    cur *= 2;
    cur += a[i];
    if (i < n + 1 && abs(b[i] - cur) <= k) {
      if (i != n || b[i] != cur) {
        res++;
      }
    }
    if (abs(cur) > 1e10) {
      break;
    }
  }
  printf("%d\n", res);
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