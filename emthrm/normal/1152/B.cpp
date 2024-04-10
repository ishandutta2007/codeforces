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

  int x; cin >> x;
  int t = 0;
  vector<int> n;
  while (__builtin_popcount(x + 1) > 1) {
    ++t;
    if (t & 1) {
      int flag;
      REP(i, 20) {
        if (x >> i & 1) flag = i;
      }
      int ni = (1 << (flag + 1)) - 1;
      x ^= ni;
      n.emplace_back(flag + 1);
    } else {
      ++x;
    }
  }
  cout << t << '\n';
  REP(i, n.size()) cout << n[i] << (i == n.size() - 1 ? '\n' : ' ');
  return 0;
}