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
int n, m;
int a[maxn], t[maxn], r[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int j = 0; j < m; j++) {
    scanf("%d%d", t + j, r + j);
    r[j]--;
  }
  return true;
}

void solve() {
  vector<int> st;
  for (int i = 0; i < m; i++) {
    while (sz(st) && r[st.back()] <= r[i]) {
      st.pop_back();
    }
    st.pb(i);
  }
  vector<int> ans;
  multiset<int> have;
  for (int i = 0; i < n; i++) {
    have.insert(a[i]);
  }
  for (int j = n - 1; j > r[st[0]]; j--) {
    ans.pb(a[j]);
    have.erase(have.find(a[j]));
  }
  for (int i = 0; i < sz(st); i++) {
    int nxt = (i < sz(st) - 1 ? r[st[i + 1]] : -1);
    for (int j = r[st[i]]; j > nxt; j--) {
      int val;
      if (t[st[i]] == 1) {
        val = *have.rbegin();
      } else {
        val = *have.begin();
      }
      have.erase(have.find(val));
      ans.pb(val);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    printf("%d%c", ans[i], " \n"[i == 0]);
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