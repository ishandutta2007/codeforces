#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

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

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

namespace FFT {
  const int maxn = 1 << 18;
  ld a[maxn], b[maxn], c[maxn], d[maxn];
  int rev[maxn];
  int n, logn;

  void init() {
    rev[0] = 0;
    for (int i = 1, j = -1; i < n; i++) {
      if (!(i & (i - 1))) {
        j++;
      }
      rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
    }
  }

  void fft(ld * a, ld * b, bool back = false) {
    for (int i = 0; i < n; i++) {
      if (rev[i] < i) {
        swap(a[i], a[rev[i]]);
        swap(b[i], b[rev[i]]);
      }
    }
    for (int j0 = 1; j0 < n; j0 <<= 1) {
      ld multa = cos(PI / j0), multb = sin(PI / j0);
      if (back) {
        multb = -multb;
      }
      for (int i = 0; i < n; i += j0) {
        ld cura = 1, curb = 0;
        for (int it = 0, j = i + j0; it < j0; i++, j++, it++) {
          ld adda = cura * a[j] - curb * b[j], addb = cura * b[j] + curb * a[j];
          a[j] = a[i] - adda, b[j] = b[i] - addb;
          a[i] += adda, b[i] += addb;

          ld ncura = cura * multa - curb * multb;
          curb = cura * multb + curb * multa;
          cura = ncura;
        }
      }
    }
  }

  void mult(int n1, ld * a1, int n2, ld * a2) {
    for (n = 1, logn = 0; n < n1 + n2 - 1; n <<= 1, logn++) ;
    init();
    for (int i = 0; i < n; i++) {
      a[i] = (i < n1) ? a1[i] : 0;
      c[i] = (i < n2) ? a2[i] : 0;
      b[i] = d[i] = 0;
    }
    /*for (int i = 0; i < n; i++) {
      eprintf("%.18f%c", (double) a[i], " \n" [i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
      eprintf("%.18f%c", (double) c[i], " \n" [i == n - 1]);
    }*/
    fft(a, b);
    /*for (int i = 0; i < n; i++) {
      eprintf("%.18f%c", (double) a[i], " \n" [i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
      eprintf("%.18f%c", (double) b[i], " \n" [i == n - 1]);
    }*/
    fft(c, d);
    for (int i = 0; i < n; i++) {
      ld na = a[i] * c[i] - b[i] * d[i];
      ld nb = a[i] * d[i] + b[i] * c[i];
      a[i] = na;
      b[i] = nb;
    }
    fft(a, b, true);
    for (int i = 0; i < n; i++) {
      a[i] /= n;
    }
    /*for (int i = 0; i < n; i++) {
      eprintf("%.18f%c", (double) a[i], " \n" [i == n - 1]);
    }*/
  }
}

const int maxn = 5e4;
const int maxm = 110;

int n, m, t, x;
vector<vector<int> > graph;
vector<vector<int> > eid;
ld p[maxm][maxn];
int a[maxm], b[maxm], c[maxm];
ld valv[maxm][maxn];
ld vale[maxm][maxn];
int ptrs[maxm], tomove[maxm], cntptrs;

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &t, &x) < 4) {
    return false;
  }
  eid = graph = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", a + i, b + i, c + i);
    a[i]--, b[i]--;
    graph[a[i]].pb(b[i]);
    eid[a[i]].pb(i);
    memset(p[i], 0, sizeof(p[i]));
    for (int k = 1; k <= t; k++) {
      double tmp;
      scanf("%lf", &tmp);
      p[i][k] = tmp / 100000;
    }
  }
  return true;
}

void first() {
  vector<ld> vals(n, 1e18);
  vector<int> used(n);
  used[n - 1] = 1, vals[n - 1] = 0;
  for (int it = 0; it < n - 1; it++) {
    ld mn = 1e18;
    int mni = -1;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      ld curval = 1e18;
      for (int j = 0; j < sz(graph[i]); j++) {
        curval = min(curval, c[eid[i][j]] + vals[graph[i][j]]);
      }
      if (curval < mn) {
        mn = curval;
        mni = i;
      }
    }
    assert(mni != -1);
    vals[mni] = mn;
    used[mni] = 1;
  }
  /*for (int i = 0; i < n; i++) {
    eprintf("%.18f%c", (double) vals[i], " \n" [i == n - 1]);
  }*/
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < t; j++) {
      valv[i][j] = vals[i] + x;
    }
  }
  valv[n - 1][t - 1] = 0;
}

void second(int l, int r) {
  //eprintf("l = %d r = %d\n", l, r);
  if (l == r - 1) {
    //eprintf("l = %d\n", l);
    for (int i = 0; i < n - 1; i++) {
      ld mn = 1e18;
      //eprintf("i = %d\n", i);
      for (int j = 0; j < sz(graph[i]); j++) {
        int e = eid[i][j];
        ld curval = c[e];
        for (int k = 0; k < cntptrs; k++) {
          curval += vale[e][l + tomove[k] + ptrs[k]];
        }
        mn = min(curval, mn);
        //eprintf("%.18f\n", (double) curval);
      }
      //eprintf("%.18f\n", (double) mn);
      valv[i][l] = mn;
    }
    valv[n - 1][l] = 0;
  } else {
    int mid = (l + r) / 2;
    if (mid > t) {
      second(l, mid);
    }
    int curptr = cntptrs++;
    tomove[curptr] = -mid;
    ptrs[curptr + 1] = ptrs[curptr] + r - mid;
    for (int i = 0; i < m; i++) {
      FFT::mult(mid - l, valv[b[i]] + l, r - l, p[i]);
      for (int j = mid; j < r; j++) {
        vale[i][j + tomove[curptr] + ptrs[curptr]] = FFT::a[j - l];
      }
    }
    second(mid, r);
    cntptrs--;
  }
}

void solve() {
  memset(valv, 0, sizeof(valv));
  memset(vale, 0, sizeof(vale));
  first();
  second(0, 2 * t);
  printf("%.18f\n", (double) valv[0][2 * t - 1]);
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