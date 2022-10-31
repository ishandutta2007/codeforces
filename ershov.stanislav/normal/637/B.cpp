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

int n;
map<string, int> m;
char s[50];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  m.clear();
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    string str(s);
    m[s] = -i;
  }
  return true;
}

void solve() {
  vector<pair<int, string> > v;
  for (auto i : m) {
    v.pb(mp(i.second, i.first));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < sz(v); i++) {
    printf("%s\n", v[i].second.c_str());
  }
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