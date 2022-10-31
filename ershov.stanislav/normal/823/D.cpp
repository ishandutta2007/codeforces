#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;

#define sz(a) (int) (a).size()
#define pb push_back

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

struct comp {
  ld x, y;

  comp (ld x = 0, ld y = 0) : x(x), y(y) {}

  comp operator+(const comp & b) const {
    return comp(x + b.x, y + b.y);
  }

  comp operator-(const comp & b) const {
    return comp(x - b.x, y - b.y);
  }

  comp operator*(const comp & b) const {
    return comp(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};

const int maxn = 1 << 20;

comp a[maxn], b[maxn];
comp w[maxn];
int rev[maxn];
int wasn = -1;
int n, logn;

void fft(comp *a) {
  if (n != wasn) {
    wasn = n;
    rev[0] = 0;
    comp tomult;
    w[1] = 1;
    for (int i = 1, j = -1; i < n; i++) {
      if (!(i & (i - 1))) {
        j++;
        tomult = comp(cos(pi / 2 / i), sin(pi / 2 / i));
      }
      rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
      if (i < n / 2) {
        w[i * 2] = w[i];
        w[i * 2 + 1] = w[i] * tomult;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int i0 = 1, pos = 1; i0 < n; i0 <<= 1) {
    for (int i = 0; i < n; i += i0) {
      for (int j = i + i0, it = 0; it < i0; it++, i++, j++) {
        comp toadd = w[it + pos] * a[j];
        a[j] = a[i] - toadd;
        a[i] = a[i] + toadd;
      }
    }
    pos += i0;
  }
}

int n0;
char s[maxn];

bool read() {
  if (scanf("%d%s", &n0, s) < 2) {
    return false;
  }
  return true;
}

int ans[maxn];

void solve() {
  for (n = 1, logn = 0; n < n0 * 2; n <<= 1, logn++) ;

  for (int i = 0; i < n; i++) {
    a[i] = 0;
    b[i] = 0;
    ans[i] = 0;
  }
  for (int i = 0; i < n0; i++) {
    if (s[i] == 'V') {
      a[i] = 1;
    } else if (s[i] == 'K') {
      b[n0 - 1 - i] = 1;
    }
  }
  fft(a);
  fft(b);
  for (int i = 0; i < n; i++) {
    a[i] = a[i] * b[i];
  }
  reverse(a + 1, a + n);
  fft(a);
  for (int i = 0; i < n0; i++) {
    if (abs(a[i + n0 - 1].x / n) > 0.5) {
      ans[i] = 1;
    }
    if (abs(a[n0 - 1 - i].x / n) > 0.5) {
      ans[i] = 1;
    }
  }
  vector<int> v;
  for (int i = 1; i < n0; i++) {
    bool ok = true;
    for (int j = i; j < n0; j += i) {
      if (ans[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      v.pb(i);
    }
  }
  v.pb(n0);
  printf("%d\n", sz(v));
  for (int i = 0; i < sz(v); i++) {
    printf("%d%c", v[i], " \n"[i == sz(v) - 1]);
  }
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}