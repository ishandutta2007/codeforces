#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100010, M = 260;

int n, a, b, c;
char s[N];
int sa[M], sb[M], sc[M];
int cur[26];
int nxt[N][26];
int dp[M][M][M];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int q;
  scanf("%d%d%s", &n, &q, s + 1);
  fill(cur, cur + 26, n + 1);
  memcpy(nxt[n + 1], cur, sizeof(cur));
  for (int i = n; i; --i) {
    memcpy(nxt[i], cur, sizeof(cur));
    cur[s[i] - 'a'] = i;
  }
  memcpy(nxt[0], cur, sizeof(cur));
  while (q--) {
    char opt;
    int x;
    scanf(" %c%d", &opt, &x);
    LOG("OPT %c %d\n", opt, x);
    if (opt == '+') {
      char y;
      scanf(" %c", &y);
      y -= 'a';
      LOG("%d\n", int(y));
      if (x == 1) {
        sa[++a] = y;
        for (int i = 0; i <= b; ++i)
          for (int j = 0; j <= c; ++j) {
            dp[a][i][j] = nxt[dp[a - 1][i][j]][sa[a]];
            if (i) dp[a][i][j] = min(dp[a][i][j], nxt[dp[a][i - 1][j]][sb[i]]);
            if (j) dp[a][i][j] = min(dp[a][i][j], nxt[dp[a][i][j - 1]][sc[j]]);
          }
      } else if (x == 2) {
        sb[++b] = y;
        for (int i = 0; i <= a; ++i)
          for (int j = 0; j <= c; ++j) {
            dp[i][b][j] = nxt[dp[i][b - 1][j]][sb[b]];
            if (i) dp[i][b][j] = min(dp[i][b][j], nxt[dp[i - 1][b][j]][sa[i]]);
            if (j) dp[i][b][j] = min(dp[i][b][j], nxt[dp[i][b][j - 1]][sc[j]]);
          }
      } else {
        sc[++c] = y;
        for (int i = 0; i <= a; ++i)
          for (int j = 0; j <= b; ++j) {
            dp[i][j][c] = nxt[dp[i][j][c - 1]][sc[c]];
            if (i) dp[i][j][c] = min(dp[i][j][c], nxt[dp[i - 1][j][c]][sa[i]]);
            if (j) dp[i][j][c] = min(dp[i][j][c], nxt[dp[i][j - 1][c]][sb[j]]);
          }
      }
    } else {
      if (x == 1) --a;
      else if (x == 2) --b;
      else --c;
    }
    puts(dp[a][b][c] <= n ? "YES" : "NO");
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}