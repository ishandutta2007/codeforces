#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;

#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  int m = n;
  int ans = 0;
  while (m >= k + 1) {
    m -= k;
    ans += 2;
  }
  if (m >= 2) {
    ans++;
  }
  if (m > 2) {
    ans++;
  }
  printf("%d\n", ans);
  vector<pair<int, int> > v;
  for (int i = 1; i < m; i++) {
    v.pb(mp(0, i));
  }
  for (int i = 0; i < k; i++) {
    v.pb(mp(m + i, min(i + (m > 2), m - 1)));
  }
  for (int i = m + k; i < n; i++) {
    v.pb(mp(i, i - k));
  }
  for (auto i : v) {
    printf("%d %d\n", i.first + 1, i.second + 1);
  }
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}