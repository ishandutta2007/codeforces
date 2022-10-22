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

  int n, m; cin >> n >> m;
  vector<int> t(n); REP(i, n) cin >> t[i];
  vector<int> cnt(101, 0);
  int sum = 0;
  REP(i, n) {
    int tmp = sum + t[i], ans = 0;
    if (tmp > m) {
      for (int j = 100; j >= 1; --j) {
        if (tmp - j * cnt[j] <= m) {
          int tm = (tmp - m + j - 1) / j;
          tmp -= tm * cnt[j];
          ans += tm;
          break;
        } else {
          tmp -= j * cnt[j];
          ans += cnt[j];
        }
      }
    }
    sum += t[i];
    ++cnt[t[i]];
    cout << ans << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}