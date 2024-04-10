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

const int maxn = 2e5;
int n;

ll x[maxn][3];
ll sum[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf(LLD, x[i] + j);
    }
    sum[i] = 0;
    for (int j = 0; j < 3; j++) {
      sum[i] += x[i][j];
    }
    for (int j = 0; j < 3; j++) {
      x[i][j] = sum[i] - 2 * x[i][j];
    }
  }
  return true;
}
ll a, b, c;
ll needadd;

bool check(ll mid) {
  //eprintf(LLD "\n", mid);
  vector<ll> l(3, -3e18), r(3, 3e18);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      l[j] = max(l[j], x[i][j] - mid);
      r[j] = min(r[j], x[i][j] + mid);
    }
  }
  for (int j = 0; j < 3; j++) {
    if (l[j] > r[j]) {
      return false;
    }
  }
  ll summn = 0, summx = 0;
  for (int j = 0; j < 3; j++) {
    summn += l[j];
    summx += r[j];
  }
  ll wasmn = summn;
  for (int i = 0; i < n; i++) {
    summn = max(summn, sum[i] - mid);
    summx = min(summx, sum[i] + mid);
  }
  if (summn > summx) {
    needadd = ((unsigned long long) (summn - summx) + 3) / 4;
    return false;
  }
  vector<ll> m(3);
  for (int j = 0; j < 3; j++) {
    m[j] = l[j];
    if (wasmn < summn) {
      ll canshift = min((unsigned long long) summn - wasmn, (unsigned long long) r[j] - l[j]);
      wasmn += canshift;
      m[j] += canshift;
    }
  }
  for (ll i = max(l[0], m[0]-4); i <= min(r[0], m[0]+4); i++) {
    for (ll j = max(l[1], m[1]-4); j <= min(r[1], m[1]+4); j++) {
      for (ll k = max(l[2], m[2]-4); k <= min(r[2], m[2]+4); k++) {
        ll cursum = i + j + k;
        if (cursum >= summn && cursum <= summx) {
          if (((i ^ j) & 1) || ((i ^ k) & 1)) {
            continue;
          }
          a = i, b = j, c = k;
          return true;
        }
      }
    }
  }
  return false;
}

void solve() {
  ll mn = 0;
  for (int j = 0; j < 3; j++) {
    ll curmn = 3e18, curmx = -3e18;
    for (int i = 0; i < n; i++) {
      curmn = min(curmn, x[i][j]);
      curmx = max(curmx, x[i][j]);
    }
    mn = max(mn, (curmx - curmn + 1) / 2);
  }
  ll curmn = 3e18, curmx = -3e18;
  for (int i = 0; i < n; i++) {
    curmn = min(curmn, sum[i]);
    curmx = max(curmx, sum[i]);
  }
  mn = max(mn, (curmx - curmn + 1) / 2);
  if (!check(mn)) {
    mn += needadd;
    if (!check(mn)) {
      check(mn + 1);
    }
  }
  printf(LLD " " LLD " " LLD "\n", (b + c) / 2, (a + c) / 2, (a + b) / 2);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  int t;
  scanf("%d", &t);
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