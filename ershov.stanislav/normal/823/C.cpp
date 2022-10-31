#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;

#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

const int maxn = 111;

int n;
ll k;
ll a[maxn];

bool read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  return true;
}

void solve() {
  vector<pair<ll, ll> > tosort;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll cur = a[i];
    sum += cur;
    ll k = cur;
    tosort.pb(mp(1, k));
    while (k > 1) {
      ll nxt = (cur + k - 2) / (k - 1);
      ll now = (cur + nxt - 1) / nxt;
      tosort.pb(mp(nxt, now - k));
      k = now;
    }
  }
  sort(tosort.begin(), tosort.end());
  ll g = 0;
  ll ans = 1;
  for (int i = 0; i < sz(tosort); ) {
    int i0 = i;
    while (i < sz(tosort) && tosort[i].first == tosort[i0].first) {
      g += tosort[i].second;
      i++;
    }
    ll curres = (k + sum) / g;
    if (i < sz(tosort)) {
      curres = min(curres, tosort[i].first - 1);
    }
    if (curres >= tosort[i0].first) {
      ans = max(ans, curres);
    }
  }
  printf("%lld\n", ans);
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}