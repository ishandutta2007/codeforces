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

  int n; cin >> n;
  int sum = 0;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  int alice = a[0];
  vector<int> ans{1};
  FOR(i, 1, n) {
    if (a[i] <= a[0] / 2) {
      ans.emplace_back(i + 1);
      alice += a[i];
    }
  }
  if (sum / 2 + 1 <= alice) {
    cout << ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
  } else {
    cout << 0 << '\n';
  }
  return 0;
}