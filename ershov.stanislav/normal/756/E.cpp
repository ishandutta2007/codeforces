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

const int mod = 1e9 + 7;

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

const int maxn = 3e5 + 100;
const int maxdp = 1e8;

int n;
int a[maxn];
int b[maxn];
int dp[maxdp];
char m[maxn];

int num[maxn], lennum;
int tmp[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  scanf("%s", m);
  return true;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  int sz = 1;
  dp[0] = 1;
  {
    int l = strlen(m);
    lennum = 0;
    for (int i = l - 9; ; i = i - 9) {
      num[lennum] = 0;
      for (int j = max(i, 0); j < i + 9 && j < l; j++) {
        num[lennum] *= 10;
        num[lennum] += m[j] - '0';
      }
      lennum++;
      if (i <= 0) {
        break;
      }
    }
    while (lennum && num[lennum - 1] == 0) {
      lennum--;
    }
  }
  for (int it = 0; it < n; it++) {
    for (int i = sz; i < sz + b[it]; i++) {
      dp[i] = 0;
    }
    for (int i = sz - 1; i >= 0; i--) {
      add(dp[i + b[it] + 1], mod - dp[i]);
    }
    sz += b[it];
    for (int i = 1; i < sz; i++) {
      add(dp[i], dp[i - 1]);
    }
    if (it < n - 1 && a[it] != 1) {
      int r = 0;
      for (int i = lennum - 1; i >= 0; i--) {
        r = ((ll) r * (ll) 1e9 + num[i]) % a[it];
      }
      int nsz = 0;
      for (int i = r; i < sz; i += a[it]) {
        dp[nsz++] = dp[i];
      }
      if (nsz == 0) {
        printf("0\n");
        return;
      }
      sz = nsz;
      {
        int nlennum = 0;
        ll cur = 0;
        for (int i = lennum - 1; i >= 0; i--) {
          cur = cur * (ll) 1e9;
          cur = cur + num[i];
          tmp[i] = cur / a[it];
          if (tmp[i] && !nlennum) {
            nlennum = i + 1;
          }
          cur = cur % a[it];
        }
        lennum = nlennum;
        for (int i = 0; i < lennum; i++) {
          num[i] = tmp[i];
        }
        if (lennum == 0) {
          printf("%d\n", dp[0]);
          return;
        }
      }
    }
  }
  if (lennum > 1) {
    printf("0\n");
    return;
  }
  if (num[0] >= sz) {
    printf("0\n");
    return;
  }
  printf("%d\n", dp[num[0]]);
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