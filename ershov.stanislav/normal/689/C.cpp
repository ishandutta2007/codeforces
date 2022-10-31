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

ll getcnt(ll n) {
  ll ans = 0;
  for (ll i = 2; i * i * i <= n; i++) {
    ans += n / (i * i * i);
  }
  return ans;
}

ll m;

bool read() {
  if (scanf("%lld", &m) < 1) {
    return false;
  }
  return true;
}

void solve() {
  ll l = 1, r = m * 10;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (getcnt(mid) < m) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (getcnt(l) == m) {
    printf("%lld\n", l);
  } else {
    printf("-1\n");
  }
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