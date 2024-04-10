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

  int n, m; cin >> n >> m;
  vector<vector<int> > light(n);
  for (int i = n - 1; i >= 0; --i) REP(j, m + 2) {
    char c; cin >> c;
    if (c == '1') light[i].emplace_back(j);
  }
  int last = -1;
  REP(i, n) {
    if (!light[i].empty()) last = i;
  }
  if (last == -1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> l(last + 1, INF), r(last + 1, INF);
  l[0] = 0;
  REP(i, last) {
    if (light[i].empty()) {
      l[i + 1] = l[i] + 1;
      r[i + 1] = r[i] + 1;
    } else {
      l[i + 1] = min(l[i] + light[i].back() * 2, r[i] + m + 1) + 1;
      r[i + 1] = min(r[i] + (m + 1 - light[i].front()) * 2, l[i] + m + 1) + 1;
    }
  }
  cout << min(l[last] + light[last].back(), r[last] + (m + 1 - light[last].front())) << '\n';
  return 0;
}