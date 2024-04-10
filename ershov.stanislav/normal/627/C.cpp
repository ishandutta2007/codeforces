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

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 5e5;
int d, n, m;
pair<int, int> xp[maxn];

bool read() {
  if (scanf("%d%d%d", &d, &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &xp[i].first, &xp[i].second);
  }
  return true;
}

void solve() {
  sort(xp, xp + m);
  if (xp[0].first > n) {
    printf("-1\n");
    return;
  }
  vector<pair<int, pair<int, int> > > events;
  events.eb(0, mp(1, 0));
  events.eb(n, mp(-1, 0));
  for (int i = 0; i < m; i++) {
    int nxt = (i < m - 1) ? xp[i + 1].first : d;
    int l = xp[i].first, r = xp[i].first + n;
    if (nxt > r) {
      printf("-1\n");
      return;
    }
    events.eb(l, mp(1, xp[i].second));
    events.eb(r, mp(-1, xp[i].second));
  }
  ll ans = 0;
  sort(events.begin(), events.end());
  /*for (int i = 0; i < sz(events); i++) {
    eprintf("%d %d %d\n", events[i].first, events[i].second.first, events[i].second.second);
  }*/
  multiset<int> curmn;
  for (int i = 0, last = 0; i < sz(events); i++) {
    if (events[i].second.first == 1) {
      curmn.insert(events[i].second.second);
    } else {
      curmn.erase(curmn.lower_bound(events[i].second.second));
    }
    if ((i < sz(events) - 1 && events[i + 1].first > events[i].first) || i == sz(events) - 1) {
      int nlast = min(d, (i < sz(events) - 1) ? events[i + 1].first : d);
      ans += (ll) (nlast - last) * (*(curmn.begin()));
      //eprintf("%d %d\n", (nlast - last), *curmn.begin());
      last = nlast;
    }
  }
  printf(LLD "\n", ans);
}

int main() {
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