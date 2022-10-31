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

const int maxn = 30030;
const int maxk = 1010;
int n, k;
ll st[100][maxk], last;
int t[maxn];
int from[maxn], to[maxn];
int v[maxn], w[maxn];
int cntall;
int q;

vector<int> tree[1 << 16];

void adddp(int v, int w) {
  for (int i = k; i >= w; i--) {
    st[last][i] = max(st[last][i], st[last][i - w] + v);
  }
}

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  last = 0;
  for (int i = 0; i <= k; i++) {
    st[last][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", v + i, w + i);
    from[i] = 0;
    to[i] = 1e6;
  }
  cntall = n;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", t + i);
    if (t[i] == 1) {
      scanf("%d%d", v + cntall, w + cntall);
      from[cntall] = i;
      to[cntall] = 1e6;
      cntall++;
    } else if (t[i] == 2) {
      int cur;
      scanf("%d", &cur);
      cur--;
      to[cur] = i;
    }
  }

  return true;
}

void pushtree(int v, int vl, int vr, int l, int r, int i) {
  if (vl >= r || vr <= l) {
    return;
  }
  if (l <= vl && vr <= r) {
    tree[v].pb(i);
  } else {
    int mid = (vl + vr) / 2;
    pushtree(v * 2, vl, mid, l, r, i);
    pushtree(v * 2 + 1, mid, vr, l, r, i);
  }
}

int ans[maxn];

const int MOD = (int) 1e9 + 7;

void add(int & a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

void solve(int v, int vl, int vr) {
  last++;
  for (int i = 0; i <= k; i++) {
    st[last][i] = st[last - 1][i];
  }
  for (auto i : tree[v]) {
    adddp(::v[i], w[i]);
  }
  if (vl == vr - 1) {
    if (t[vl] == 3) {
      ans[vl] = 0;
      for (int i = k; i >= 1; i--) {
        //eprintf("%d%c", st[last][i], " \n"[i == 1]);
        ans[vl] = mult(ans[vl], (int) 1e7 + 19);
        add(ans[vl], st[last][i] % MOD);
      }
    }
  } else {
    int mid = (vl + vr) / 2;
    solve(v * 2, vl, mid);
    solve(v * 2 + 1, mid, vr);
  }
  last--;
}

void solve() {
  for (int i = 0; i < (1 << 16); i++) {
    tree[i].clear();
  }
  for (int i = 0; i < cntall; i++) {
    pushtree(1, 0, q, from[i], to[i], i);
  }
  solve(1, 0, q);
  for (int i = 0; i < q; i++) {
    if (t[i] == 3) {
      printf("%d\n", ans[i]);
    }
  }
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