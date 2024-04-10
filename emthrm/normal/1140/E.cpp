#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int k;

long long solve(vector<int> a) {
  int n = a.size();
  long long res = 1;
  for (int i = 0; i < n; ) {
    if (a[i] == -1) {
      int j = i + 1;
      while (j < n && a[j] == -1) ++j;
      int tm = j - i;
      if (j == n) {
        if (i == 0) (res *= k) %= MOD;
        else (res *= k - 1) %= MOD;
        REP(i, tm - 1) (res *= k - 1) %= MOD;
      } else if (i == 0) {
        REP(i, tm) (res *= k - 1) %= MOD;
      } else {
        if (a[i - 1] == a[j]) {
          vector<vector<long long> > dp(tm, vector<long long>(2, 0));
          dp[0][false] = k - 1;
          FOR(i, 1, tm) {
            dp[i][true] = dp[i - 1][false];
            dp[i][false] = (dp[i - 1][true] * (k - 1) % MOD + dp[i - 1][false] * (k - 2) % MOD) % MOD;
          }
          (res *= dp[tm - 1][false]) %= MOD;
        } else {
          vector<vector<vector<long long> > > dp(tm, vector<vector<long long> >(2, vector<long long>(2, 0)));
          dp[0][false][false] = k - 2;
          dp[0][false][true] = 1;
          FOR(i, 1, tm) {
            dp[i][true][false] = (dp[i - 1][false][true] + dp[i - 1][false][false]) % MOD;
            dp[i][false][true] = (dp[i - 1][true][false] + dp[i - 1][false][false]) % MOD;
            dp[i][false][false] = ((dp[i - 1][true][false] * (k - 2) % MOD + dp[i - 1][false][true] * (k - 2) % MOD) % MOD + dp[i - 1][false][false] * (k - 3) % MOD) % MOD;
          }
          (res *= (dp[tm - 1][true][false] + dp[tm - 1][false][false]) % MOD) %= MOD;
        }
      }
      i = j;
    } else {
      if (i >= 1) {
        if (a[i - 1] == a[i]) return -1;
      }
      if (i <= n - 2) {
        if (a[i] == a[i + 1]) return -1;
      }
      ++i;
    }
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n >> k;
  vector<int> odd, even;
  REP(i, n) {
    int a; cin >> a;
    if (i & 1) odd.emplace_back(a);
    else even.emplace_back(a);
  }
  long long one = solve(odd), two = solve(even);
  cout << (one == -1 || two == -1 ? 0 : (one * two) % MOD) << '\n';
  return 0;
}