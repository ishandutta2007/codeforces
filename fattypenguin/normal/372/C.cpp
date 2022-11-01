#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cassert>
#include <queue>
#include <vector>
#define FILL(x, c) memset(x, c, sizeof(x))
#define PB push_back
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(it, n) for (__typeof(n.begin()) it = n.begin(); it != n.end(); ++it)

const int INF = 0x3F3F3F3F;

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;

const int N = 150007;

LL dp[2][N];
int a[N], b[N], t[N];

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  REP(i, m) scanf("%d%d%d", &a[i], &b[i], &t[i]);
  REP(i, m) --a[i];
  deque<PII> q;
  int lastTime = -100000000;
  REP(i, m) {
    int now = i & 1, next = now ^ 1;
    long long range = min((t[i] - lastTime) * (long long)d, (long long)n);
    lastTime = t[i];
   // cout << "range = " << range << endl;
    REP(j, n) dp[next][j] = -INF;
    q.clear();
    REP(j, n) {
      while (q.size() > 0 && q.front().second < j - range) {
        q.pop_front();
      }
      while (q.size() > 0 && q.back().first <= dp[now][j]) {
        q.pop_back();
      }
      q.push_back(PII(dp[now][j], j));
      LL best = q.front().first;
      dp[next][j] = max(dp[next][j], best + b[i] - abs(j - a[i]));
    }
    q.clear();
    for (int j = n - 1; j >= 0; --j) {
      while (q.size() > 0 && q.front().second > j + range) {
        q.pop_front();
      }
      while (q.size() > 0 && q.back().first <= dp[now][j]) {
        q.pop_back();
      }
      q.push_back(PII(dp[now][j], j));
      LL best = q.front().first;
      dp[next][j] = max(dp[next][j], best + b[i] - abs(j - a[i]));
    }
  }

  LL ans = -INF;
  REP(i, n) ans = max(ans, dp[m & 1][i]);
  cout << ans << endl;
  return 0;
}