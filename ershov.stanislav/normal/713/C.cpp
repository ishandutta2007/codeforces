#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

const int maxn = 3300;

int n;
ll a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    a[i] -= i;
  }
  return true;
}

pair<ll, ll> dp[maxn];

void solve() {
  dp[0] = mp(0, -1e18);
  for (int i = 1; i <= n; i++) {
    dp[i] = mp(1e18, 0);
    multiset<pair<ll, int> > s;
    s.insert(mp(a[i - 1], i - 1));
    auto cur = s.begin();
    int l = 0, r = 0;
    ll suml = 0, sumr = 0;
    for (int j = 1; j <= i; j++) {
      if (dp[i - j].second < cur->first) {
        dp[i] = min(dp[i], mp(dp[i - j].first + cur->first * l - suml + sumr - cur->first * r, cur->first));
      }
      if (j < i) {
        s.insert(mp(a[i - j - 1], i - j - 1));
        if (*cur > mp(a[i - j - 1], i - j - 1)) {
          l++;
          suml += a[i - j - 1];
        } else {
          r++;
          sumr += a[i - j - 1];
        }
        while (l + 1 < r) {
          suml += cur->first;
          cur++;
          sumr -= cur->first;
          l++;
          r--;
        }
        while (l > r) {
          sumr += cur->first;
          cur--;
          suml -= cur->first;
          l--;
          r++;
        }
      }
    }
  }
  printf("%lld\n", dp[n].first);
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