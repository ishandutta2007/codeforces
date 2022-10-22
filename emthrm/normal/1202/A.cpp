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
// string add(string x, string y) {
//   if (x.length() < y.length()) swap(x, y);
//   int n = x.length();
//   reverse(ALL(x));
//   reverse(ALL(y));
//   vector<int> kuriage(n + 1, 0);
//   vector<string> res;
//   REP(i, n + 1) {
//     int plus = kuriage[i];
//     if (i < n) plus += x[i] - '0';
//     if (i < y.length()) plus += (y[i] - '0');
//     if (plus <= 1) {
//       res += '0' + plus;
//     } else {
//       kuriage[i + 1] = 1;
//       res += (plus == 2 ? '0' : '1');
//     }
//   }
//   reverse(ALL(res));
//   while (true) {
//     if (res.back() == '0') res.pop_back();
//   }
//   return res;
// }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    string x, y; cin >> x >> y;
    reverse(ALL(x));
    reverse(ALL(y));
    int pos = y.find('1'), ans = -1;
    FOR(i, pos, x.length()) {
      if (x[i] == '1') {
        ans = i - pos;
        break;
      }
    }
    cout << (ans == -1 ? 0 : ans) << '\n';
  }
  return 0;
}