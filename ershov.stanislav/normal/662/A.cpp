#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

const int maxm = 62;
int n;
vector<ll> a;
ll want;
vector<ll> st;
vector<int> bit;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  a.clear();
  want = 0;
  for (int i = 0; i < n; i++) {
    ll c, d;
    scanf(LLD " " LLD, &c, &d);
    want ^= c;
    a.pb(c ^ d);
  }
  return true;
}

void add(ll cur) {
  for (int i = 0; i < sz(st); i++) {
    if ((cur >> bit[i]) & 1) {
      cur ^= st[i];
    }
  }
  if (cur) {
    st.pb(cur);
    for (int j = 0; j < maxm; j++) {
      if ((cur >> j) & 1) {
        bit.pb(j);
        return;
      }
    }
  }
}
void solve() {
  st.clear();
  bit.clear();
  for (int i = 0; i < n; i++) {
    add(a[i]);
  }
  int was = sz(st);
  add(want);
  if (sz(st) != was) {
    printf("1/1\n");
  } else {
    int pw = sz(st);
    printf(LLD "/" LLD "\n", (1ll << pw) - 1, (1ll << pw));
  }
}

int main() {
  srand(rdtsc());
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