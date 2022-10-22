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

  int l; cin >> l;
  long long overflow = 1;
  REP(i, 32) overflow *= 2;
  long long f = 0, x = 1, memo = 0;
  int sz = -1;
  vector<int> n;
  while (l--) {
    string command; cin >> command;
    if (command == "add") {
      f += x;
      if (f >= overflow) {
        cout << "OVERFLOW!!!\n";
        return 0;
      }
    } else if (command == "for") {
      int loop; cin >> loop;
      n.emplace_back(loop);
      x *= loop;
      if (x >= overflow) {
        if (sz == -1) {
          sz = n.size();
          memo = x / n.back();
        }
        x = overflow;
      }
    } else {
      if (x == overflow) {
        if (sz == n.size()) {
          sz = -1;
          x = memo;
        }
      } else {
        x /= n.back();
      }
      n.pop_back();
    }
  }
  cout << f << '\n';
  return 0;
}