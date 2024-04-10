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

const int maxn = 1e5 + 100;
int n, m;
char s[maxn];

bool read() {
  if (scanf("%d", &m) < 1) {
    return false;
  }
  scanf("%s", s);
  n = strlen(s);
  return true;
}

void solve() {
  for (char cur = 'a'; cur <= 'z'; cur++) {
    vector<int> cnt(26);
    bool ok = true;
    int lastcur = -1e18;
    for (int i = 0, last = -1; i < n; i++) {
      if (s[i] == cur) {
        lastcur = i;
      }
      if (s[i] < cur) {
        last = i;
        cnt[s[i] - 'a']++;
      }
      if (i - last >= m) {
        if (lastcur <= last) {
          ok = false;
          break;
        }
        last = lastcur;
        cnt[cur - 'a']++;
      }
    }
    if (!ok) {
      continue;
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        printf("%c", 'a' + i);
      }
    }
    printf("\n");
    break;
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