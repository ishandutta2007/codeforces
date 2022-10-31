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

const int maxn = (int) 1e5 + 100;
int n;
pair<int, int> p[maxn];
int premx[maxn], premn[maxn], sufmx[maxn], sufmn[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  return true;
}

ll sqr(ll a) {
  return a * a;
}

ll getans(int l, int r) {
  ll ans = sqr(p[r - 1].first - p[l].first);
  int mx = max(premx[l], sufmx[r]);
  int mn = min(premn[l], sufmn[r]);
  ans = max(ans, sqr(mx - mn));
  ans = max(ans, max(sqr(mx), sqr(mn)) + max(sqr(p[r - 1].first), sqr(p[l].first)));
  return ans;
}

void solve() {
  ll ans = 1e18;
  {
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; i++) {
      mn = min(mn, p[i].first);
      mx = max(mx, p[i].first);
    }
    ans = min(ans, sqr(mx - mn));
  }
  {
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; i++) {
      mn = min(mn, p[i].second);
      mx = max(mx, p[i].second);
    }
    ans = min(ans, sqr(mx - mn));
  }
  for (int it = 0; it < 2; it++) {
    sort(p, p + n);
    premx[0] = -INF;
    premn[0] = INF;
    for (int i = 0; i < n; i++) {
      premx[i + 1] = max(premx[i], p[i].second);
      premn[i + 1] = min(premn[i], p[i].second);
    }
    sufmx[n] = -INF;
    sufmn[n] = INF;
    for (int i = n - 1; i >= 0; i--) {
      sufmx[i] = max(sufmx[i + 1], p[i].second);
      sufmn[i] = min(sufmn[i + 1], p[i].second);
    }
    vector<int> xs;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (i && p[i - 1].first == p[i].first) {
        continue;
      }
      xs.pb(p[i].first);
      pos.pb(i);
    }
    pos.pb(n);
    for (int i = 0; i < sz(xs); i++) {
      int cur = xs[i];
      if (cur > 0) {
        break;
      }
      int j = (int) (upper_bound(xs.begin(), xs.end(), -cur) - xs.begin());
      int l = 1, r = j - i;
      while (l < r) {
        int mid = (l + r) / 2;
        ll ans1 = getans(pos[i], pos[i + mid]);
        ll ans2 = getans(pos[i], pos[i + mid + 1]);
        if (ans1 < ans2) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      ans = min(ans, getans(pos[i], pos[i + l]));
    }
    for (int i = 0; i < n; i++) {
      p[i].first *= -1;
    }
  }
  /*ll ans2 = 1e18;
    vector<pair<int, int> > cur;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cur.pb(mp(0, p[i].second));
      } else {
        cur.pb(mp(p[i].first, 0));
      }
    }
    ll curans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        curans = max(curans, sqr(cur[i].first - cur[j].first) + sqr(cur[i].second - cur[j].second));
      }
    }
    ans2 = min(ans2, curans);
  }
  assert(ans == ans2);
  eprintf(LLD "\n", ans);*/
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