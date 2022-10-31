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

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 250;
int n;
ll l;
int a[maxn];
string s[maxn];
int go[maxn][26], suff[maxn], dp[maxn];
int cnt;

bool read() {
  if (scanf("%d%lld", &n, &l) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  memset(go, -1, sizeof(go));
  memset(suff, -1, sizeof(suff));
  memset(dp, 0, sizeof(dp));
  cnt = 1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int cur, j;
    for (cur = 0, j = 0; j < sz(s[i]); j++) {
      int & nxt = go[cur][s[i][j] - 'a'];
      if (nxt == -1) {
        nxt = cnt++;
      }
      cur = nxt;
    }
    dp[cur] += a[i];
  }
  return true;
}

struct matrix {
  ll a[maxn][maxn];

  matrix() {
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        a[i][j] = -1e18;
      }
    }
  }

  matrix operator*(const matrix & b) const {
    matrix ans;
    for (int i = 0; i < maxn; i++) {
      for (int j = 0; j < maxn; j++) {
        for (int k = 0; k < maxn; k++) {
          ans.a[i][j] = max(ans.a[i][j], a[i][k] + b.a[k][j]);
        }
      }
    }
    return ans;
  }
};

matrix power(matrix m, ll p) {
  matrix res;
  for (int i = 0; i < maxn; i++) {
    res.a[i][i] = 0;
  }
  while (p) {
    if (p & 1) {
      res = res * m;
    }
    m = m * m;
    p >>= 1;
  }
  return res;
}

void solve() {
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (go[0][i] != -1) {
      suff[go[0][i]] = 0;
      q.push(go[0][i]);
    } else {
      go[0][i] = 0;
    }
  }
  while (sz(q)) {
    int cur = q.front();
    dp[cur] += dp[suff[cur]];
    //eprintf("%d\n", dp[cur]);
    q.pop();
    for (int i = 0; i < 26; i++) {
      int & to = go[cur][i];
      if (to != -1) {
        suff[to] = go[suff[cur]][i];
        q.push(to);
      } else {
        to = go[suff[cur]][i];
      }
    }
  }
  matrix topower;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < 26; j++) {
      topower.a[i][go[i][j]] = max(topower.a[i][go[i][j]], (ll) dp[go[i][j]]);
    }
  }
  /*for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      eprintf("%lld%c", topower.a[i][j], " \n"[j == cnt - 1]);
    }
  }*/
  topower = power(topower, l);
  /*for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      eprintf("%lld%c", topower.a[i][j], " \n"[j == cnt - 1]);
    }
  }*/
  ll res = 0;
  for (int i = 0; i < cnt; i++) {
    res = max(res, topower.a[0][i]);
  }
  printf("%lld\n", res);
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