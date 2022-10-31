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

int n, b;

bool read() {
  if (scanf("%d%d", &n, &b) < 2) {
    return false;
  }
  return true;
}

void solve() {
  queue<ll> q;
  for (int i = 0; i < n; i++) {
    int t, d;
    scanf("%d%d", &t, &d);
    while (sz(q) && q.front() <= t) {
      q.pop();
    }
    ll res = -1;
    if (sz(q) > 0 && sz(q) < b + 1) {
      q.push(q.back() + d);
      res = q.back();
    }
    if (sz(q) == 0) {
      q.push(t + d);
      res = t + d;
    }
    printf(LLD "%c", res, " \n"[i == n - 1]);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}