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
int n[2];
vector<int> happy[2];

bool read() {
  if (scanf("%d%d", &n[0], &n[1]) < 2) {
    return false;
  }
  for (int it = 0; it < 2; it++) {
    happy[it].clear();
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int cur;
      scanf("%d", &cur);
      happy[it].pb(cur);
    }
  }
  return true;
}

int gcd;
int inv[2], good[2];

int gcdExt(int a, int b, int & x, int & y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  } else {
    int k = a / b;
    int res = gcdExt(b, a % b, y, x);
    y -= x * k;
    return res;
  }
}

int getid(int i, int it) {
  return (ll) (i / gcd % good[it]) * inv[!it] % good[it];
}

void solve() {
  {
    int x, y;
    gcd = gcdExt(n[0], n[1], x, y);
    good[0] = n[0] / gcd;
    good[1] = n[1] / gcd;
    inv[0] = (x % n[1] + n[1]) % n[1];
    inv[1] = (y % n[0] + n[0]) % n[0];
  }
  //eprintf("gcd = %d, invn = %d\n", gcd, invn);
  vector<vector<pair<int, ll> > > v(gcd * 2);
  vector<vector<int> > have(gcd * 2);
  for (int it = 0; it < 2; it++) {
    for (auto j : happy[it]) {
      have[j % gcd + it * gcd].pb(getid(j, it));
      v[j % gcd + it * gcd].pb(mp(getid(j, it), -j));
      v[j % gcd + (1 - it) * gcd].pb(mp(getid(j, !it), -j));
    }
  }
  ll res = 0;
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < gcd; i++) {
      vector<pair<int, ll> > & cur = v[i + it * gcd];
      vector<int> & curhave = have[i + it * gcd];
      sort(curhave.begin(), curhave.end());
      sort(cur.begin(), cur.end());
      if (!sz(cur)) {
        printf("-1\n");
        return;
      }
      cur.pb(cur[0]);
      for (int i = 0; i + 1 < sz(cur); i++) {
        ll b = cur[i + 1].first, a = cur[i].first;
        ll dist = b - a;
        if (dist < 0) {
          dist += good[it];
        }
        if (dist == 0 && i == sz(cur) - 2) {
          dist += good[it];
        }
        while (dist > 0 && binary_search(curhave.begin(), curhave.end(), (b + good[it] - 1) % good[it])) {
          dist--;
          b = (b + good[it] - 1) % good[it];
        }
        if (dist == 0) {
          continue;
        }
        ll l = 0, r = 8e18;
        while (l < r) {
          ll mid = l + (r - l) / 2;
          if ((mid + cur[i].second + n[!it]) / n[!it] >= dist) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        //eprintf(LLD "\n", l);
        res = max(res, l);
      }
    }
  }
  printf(LLD "\n", res);
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