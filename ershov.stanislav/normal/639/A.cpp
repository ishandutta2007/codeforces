#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 2e5 + 100;
int n, k, q;
int t[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", t + i);
  }
  return true;
}

void solve() {
  set<pair<int, int> > s;
  for (int i = 0; i < q; i++) {
    int tp, id;
    scanf("%d%d", &tp, &id);
    id--;
    if (tp == 1) {
      s.insert(mp(-t[id], id));
    } else {
      bool ok = false;
      int j = 0;
      for (auto r : s) {
        if (r.second == id) {
          ok = true;
          break;
        }
        j++;
        if (j >= k) {
          break;
        }
      }
      printf(ok ? "YES\n" : "NO\n");
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}