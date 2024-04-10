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

const int maxn = (int) 2e6 + 100;
int n, a, b, T;
char s[maxn];
int sumpref[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &a, &b, &T) < 1) {
    return false;
  }
  scanf("%s", s);
  return true;
}

void solve() {
  for (int i = 0; i < 2 * n; i++) {
    sumpref[i + 1] = sumpref[i] + 1 + b * (s[i % n] == 'w');
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int l = i, r = 2 * n + 1;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      ll curans = sumpref[mid] - sumpref[i];
      if (i < n && mid > n + 1) {
        curans += (ll) a * min(abs(n - i), abs(mid - 1 - n));
        curans += (ll) a * (mid - i - 1);
      } else {
        curans += (ll) a * max(n - i, mid - 1 - n);
      }
      if (curans <= T) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (l > n) {
      mx = max(mx, l - i);
    }
  }
  printf("%d\n", min(mx, n));
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