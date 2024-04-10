#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

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

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 1e5 + 100;
int n;
int a, x[maxn], y[maxn];

ld norm(ld x) {
  while (x < -PI) {
    x += 2 * PI;
  }
  while (x > PI) {
    x -= 2 * PI;
  }
  return x;
}

bool read() {
  if (scanf("%d%d", &n, &a) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  return true;
}

void solve() {
  vector<ld> ang(n), dist(n), r(n);
  for (int i = 0; i < n; i++) {
    ld curx = ((ld) x[i] + a) / 2;
    ld cury = ((ld) y[i]) / 2;
    ang[i] = atan2(cury, curx);
    dist[i] = sqrt(curx * curx + cury * cury);
    ld x1 = curx - a, y1 = cury;
    r[i] = x1 * x1 + y1 * y1;
  }
  ld l = 0, diff = a;
  while (diff / max(1.0L, l) > 1e-7) {
    diff /= 2;
    ld mid = l + diff;
    vector<pair<ld, int> > events;
    for (int i = 0; i < n; i++) {
      ld val = (dist[i] / 2 - (r[i] - mid * mid) / dist[i] / 2) / mid;
      if (val > 1 - EPS || val < -1 + EPS) {
        continue;
      }
      ld curang = acos(val);
      ld ang1 = ang[i] - curang, ang2 = ang[i] + curang;
      ang1 = norm(ang1);
      ang2 = norm(ang2);
      if (ang1 > ang2) {
        swap(ang1, ang2);
      }
      events.eb(ang1, i + 1);
      events.eb(ang2, -i - 1);
    }
    vector<int> st;
    sort(events.begin(), events.end());
    bool ok = false;
    for (auto i : events) {
      if (i.second < 0) {
        if (!sz(st) || st.back() != -i.second) {
          ok = true;
          break;
        }
        st.pop_back();
      } else {
        st.pb(i.second);
      }
    }
    if (!ok) {
      l = mid;
    }
  }
  printf("%.18f\n", (double) (2 * l));
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