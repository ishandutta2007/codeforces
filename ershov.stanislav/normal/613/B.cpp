#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

const int maxn = 5e5;
int n, A;
int cf, cm;
int a[maxn];
ll m;

bool read() {
  if (scanf("%d%d%d%d" LLD, &n, &A, &cf, &cm, &m) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  ll mx = -1;
  ll mxi = n;
  ll mxj = 0;
  int mxmn = 0;
  vector<pair<int, int> > tosort;
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; i++) {
    tosort.eb(a[i], i);
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + tosort[i].first;
  }
  ll cur = 0;
  for (int i = n; i >= 0; i--) {
    ll left = m - cur;
    if (left < 0) {
      break;
    }
    int l = 0, r = A;
    while (r > l + 1) {
      int mid = (l + r) / 2;
      int j = (int) (lower_bound(tosort.begin(), tosort.end(), mp(mid, 0)) - tosort.begin());
      j = min(j, i);
      ll cur2 = (ll) mid * j - sum[j];
      if (cur2 <= left) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (i == 0) {
      l = A;
    }
    ll nmx = (ll) l * cm + (ll) (n - i) * cf;
    if (nmx > mx) {
      mx = nmx;
      mxi = i;

      int j = (int) (lower_bound(tosort.begin(), tosort.end(), mp(l, 0)) - tosort.begin());
      j = min(j, i);
      mxj = j;
      mxmn = l;
    }
    if (i) {
      cur += A - tosort[i - 1].first;
    }
  }
  vector<int> where(n);
  for (int i = 0; i < n; i++) {
    where[tosort[i].second] = i;
  }
  printf(LLD "\n", mx);
  for (int i = 0; i < n; i++) {
    int ii = where[i];
    if (ii < mxj) {
      printf("%d", (int) mxmn);
    } else if (ii >= mxi) {
      printf("%d", A);
    } else {
      printf("%d", a[i]);
    }
    if (i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  srand(rdtsc());
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