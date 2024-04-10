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

const int maxn = 5e5;
int n, k, a, b, q;
int fenwa[maxn], fenwb[maxn];
int arr[maxn];

int get(int * fenw, int i) {
  int ans = 0;
  for (; i > 0; i -= (i & (-i))) {
    ans += fenw[i];
  }
  return ans;
}

int add(int * fenw, int i, int val) {
  for (; i < maxn; i += (i & (-i))) {
    fenw[i] += val;
  }
}

bool read() {
  if (scanf("%d%d%d%d%d", &n, &k, &a, &b, &q) < 1) {
    return false;
  }
  return true;
}

void solve() {
  memset(fenwa, 0, sizeof(fenwa));
  memset(fenwb, 0, sizeof(fenwb));
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int di, ai;
      scanf("%d%d", &di, &ai);
      int was = arr[di];
      arr[di] += ai;
      add(fenwa, di, min(arr[di], a) - min(was, a));
      add(fenwb, di, min(arr[di], b) - min(was, b));
    } else {
      int pi;
      scanf("%d", &pi);
      int ans = get(fenwa, n) - get(fenwa, pi + k - 1) + get(fenwb, pi - 1);
      printf("%d\n", ans);
    }
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