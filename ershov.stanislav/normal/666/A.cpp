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

void precalc() {
}

const int maxn = 1e5;
int n;
string str;
char s[maxn];
int dp[5][maxn];

bool read() {
  if (scanf("%s", s) < 1) {
    return false;
  }
  str = string(s);
  n = strlen(s);
  return true;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[2][n - 2] = 1;
  dp[3][n - 3] = 1;
  for (int i = n - 4; i >= 5; i--) {
    for (int j = 2; j <= 3; j++) {
      if (dp[j ^ 1][i + j]) {
        dp[j][i] = 1;
      }
      if (i + j * 2 <= n) {
        string s1 = str.substr(i, j);
        string s2 = str.substr(i + j, j);
        if (s1 != s2 && dp[j][i + j]) {
          dp[j][i] = 1;
        }
      }
    }
  }
  set<string> ans;
  for (int i = 5; i < n; i++) {
    for (int j = 2; j <= 3; j++) {
      if (i + j > n) {
        continue;
      }
      if (i + j == n - 1) {
        continue;
      }
      string cur = str.substr(i, j);
      if (dp[2][i + j] || dp[3][i + j] || n == i + j) {
        ans.insert(cur);
      }
    }
  }
  printf("%d\n", sz(ans));
  for (string s : ans) {
    printf("%s\n", s.c_str());
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