#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

int t;

bool read() {
  if (scanf("%d", &t) < 1) {
    return false;
  }
  return true;
}

int cnt[1 << 20];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < t; i++) {
    char c;
    scanf(" %c", &c);
    if (c == '+' || c == '-') {
      ll val;
      scanf("%lld", &val);
      int msk = 0;
      for (int i = 0; i < 20; i++) {
        if (val & 1) {
          msk ^= (1 << i);
        }
        val /= 10;
      }
      if (c == '+') {
        cnt[msk]++;
      } else {
        cnt[msk]--;
      }
    } else {
      char s[100];
      scanf("%s", s);
      int len = strlen(s);
      reverse(s, s + len);
      int msk = 0;
      for (int i = 0; s[i]; i++) {
        if (s[i] == '1') {
          msk ^= (1 << i);
        }
      }
      printf("%d\n", cnt[msk]);
    }
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