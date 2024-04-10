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

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    REP(i, n) {
      int a; cin >> a;
      ++cnt[a];
    }
    vector<int> sum(n + 1, 0);
    FOR(i, 1, n + 1) ++sum[cnt[i]];
    int ans = 0, res = 0;
    for (int i = n; i >= 1; --i) {
      res += sum[i];
      if (res >= 1) {
        ans += i;
        --res;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}