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

int n;
string str;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  cin >> str;
  return true;
}

void solve() {
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    cnt[str[i] - 'a']++;
  }
  int cntdiff = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      cntdiff++;
    }
  }
  if (n > 26) {
    printf("-1\n");
  } else {
    printf("%d\n", n - cntdiff);
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