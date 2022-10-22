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
#include <numeric>
#include <queue>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<long long> b(n); REP(i, n) cin >> b[i];
  vector<int> cnt(60, 0);
  REP(i, n) {
    REP(j, 60) {
      if (b[i] % (1LL << (j + 1)) == (1LL << j)) {
        ++cnt[j];
        break;
      }
    }
  }
  int idx = max_element(ALL(cnt)) - cnt.begin();
  vector<long long> ans;
  REP(i, n) {
    if (b[i] % (1LL << (idx + 1)) != (1LL << idx)) ans.emplace_back(b[i]);
  }
  int sz = ans.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans[i] << (i + 1 == sz ? '\n' : ' ');
  return 0;
}