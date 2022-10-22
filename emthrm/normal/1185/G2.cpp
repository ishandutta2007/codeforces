#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, T; cin >> n >> T;
  vector<int> t(n), g(n), cnt(3, 0), dur(3, 0);
  REP(i, n) {
    cin >> t[i] >> g[i]; --g[i];
    ++cnt[g[i]];
    dur[g[i]] += t[i];
  }
  vector<vector<long long> > a(cnt[0] + 1, vector<long long>(dur[0] + 1, 0));
  vector<vector<vector<long long> > > bc(cnt[1] + 1, vector<vector<long long> > (cnt[2] + 1, vector<long long>(dur[1] + dur[2] + 1, 0)));
  a[0][0] = 1;
  bc[0][0][0] = 1;
  REP(i, n) {
    if (g[i] == 0) {
      for (int j = cnt[0] - 1; j >= 0; --j) REP(k, dur[0] + 1) {
        if (k + t[i] <= dur[0]) (a[j + 1][k + t[i]] += a[j][k]) %= MOD;
      }
    } else {
      for (int j = cnt[1]; j >= 0; --j) for (int k = cnt[2]; k >= 0; --k) REP(l, dur[1] + dur[2] + 1) {
        if (l + t[i] <= dur[1] + dur[2]) {
          if (g[i] == 1) {
            if (j + 1 <= cnt[1]) (bc[j + 1][k][l + t[i]] += bc[j][k][l]) %= MOD;
          } else {
            if (k + 1 <= cnt[2]) (bc[j][k + 1][l + t[i]] += bc[j][k][l]) %= MOD;
          }
        }
      }
    }
  }
  vector<vector<vector<vector<long long> > > > dp(cnt[0] + 1, vector<vector<vector<long long> > >(cnt[1] + 1, vector<vector<long long> >(cnt[2] + 1, vector<long long>(4, 0))));
  dp[0][0][0][3] = 1;
  REP(i, cnt[0] + 1) REP(j, cnt[1] + 1) REP(k, cnt[2] + 1) REP(l, 4) {
    REP(m, 3) if (m != l) {
      if (m == 0) {
        if (i + 1 <= cnt[0]) (dp[i + 1][j][k][m] += dp[i][j][k][l]) %= MOD;
      } else if (m == 1) {
        if (j + 1 <= cnt[1]) (dp[i][j + 1][k][m] += dp[i][j][k][l]) %= MOD;
      } else {
        if (k + 1 <= cnt[2]) (dp[i][j][k + 1][m] += dp[i][j][k][l]) %= MOD;
      }
    }
  }
  vector<long long> fac(51, 1);
  FOR(i, 1, 51) fac[i] = fac[i - 1] * i % MOD;
  long long ans = 0;
  REP(i, cnt[0] + 1) REP(j, dur[0] + 1) if (0 <= T - j && T - j <= dur[1] + dur[2]) {
    REP(k, cnt[1] + 1) REP(l, cnt[2] + 1) {
      long long tmp = 0;
      REP(m, 3) (tmp += dp[i][k][l][m]) %= MOD;
      (tmp *= a[i][j] * bc[k][l][T - j] % MOD) %= MOD;
      (tmp *= fac[i] * fac[k] % MOD * fac[l] % MOD) %= MOD;
      (ans += tmp) %= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}