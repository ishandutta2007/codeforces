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

const int maxn = 3e5 + 100;

int n, q;
bool used[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  return true;
}

void solve() {
  vector<vector<int> > apps(n);
  int i1 = 0;
  int cnt = 0;
  int all = 0;
  for (int i = 0; i < q; i++) {
    int t, x;
    scanf("%d%d", &t, &x);
    if (t == 1) {
      cnt++;
      apps[x - 1].pb(all);
      used[all++] = false;
    } else if (t == 2) {
      for (auto i : apps[x - 1]) {
        if (!used[i]) {
          used[i] = true;
          cnt--;
        }
      }
      apps[x - 1].clear();
    } else {
      for (; i1 < x; i1++) {
        if (!used[i1]) {
          used[i1] = true;
          cnt--;
        }
      } 
    }
    printf("%d\n", cnt);
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