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

const int maxn = 5500;
int n, m, k;
vector<pair<int, int> > rows[maxn], cols[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 1) {
    return false;
  }
  for (int i = 0; i < maxn; i++) {
    rows[i].clear();
    rows[i].eb(-1, 0);
    cols[i].clear();
    cols[i].eb(-1, 0);
  }
  for (int i = 0; i < k; i++) {
    int t, j, a;
    scanf("%d%d%d", &t, &j, &a);
    if (t == 1) {
      rows[j - 1].eb(i, a);
    } else {
      cols[j - 1].eb(i, a);
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int res;
      if (rows[i].back().first > cols[j].back().first) {
        res = rows[i].back().second;
      } else {
        res = cols[j].back().second;
      }
      printf("%d%c", res, " \n"[j == m - 1]);
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