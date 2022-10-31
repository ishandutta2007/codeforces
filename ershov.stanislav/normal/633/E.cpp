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

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

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

const int maxn = 1e6 + 100;
int n, k;
int v[maxn], c[maxn];
int mn[21][maxn], mx[21][maxn];
int mxpow[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  return true;
}

int getmx(int l, int r) {
  int pw = mxpow[r - l];
  return max(mx[pw][l], mx[pw][r - (1 << pw)]);
}

int getmn(int l, int r) {
  int pw = mxpow[r - l];
  return min(mn[pw][l], mn[pw][r - (1 << pw)]);
}

void solve() {
  for (int i = 1, j = -1; i < maxn; i++) {
    if (!(i & (i - 1))) {
      j++;
    }
    mxpow[i] = j;
  }
  for (int i = 0; i < n; i++) {
    mx[0][i] = v[i];
    mn[0][i] = c[i];
  }
  for (int j = 1; j < 21; j++) {
    for (int i = 0; (i + (1 << (j - 1))) < n; i++) {
      mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
      mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
    }
  }
  vector<int> p(n);
  for (int i = n - 1, j = n; i >= 0; i--) {
    while (j > i + 1) {
      int curmx1 = getmx(i, j) * 100, curmn1 = getmn(i, j);
      int curmx2 = getmx(i, j - 1) * 100, curmn2 = getmn(i, j - 1);
      if (curmx2 >= curmn2) {
        j--;
        continue;
      }
      if (min(curmx1, curmn1) < min(curmx2, curmn2)) {
        j--;
        continue;
      }
      break;
    }
    p[i] = min(getmx(i, j) * 100, getmn(i, j));
  }
  /*for (int i = 0; i < n; i++) {
    eprintf("%d%c", p[i], " \n" [i == n - 1]);
  }*/
  ld ans = 0;
  sort(p.begin(), p.end());
  ld cur = (ld) k / n;
  for (int i = 0; i < n - k + 1; i++) {
    ans += cur * p[i];
    //eprintf("%.18f\n", (double) cur);
    cur *= (ld) (n - i - k) / (n - 1 - i); 
  }
  printf("%.18f\n", (double) ans);
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}