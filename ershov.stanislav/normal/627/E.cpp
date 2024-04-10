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

int r, c, n, k;
vector<int> x, y;

bool read() {
  if (scanf("%d%d%d%d", &r, &c, &n, &k) < 4) {
    return false;
  }
  x = y = vector<int> (n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    x[i]--, y[i]--;
  }
  return true;
}

void solve() {
  vector<pair<int, int> > hor(n), ver(n);
  for (int i = 0; i < n; i++) {
    hor[i] = mp(y[i], i);
    ver[i] = mp(x[i], i);
  }
  sort(hor.begin(), hor.end());
  sort(ver.begin(), ver.end());
  reverse(ver.begin(), ver.end());
  vector<int> nxt(n), pr(n);
  ll ans = 0;
  for (int it = 0; it < r; it++) {
    int cur = -1;
    for (int i = 0; i < n; i++) {
      int now = hor[i].second;
      if (x[now] >= it) {
        if (cur != -1) {
          nxt[cur] = now;
        }
        pr[now] = cur;
        cur = now;
      }
    }
    if (cur != -1) {
      nxt[cur] = -1;
    }
    int add = 0;
    for (int curx = r - 1, i = 0; curx >= it; curx--) {
      for (; i < n && ver[i].first >= curx; i++) {
        int now = ver[i].second;
        if (x[now] < it) {
          continue;
        }
        static int toright[15];
        for (int j = 0, cur = now; j <= k; j++) {
          toright[j] = (cur == -1) ? c : y[cur];
          cur = (cur == -1) ? -1 : nxt[cur];
        }
        for (int j = 0, cur = now; j < k && cur != -1; j++, cur = pr[cur]) {
          int y1 = y[cur];
          int y2 = (pr[cur] == -1) ? -1 : y[pr[cur]];
          add -= (y1 - y2) * (toright[k - j] - toright[k - j - 1]);
        }
        int a = pr[now], b = nxt[now];
        if (a != -1) {
          nxt[a] = b;
        }
        if (b != -1) {
          pr[b] = a;
        }
      }
      ans += add;
    }
    ans -= (ll) add * (r - it + 1); 
  }
  printf(LLD "\n", ans);
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