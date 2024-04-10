#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

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

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

int n;
map<int, int> x, y;
map<pair<int, int>, int> all;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  x.clear();
  y.clear();
  all.clear();
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    x[a]++;
    y[b]++;
    all[mp(a, b)]++;
  }
  return true;
}

void solve() {
  ll ans = 0;
  for (auto i : x) {
    ans += (ll) i.second * (i.second - 1) / 2;
  }
  for (auto i : y) {
    ans += (ll) i.second * (i.second - 1) / 2;
  }
  for (auto i : all) {
    ans -= (ll) i.second * (i.second - 1) / 2;
  }
  printf(LLD "\n", ans);
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