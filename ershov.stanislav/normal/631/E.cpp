#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

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

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 2e5 + 100;
int n, a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  vector<ll> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  /*for (int i = 0; i < sz(suf); i++) {
    eprintf("%d%c", suf[i], " \n"[i == sz(suf) - 1]);
  }*/
  vector<int> st;
  for (int i = 0; i <= n; i++) {
    while (sz(st) >= 2) {
      ll cur = (st[sz(st) - 1] - st[sz(st) - 2]) * (suf[i] - suf[st[sz(st) - 1]]) - (suf[st[sz(st) - 1]] - suf[st[sz(st) - 2]]) * (i - st[sz(st) - 1]);
      if (cur >= 0) {
        st.pop_back();
      } else {
        break;
      }
    }
    st.pb(i);
  }
  /*for (int i = 0; i < sz(st); i++) {
    eprintf("%d%c", st[i], " \n"[i == sz(st) - 1]);
  }*/
  ll mx = -lINF;
  for (int i = 0; i < n; i++) {
    int l = 0, r = sz(st) - 1;
    while (r > l) {
      int mid = (l + r) / 2;
      ll ans1 = (ll) a[i] * (st[mid] - i) - suf[i] + suf[st[mid]];
      ll ans2 = (ll) a[i] * (st[mid + 1] - i) - suf[i] + suf[st[mid + 1]];
      if (ans2 <= ans1) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    mx = max(mx, (ll) a[i] * (st[l] - i) - suf[i] + suf[st[l]]);
  }
  for (int i = 0; i < n; i++) {
    mx += (ll) a[i] * (i + 1);
  }
  printf(LLD "\n", mx);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}