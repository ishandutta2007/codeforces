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

const ll inf = (ll) 1e18 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

vector<ll> bad;

void precalc() {
  for (ll cur = 1; cur < inf; cur *= 42) {
    bad.pb(cur);
    if (cur > inf / 42 + 1) {
      break;
    }
  }
  //eprintf("%d\n", sz(bad));
}

struct T {
  ll toadd, equal;
  pair<ll, int> mx;

  T (pair<ll, int> mx = mp(0, 0)) : toadd(0), equal(0), mx(mx) { }

  void add(ll val) {
    toadd += val;
    mx.first += val;
  }

  void makeequal(ll val) {
    mx.first = equal = val;
    toadd = 0;
  }
};

struct SegmTree {
  const static int maxn = 1 << 18;
  T a[maxn];
  int n;

  void build(int _n, ll * vals) {
    for (n = 1; n < _n; n <<= 1);
    for (int i = 0; i < n; i++) {
      a[i + n] = (i < _n) ? T(mp(vals[i], i)) : T(mp(-inf, i));
    }
    for (int i = n - 1; i > 0; i--) {
      a[i] = T(max(a[i * 2].mx, a[i * 2 + 1].mx));
    }
  }

  void push(int v) {
    if (a[v].equal) {
      for (int it = 0; it < 2; it++) {
        a[v * 2 + it].makeequal(a[v].equal);
      }
      a[v].equal = 0;
    }
    if (a[v].toadd) {
      for (int it = 0; it < 2; it++) {
        a[v * 2 + it].add(a[v].toadd);
      }
      a[v].toadd = 0;
    }
  }

  pair<ll, int> getmx() {
    return a[1].mx;
  }

  void add(int v, int vl, int vr, int l, int r, ll val) {
    if (r <= vl || vr <= l) {
      return;
    }
    if (l <= vl && vr <= r) {
      a[v].add(val);
    } else {
      push(v);
      int mid = (vl + vr) / 2;
      add(v * 2, vl, mid, l, r, val);
      add(v * 2 + 1, mid, vr, l, r, val);
      a[v].mx = max(a[v * 2].mx, a[v * 2 + 1].mx);
    }
  }

  void makeequal(int v, int vl, int vr, int l, int r, ll val) {
    if (r <= vl || vr <= l) {
      return;
    }
    if (l <= vl && vr <= r) {
      a[v].makeequal(val);
    } else {
      push(v);
      int mid = (vl + vr) / 2;
      makeequal(v * 2, vl, mid, l, r, val);
      makeequal(v * 2 + 1, mid, vr, l, r, val);
      a[v].mx = max(a[v * 2].mx, a[v * 2 + 1].mx);
    }
  }

  ll getval(int i) {
    int vl = 0, vr = n;
    int v = 1;
    while (vl < vr - 1) {
      push(v);
      int mid = (vl + vr) / 2;
      if (mid > i) {
        vr = mid;
        v = v * 2;
      } else {
        vl = mid;
        v = v * 2 + 1;
      }
    }
    return a[v].mx.first;
  }

  void add(int l, int r, ll val) {
    add(1, 0, n, l, r, val);
  }

  void makeequal(int l, int r, ll val) {
    makeequal(1, 0, n, l, r, val);
  }
} tree[2];

const int maxn = 1e5 + 100;
int n, q;
ll t[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", t + i);
  }
  return true;
}

ll magic(ll a) {
  int j = 0;
  while (bad[j] < a) {
    j++;
  }
  return a - bad[j];
}

void solve() {
  set<int> starts;
  for (int i = 0; i <= n; i++) {
    starts.insert(i);
  }
  for (int i = 0; i < 2; i++) {
    tree[i].build(n, t);
    if (!i) {
      for (int j = 0; j < n; j++) {
        t[j] = magic(t[j]);
      }
    }
  }
  for (int t = 0; t < q; t++) {
    int curt;
    scanf("%d", &curt);
    if (curt == 1) {
      int i;
      scanf("%d", &i);
      i--;
      printf("%lld\n", tree[0].getval(i));
    } else {
      int a, b;
      ll x;
      scanf("%d%d%lld", &a, &b, &x);
      a--;
      starts.insert(a);
      starts.insert(b);
      if (curt == 2) {
        for (int i = 0; i < 2; i++) {
          tree[i].makeequal(a, b, x);
          if (!i) {
            x = magic(x);
          }
        }
        auto it = starts.upper_bound(a);
        while (it != starts.end() && *it < b) {
          starts.erase(it++);
        }
      } else {
        while (true) {
          bool tocontinue = false;
          for (int i = 0; i < 2; i++) {
            tree[i].add(a, b, x);
            if (i) {
              while (true) {
                pair<ll, int> curmx = tree[i].getmx();
                if (curmx.first == 0) {
                  tocontinue = true;
                }
                if (curmx.first <= 0) {
                  break;
                }
                //eprintf("%lld %d %d\n", curmx.first, curmx.second, t);
                auto it = starts.upper_bound(curmx.second);
                int r = *it;
                int l = *(--it);
                ll nval = magic(tree[0].getval(curmx.second));
                //eprintf("%d %d\n", l, r);
                //eprintf("%lld\n", tree[0].getval(curmx.second));
                tree[i].makeequal(l, r, nval);
              }
            }
          }
          if (!tocontinue) {
            break;
          }
        }
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