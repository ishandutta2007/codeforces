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

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  int ans = a + b;
  if (ans >= MOD) {
    ans -= MOD;
  }
  return ans;
}

const int maxn = 2e6 + 100;
int n, k;
int m;
char s[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", s);
  m = strlen(s);
  return true;
}

void solve() {
  vector<int> was(k, -1);
  vector<int> dp(n + m + 1);
  dp[0] = 1;
  for (int i = 0; i < n + m; i++) {
    int curc;
    if (i < m) {
      curc = s[i] - 'a';
    } else {
      int mn = -1;
      for (int j = 0; j < k; j++) {
        if (mn == -1 || was[mn] > was[j]) {
          mn = j;
        }
      }
      curc = mn;
    }
    dp[i + 1] = add(dp[i], add(dp[i], (was[curc] == -1) ? 0 : MOD - dp[was[curc]]));
    was[curc] = i;
  }
  printf("%d\n", dp[n + m]);
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