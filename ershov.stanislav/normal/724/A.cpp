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

int cnt[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> names;

void precalc() {
  names["monday"] = 0;
  names["tuesday"] = 1;
  names["wednesday"] = 2;
  names["thursday"] = 3;
  names["friday"] = 4;
  names["saturday"] = 5;
  names["sunday"] = 6;
}

char s1[1000], s2[1000];

bool read() {
  if (scanf("%s%s", s1, s2) < 2) {
    return false;
  }
  return true;
}

void solve() {
  string str1 = s1, str2 = s2;
  int n1 = names[s1], n2 = names[s2];
  for (int i = 0; i < 11; i++) {
    if (cnt[i] % 7 == (n2 - n1 + 7) % 7) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
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