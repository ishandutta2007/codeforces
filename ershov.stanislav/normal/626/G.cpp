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

struct Ratio {
  ll a, b;
  
  Ratio(ll a = 0, ll b = 1) : a(a), b(b) { }

  Ratio operator*(const Ratio & y) const {
    return Ratio(a * y.a, b * y.b);
  }
  
  Ratio operator+(const Ratio & y) const {
    return Ratio(a * y.b + y.a * b, b * y.b);
  }

  Ratio operator-() const {
    return Ratio(-a, b);
  }

  Ratio operator-(const Ratio & y) const {
    return Ratio(a * y.b - y.a * b, b * y.b);
  }

  bool operator<(const Ratio & y) const {
    return a * y.b < y.a * b;
  }
};

bool operator>(const Ratio & x, const Ratio & y) {
  return y < x;
}

const Ratio smallest = Ratio(-1e6, 1);

struct Tree {
  static const int maxn = 1 << 19;
  pair<Ratio, int> a[maxn];
  int n;

  void build(int n1) {
    for (n = 1; n < n1; n <<= 1);

    for (int i = n; i < 2 * n; i++) {
      a[i] = mp(smallest, i - n);
    }
    for (int i = n - 1; i > 0; i--) {
      a[i] = max(a[i * 2], a[i * 2 + 1]);
    }
  }

  void set(int i, Ratio val) {
    a[i + n] = mp(val, i);
    for (int j = (i + n) >> 1; j > 0; j >>= 1) {
      a[j] = max(a[j * 2], a[j * 2 + 1]);
    }
  }

  Ratio get(int i) {
    return a[i + n].first;
  }

  pair<Ratio, int> get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
      return mp(Ratio(smallest), -1);
    } else if (l <= vl && vr <= r) {
      return a[v];
    } else {
      int mid = (vl + vr) / 2;
      return max(get(v * 2, vl, mid, l, r), get(v * 2 + 1, mid, vr, l, r));
    }
  }

  pair<Ratio, int> get(int l, int r) {
    return get(1, 0, n, l, r);
  }

  pair<Ratio, int> getall() {
    return a[1];
  }
} take, put;

const int maxn = (int) 2e5 + 100;
int n, t, q;
int p[maxn], l[maxn], m[maxn];
int used;
ld curans;

bool read() {
  if (scanf("%d%d%d", &n, &t, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", l + i);
  }
  return true;
}

void upd(int i) {
  if (m[i] == 0) {
    take.set(i, smallest);
  } else {
    take.set(i, Ratio(p[i]) * (Ratio(m[i] - 1, m[i] - 1 + l[i]) - Ratio(m[i], m[i] + l[i])));
  }
  if (m[i] >= l[i]) {
    put.set(i, smallest);
  } else {
    put.set(i, Ratio(p[i]) * (Ratio(m[i] + 1, m[i] + 1 + l[i]) - Ratio(m[i], m[i] + l[i])));
  }
}

bool doput() {
  if (used >= t) {
    return false;
  }
  pair<Ratio, int> toput = put.getall();
  if (toput.first > smallest) {
    m[toput.second]++;
    curans += (ld) toput.first.a / toput.first.b;
    upd(toput.second);
    used++;
    return true;
  }
  return false;
}

void trychange() {
  while (true) {
    pair<Ratio, int> totake = take.getall(), toput = put.getall();
    if (-totake.first < toput.first) {
      assert(totake.second != toput.second);
      m[totake.second]--;
      m[toput.second]++;
      curans += (ld) toput.first.a / toput.first.b;
      curans += (ld) totake.first.a/ totake.first.b;
      upd(totake.second);
      upd(toput.second);
    } else {
      break;
    }
  }
}

void solve() {
  take.build(n), put.build(n);
  for (int i = 0; i < n; i++) {
    m[i] = 0;
    upd(i);
  }
  used = 0;
  curans = 0;
  while (true) {
    if (!doput()) {
      break;
    }
  }
  for (int i = 0; i < q; i++) {
    int t, r;
    scanf("%d %d", &t, &r);
    r--;
    if (t == 1) {
      curans -= p[r] * ((ld) m[r] / (m[r] + l[r]));
      l[r]++;
      curans += p[r] * ((ld) m[r] / (m[r] + l[r]));
      upd(r);
      doput();
      trychange();
    } else {
      curans -= p[r] * ((ld) m[r] / (m[r] + l[r]));
      l[r]--;
      curans += p[r] * ((ld) m[r] / (m[r] + l[r]));
      upd(r);
      while (m[r] > l[r]) {
        Ratio cur = take.get(r);
        curans += (ld) cur.a / cur.b;
        m[r]--;
        upd(r);
        used--;
      }
      while (true) {
        if (!doput()) {
          break;
        }
      }
      trychange();
    }
    printf("%.18f\n", (double) curans);
  }
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