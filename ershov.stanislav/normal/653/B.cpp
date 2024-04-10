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

const int maxn = 100;
int n;
int q;
char a[maxn][3];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < q; i++) {
    scanf(" %c%c %c", a[i], a[i] + 1, a[i] + 2);
  }
  return true;
}

void solve() {
  vector<set<string> > v(n + 1);
  v[1].insert("a");
  for (int len = 2, cnt = 6 * 6; len <= n; len++) {
    for (int i = 0; i < cnt; i++) {
      string cur;
      int ii = i;
      for (int j = 0; j < len; j++) {
        cur.pb((ii % 6) + 'a');
        ii /= 6;
      }
      for (int j = 0; j < q; j++) {
        if (cur[len - 1] == a[j][0] && cur[len - 2] == a[j][1]) {
          string ncur = cur.substr(0, len - 2);
          ncur.pb(a[j][2]);
          if (v[len - 1].find(ncur) != v[len - 1].end()) {
            v[len].insert(cur);
            break;
          }
        }
      }
    }
    cnt *= 6;
  }
  printf("%d\n", sz(v[n]));
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