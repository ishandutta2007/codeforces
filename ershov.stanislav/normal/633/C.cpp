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

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 1e6 + 100;
int n, m;
char s[maxn];
vector<string> v;
int go[maxn][26];
int isok[maxn];
int cntall;

int add() {
  int len = sz(v.back());
  int cur, i;
  for (cur = 0, i = 0; i < len; i++) {
    int nxt;
    char c = tolower((v.back())[i]);
    if (go[cur][c] == -1) {
      go[cur][c] = cntall++;
    }
    nxt = go[cur][c];
    cur = nxt;
  }
  isok[cur] = sz(v);
}

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", s);
  scanf("%d", &m);
  cntall = 1;
  memset(go, -1, sizeof(go));
  memset(isok, 0, sizeof(isok));
  v.clear();
  for (int i = 0; i < m; i++) {
    string cur;
    cin >> cur;
    v.pb(cur);
    add();
  }
  return true;
}

void solve() {
  reverse(s, s + n);
  vector<int> pr(n + 1, -1), good(n + 1);
  vector<int> topush(n + 1);
  good[0] = 1;
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      int cur = 0;
      for (int j = i; j < n; j++) {
        cur = go[cur][s[j]];
        if (cur == -1) {
          break;
        }
        if (isok[cur]) {
          good[j + 1] = 1;
          pr[j + 1] = i;
          topush[j + 1] = isok[cur] - 1;
        }
      }
    }
  }
  vector<string> ans;
  for (int i = n; i != 0; i = pr[i]) {
    int nxt = pr[i];
    ans.pb(v[topush[i]]);
  }
  for (int i = 0; i < sz(ans); i++) {
    cout << ans[i];
    if (i < sz(ans) - 1) {
      cout << ' ';
    }
  }
  cout << endl;
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}