#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

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

const int mod = 998244353;
const int maxn = 300;

void add(int & a, int b) {
  if ((a += b) >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int power(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, a);
    }
    a = mult(a, a);
    p >>= 1;
  }
  return res;
}

int inv(int a) {
  return power(a, mod - 2);
}

int fact[maxn];
int invfact[maxn];
int dp1[maxn][maxn];
int bin[maxn][maxn];
int A[maxn][maxn];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  for (int i = 0; i < maxn; i++) {
    invfact[i] = inv(fact[i]);
  }
  bin[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    bin[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      bin[i][j] = bin[i - 1][j - 1];
      add(bin[i][j], bin[i - 1][j]);
    }
  }
  dp1[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    for (int k = 1; k <= i; k++) {
      for (int len = 1; len <= i; len++) {
        add(dp1[i][k], mult(dp1[i - len][k - 1], mult(bin[i - 1][len - 1], fact[len - 1])));
      }
    }
  }
}

int n;
vector<int> p, q;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  p = q = vector<int> (n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
    q[i]--;
  }
  return true;
}

vector<int> makegood(vector<int> & p) {
  set<int> s;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) {
      s.erase(p[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (p[i] == -1) {
      auto cur = s.begin();
      p[i] = *cur;
      s.erase(cur);
      ans.pb(i);
    }
  }
  return ans;
}

#define rank mrank
int pr[maxn], rank[maxn];

int getpar(int v) {
  if (pr[v] == v) {
    return v;
  } else {
    return pr[v] = getpar(pr[v]);
  }
}

void myUnion(int v, int u) {
  v = getpar(v);
  u = getpar(u);
  if (v == u) {
    return;
  }
  if (rank[v] == rank[u]) {
    rank[v]++;
  }
  if (rank[v] < rank[u]) {
    swap(v, u);
  }
  pr[u] = v;
}

int dp2[maxn][maxn];

void solve() {
  vector<int> change1, change2;
  change1 = makegood(p);
  change2 = makegood(q);
#ifdef DEBUG
  vector<int> ans2(n + 1);
  {
    vector<int> inp;
    for (auto i : change1) {
      inp.pb(p[i]);
    }
    sort(inp.begin(), inp.end());
    vector<int> bad(n);
    for (auto i : change2) {
      bad[i] = 1;
    }
    do {
        for (int i = 0; i < sz(change1); i++) {
          p[change1[i]] = inp[i];
        }
        vector<int> prod(n);
        vector<int> invq(n);
        for (int i = 0; i < n; i++) {
          invq[q[i]] = i;
        }
        for (int i = 0; i < n; i++) {
          prod[i] = invq[p[i]];
        }

        for (int i = 0; i < n; i++) {
          pr[i] = i;
          rank[i] = 0;
        }
        for (int i = 0; i < n; i++) {
          if (!bad[prod[i]]) {
            myUnion(i, prod[i]);
          }
        }
        int cnt = 0;
        int cycles = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
          if (bad[i]) {
            v[getpar(i)] = 1;
          }
        }
        for (int i = 0; i < n; i++) {
          if (pr[i] == i) {
            if (v[i]) {
              cnt++;
            } else {
              cycles++;
            }
          }
        }
        for (int i = 0; i <= cnt; i++) {
          add(ans2[cycles + i], dp1[cnt][i]);
        }
    } while (next_permutation(inp.begin(), inp.end()));
  }
#endif
  vector<int> invq(n);
  for (int i = 0; i < n; i++) {
    invq[q[i]] = i;
  }
  vector<int> prod(n);
  vector<int> invprod(n);
  for (int i = 0; i < n; i++) {
    prod[i] = invq[p[i]];
  }
  for (int i = 0; i < n; i++) {
    invprod[prod[i]] = i;
  }
  for (auto & i : change1) {
    i = prod[i];
  }
  vector<int> type(n);
  for (auto i : change1) {
    type[i] ^= 1;
  }
  for (auto i : change2) {
    type[i] ^= 2;
  }
  for (int i = 0; i < n; i++) {
    pr[i] = i;
    rank[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (!type[prod[i]]) {
      myUnion(i, prod[i]);
    }
  }
  int cnt = 0;
  vector<int> cid(n);
  for (int i = 0; i < n; i++) {
    if (pr[i] == i) {
      cid[i] = cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    cid[i] = cid[getpar(i)];
  }
  vector<int> ctype(cnt);
  for (int i = 0; i < n; i++) {
    ctype[cid[i]] |= type[i];
  }
  vector<int> out(cnt);
  for (auto i : change1) {
    out[cid[invprod[i]]] = 1;
  }
  ld tomult = 1;
  vector<int> ans(n + 1);
  {
    int a = sz(change1);
    int b = 0, c = 0;
    int all = 0;
    int cycles = 0;
    for (int i = 0; i < cnt; i++) {
      if (ctype[i] == 1) {
        if (out[i]) {
          b++;
        } else {
          c++;
        }
      }
      if (ctype[i]) {
        all++;
      } else {
        cycles++;
      }
    }
    //eprintf("%d %d %d %d %d\n", a, b, c, all, cycles);
    tomult = fact[a - b - c];
    tomult = mult(tomult, mult(bin[a - b][c], fact[c]));
    memset(dp2, 0, sizeof(dp2));
    dp2[0][0] = 1;
    for (int i = 1; i <= b; i++) {
      dp2[i][0] = mult(bin[a - b + i][i], fact[i]);
      for (int j = 1; j <= i; j++) {
        for (int k = j; k <= i; k++) {
          int cur = mult(bin[i][k], dp1[k][j]);
          cur = mult(cur, dp2[i - k][0]);
          //eprintf("%d %d %d\n", j, k, cur);
          add(dp2[i][j], cur);
          add(dp2[i][0], mod - cur);
        }
      }
    }
    for (int badcycles = 0; badcycles <= b; badcycles++) {
      int cur = dp2[b][badcycles];
      int remains = all - b - c;
      for (int i = 0; i <= remains; i++) {
        add(ans[cycles + badcycles + i], mult(dp1[remains][i], cur));
      }
    }
    for (int i = 1; i <= n; i++) {
      ans[i] = mult(ans[i], tomult);
    }
  }
#ifdef DEBUG
  eprintf("correct: \n");
  for (int i = 0; i <= n; i++) {
    eprintf("%d%c", ans2[i], " \n"[i == n]);
  }
  eprintf("wrong: \n");
  for (int i = 0; i <= n; i++) {
    eprintf("%d%c", ans[i], " \n"[i == n]);
  }
  for (int i = 0; i <= n; i++) {
    assert(ans[i] == ans2[i]);
  }
#endif
  for (int k = 0; k < n; k++) {
    printf("%d%c", ans[n - k], " \n"[k == n - 1]);
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