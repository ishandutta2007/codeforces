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

const int maxn = 2e5 + 100;
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  return true;
}
vector<int> v1, v2;

int geta(int i) {
  return a[*(lower_bound(v1.begin(), v1.end(), i))];
}
int getb(int i) {
  return b[*(lower_bound(v2.begin(), v2.end(), i))];
}

void solve() {
  v1.clear(), v2.clear();
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while (sz(v1) && a[v1.back()] <= a[i]) {
      v1.pop_back();
    }
    v1.pb(i);
    while (sz(v2) && b[v2.back()] >= b[i]) {
      v2.pop_back();
    }
    v2.pb(i);
    int ans1, ans2;
    {
      int l = 0, r = i + 1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (geta(mid) > getb(mid)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      ans1 = l;
    }
    {
      int l = 0, r = i + 1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (geta(mid) >= getb(mid)) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      ans2 = l;
    }
    ans += ans2 - ans1;
  }
  printf("%lld\n", ans);
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