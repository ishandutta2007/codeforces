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

const int maxn = (int) 2e5 + 100;
int n, m;
vector<pair<ll, int> > s, t;

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  s.clear(), t.clear();
  for (int i = 0; i < n; i++) {
    int a;
    char b;
    scanf("%d-%c", &a, &b);
    ll sum = 0;
    while (sz(t) && t.back().second == b) {
      sum += t.back().first;
      t.pop_back();
    }
    t.pb(mp(a + sum, (int) b));
  }
  for (int i = 0; i < m; i++) {
    int a;
    char b;
    scanf("%d-%c", &a, &b);
    ll sum = 0;
    while (sz(s) && s.back().second == b) {
      sum += s.back().first;
      s.pop_back();
    }
    s.pb(mp(a + sum, (int) b));
  }
  return true;
}

void solve() {
  if (sz(t) < sz(s)) {
    printf("0\n");
    return;
  }
  int cangood = sz(t) - sz(s) + 1;
  vector<int> bad(cangood);
  int sumlen = sz(t) + sz(s) + 1;
  vector<ll> str(sumlen);
  vector<int> z(sumlen);
  for (int i = 0; i < sz(s); i++) {
    str[i] = s[i].second;
  }
  str[sz(s)] = -10;
  for (int i = 0; i < sz(t); i++) {
    str[i + sz(s) + 1] = t[i].second;
  }
  int mx = 0, mxi = 0;
  for (int i = 1; i < sumlen; i++) {
    z[i] = max(0, min(mx - i + 1, z[i - mxi]));
    while (z[i] + i < sumlen && str[z[i] + i] == str[z[i]]) {
      z[i]++;
    }
    if (z[i] + i - 1 >= mx) {
      mx = z[i] + i - 1;
      mxi = i;
    }
  }
  for (int i = 0; i < cangood; i++) {
    if (z[i + sz(s) + 1] < sz(s)) {
      bad[i] = 1;
    }
  }

  if (sz(s) > 2) {
    sumlen -= 2;
    for (int i = 1; i < sz(s) - 1; i++) {
      str[i - 1] = s[i].first;
    }
    str[sz(s) - 2] = -10;
    for (int i = 0; i < sz(t); i++) {
      str[sz(s) - 1 + i] = t[i].first;
    }
    int mx = 0, mxi = 0;
    for (int i = 1; i < sumlen; i++) {
      z[i] = max(0, min(mx - i + 1, z[i - mxi]));
      while (z[i] + i < sumlen && str[z[i] + i] == str[z[i]]) {
        z[i]++;
      }
      if (z[i] + i - 1 >= mx) {
        mx = z[i] + i - 1;
        mxi = i;
      }
    }
    for (int i = 0; i < cangood; i++) {
      if (z[i + sz(s)] < sz(s) - 2) {
        bad[i] = 1;
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < cangood; i++) {
    if (bad[i]) {
      continue;
    }
    if (t[i].first < s[0].first) {
      continue;
    }
    if (t[i + sz(s) - 1].first < s.back().first) {
      continue;
    }
    if (sz(s) > 1) {
      ans++;
    } else {
      ans += t[i].first - s[0].first + 1;
    }
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