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

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
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

const int maxn = 2e5 + 100;
int n;
int a[maxn];
vector<int> divs[maxn];

void precalc() {
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      divs[j].pb(i);
    }
  }
}

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}
set<pair<int, int> > st;
ll sumst;

void dosomething(int i, int val) {
  //eprintf("%d %d\n", i, val);
  if (i >= n) {
    return;
  }
  auto iter = st.upper_bound(mp(i, inf));
  iter--;
  if (iter->second >= val) {
    return;
  }
  int valmn = iter->second;
  {
    iter++;
    vector<pair<int, int> > toerase;
    while (iter != st.end()) {
      int curval = iter->second;
      if (curval > val) {
        break;
      }
      int curbegin = iter->first;
      toerase.pb(*iter);
      //eprintf("iter: %d %d\n", iter->first, iter->second);
      iter++;
      int nxtx = (iter == st.end() ? n : iter->first);
      sumst -= (ll) (nxtx - curbegin) * (curval - valmn);
      //eprintf("%d\n", sumst);
    }
    for (int i = 0; i < sz(toerase); i++) {
      st.erase(toerase[i]);
    }
  }
  auto iter2 = st.upper_bound(mp(i, inf));
  int nxtx = (iter2 == st.end() ? n : iter2->first);
  sumst += (ll) (nxtx - i) * (val - valmn);
  st.insert(mp(i, val));
      //eprintf("%d\n", sumst);
}

void solve() {
  if (n <= 2) {
    printf("0\n");
    return;
  }
  vector<vector<int> > cnt(maxn);
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (auto j : divs[a[i]]) {
      cnt[j].pb(i);
    }
  }
  st.clear();
  sumst = 0;
  for (int i = 0; i < n; i++) {
    st.insert(mp(i, i + 1));
    sumst += i + 1;
  }
  vector<ll> ans(maxn);
  for (int i = maxn - 1; i >= 0; i--) {
    if (sz(cnt[i]) <= 1) {
      continue;
    }
    //eprintf("%d\n", i);
    //eprintf("%lld\n", sumst);
    ans[i] = ((ll) n * (n + 1) - sumst);
    dosomething(0, cnt[i][sz(cnt[i]) - 2] + 1);
    dosomething(cnt[i][0] + 1, cnt[i][sz(cnt[i]) - 1] + 1);
    dosomething(cnt[i][1] + 1, n + 1);
  }
  ll prevcnt = 0;
  for (int i = 0; i < maxn; i++) {
    if (ans[i] == 0) {
      continue;
    }
    ans[i] -= prevcnt;
    //eprintf("i = %d, ans[i] = %d\n", i, ans[i]);
    prevcnt += ans[i];
    res += (ll) i * ans[i];
  }
  printf(LLD "\n", res - 3);
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