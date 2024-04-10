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
  vector<pair<int, int> > a(n);
  REP(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(ALL(a));
  reverse(ALL(a));
  long long ans = 0;
  vector<int> idx;
  REP(i, n) {
    ans += a[i].first * i + 1;
    idx.emplace_back(a[i].second);
  }
  cout << ans << '\n';
  REP(i, n) cout << idx[i] + 1 << (i + 1 == n ? '\n' : ' ');
  return 0;
}