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

ll m;

bool read() {
  if (scanf("%lld", &m) < 1) {
    return false;
  }
  return true;
}

pair<ll, ll> solve(ll m) {
  if (m < 0) {
    return mp(0, 0);
  }
  if (m == 1) {
    return mp(0, 0);
  }
  ll l = 1, r = 1e6;
  while (l < r - 1) {
    ll mid = (l + r) / 2;
    if (mid * mid * mid < m) {
      l = mid;
    } else {
      r = mid;
    }
  }
  pair<ll, ll> ans1 = solve(m - l * l * l);
  ans1.first++;
  ans1.second += l * l * l;
  pair<ll, ll> ans2 = mp(0, 0);
  if (l > 1) {
    ans2 = solve(l * l * l - (l - 1) * (l - 1) * (l - 1));
    ans2.first++;
    ans2.second += (l - 1) * (l - 1) * (l - 1);
  }
  return max(ans1, ans2);
}

void solve() {
  m++;
  pair<ll, ll> res = solve(m);
  printf("%lld %lld\n", res.first, res.second);
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