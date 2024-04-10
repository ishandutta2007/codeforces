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

const int maxn = 100;
int n;
char s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", s);
  return true;
}

bool ok[4][3];
int x[10], y[10];

bool good(int x, int y) {
  return 0 <= x && x < 4 && 0 <= y && y < 3;
}

void solve() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      ok[i][j] = true;
    }
  }
  ok[3][0] = ok[3][2] = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      x[i * 3 + j + 1] = i;
      y[i * 3 + j + 1] = j;
    }
  }
  x[0] = 3, y[0] = 1;
  for (int i = 0; i < n; i++) {
    int first = s[0] - '0';
    int cur = s[i] - '0';
    int movex = x[cur] - x[first];
    int movey = y[cur] - y[first];
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 3; y++) {
        if (!good(x + movex, y + movey)) {
          ok[x][y] = false;
        }
        if (x + movex == 3) {
          if (y + movey == 0 || y + movey == 2) {
            ok[x][y] = false;
          }
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (ok[i][j]) {
        cnt++;
      }
    }
  }
  assert(cnt >= 1);
  printf(cnt > 1 ? "NO\n" : "YES\n");
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