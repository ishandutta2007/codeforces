#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

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

struct val {
  int a[4][4];
};

val join(const val & a, const val & b) {
  val res;
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      res.a[i][j] = inf;
      for (int k = i; k <= j; k++) {
        res.a[i][j] = min(res.a[i][j], a.a[i][k] + b.a[k][j]);
      }
    }
  }
  return res;
}

const int maxn = 2e5 + 100;
int n, q;
char s[maxn];
int a[maxn];
int cnt[maxn];
int str[4] = {2, 0, 1, 6};
val tree[maxn * 4];
#define prev mprev
int prev[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  return true;
}

void build(int v, int vl, int vr) {
  if (vl == vr - 1) {
    for (int i = 0; i < 4; i++) {
      for (int j = i; j < 4; j++) {
        tree[v].a[i][j] = inf;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (str[i] == a[vl]) {
        tree[v].a[i][i] = 1;
        tree[v].a[i][i + 1] = 0;
      } else {
        tree[v].a[i][i] = 0;
      }
    }
  } else {
    int mid = (vl + vr) / 2;
    build(v * 2, vl, mid);
    build(v * 2 + 1, mid, vr);
    tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
  }
}

val get(int v, int vl, int vr, int l, int r) {
  if (vr <= l || r <= vl) {
    val res;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        res.a[i][j] = inf;
      }
      res.a[i][i] = 0;
    }
    return res;
  }
  if (l <= vl && vr <= r) {
    return tree[v];
  } else {
    int mid = (vl + vr) / 2;
    return join(get(v * 2, vl, mid, l, r), get(v * 2 + 1, mid, vr, l, r));
  }
}

void solve() {
  build(1, 0, n);
  prev[0] = -inf;
  for (int i = 0; i < n; i++) {
    prev[i + 1] = prev[i];
    if (a[i] == 7) {
      prev[i + 1] = i;
    }
  }
  cnt[0] = 0;
  for (int i = 0; i < n; i++) {
    cnt[i + 1] = cnt[i] + (a[i] == 6);
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int pr = prev[r];
    int toadd = 0;
    if (pr >= 0) {
      toadd = cnt[r] - cnt[pr];
    }
    r = min(r, pr);
    if (r <= l) {
      printf("-1\n");
      continue;
    }
    int res = get(1, 0, n, l, r).a[0][3];
    if (res > inf / 2) {
      printf("-1\n");
    } else {
      printf("%d\n", res + toadd);
    }
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}