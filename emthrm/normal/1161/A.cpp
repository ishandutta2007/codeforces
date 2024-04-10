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

  int n, k; cin >> n >> k;
  vector<int> x(k); REP(i, k) cin >> x[i];
  long long ans = (n - 2) * 3 + 4;
  vector<int> cnt(n + 1, 0);
  REP(i, k) ++cnt[x[i]];
  vector<bool> used(n + 1, false);
  REP(i, k) {
    --cnt[x[i]];
    if (!used[x[i]]) {
      used[x[i]] = true;
      --ans;
      if (x[i] > 1 && cnt[x[i] - 1] > 0) --ans;
      if (x[i] < n && cnt[x[i] + 1] > 0) --ans;
    }
    // cout << ans << '\n';
  }
  cout << ans << '\n';
  return 0;
}