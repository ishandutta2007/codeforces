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

int q;

map<ll, ll> m;

bool read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < q; i++) {
    int t;
    ll u, v;
    scanf("%d%lld%lld", &t, &u, &v);
    if (t == 2) {
      ll res = 0;
      vector<int> v1, v2;
      ll wasu = u;
      while (u) {
        v1.pb(u % 2);
        u /= 2;
      }
      ll wasv = v;
      while (v) {
        v2.pb(v % 2);
        v /= 2;
      }
      int cnt = 0;
      while (cnt < sz(v1) && cnt < sz(v2) && v1[sz(v1) - 1 - cnt] == v2[sz(v2) - 1 - cnt]) {
        cnt++;
      }
      for (int i = 0; i < sz(v1) - cnt; i++) {
        res += m[wasu];
        wasu /= 2;
      }
      for (int i = 0; i < sz(v2) - cnt; i++) {
        res += m[wasv];
        wasv /= 2;
      }
      printf("%lld\n", res);
    } else {
      int w;
      scanf("%d", &w);
      vector<int> v1, v2;
      ll wasu = u;
      while (u) {
        v1.pb(u % 2);
        u /= 2;
      }
      ll wasv = v;
      while (v) {
        v2.pb(v % 2);
        v /= 2;
      }
      int cnt = 0;
      while (cnt < sz(v1) && cnt < sz(v2) && v1[sz(v1) - 1 - cnt] == v2[sz(v2) - 1 - cnt]) {
        cnt++;
      }
      for (int i = 0; i < sz(v1) - cnt; i++) {
        m[wasu] += w;
        wasu /= 2;
      }
      for (int i = 0; i < sz(v2) - cnt; i++) {
        m[wasv] += w;
        wasv /= 2;
      }
    }
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