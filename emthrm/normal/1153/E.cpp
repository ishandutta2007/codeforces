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
  vector<int> tate, yoko;
  REP(i, n) {
    cout << "? " << i + 1 << " 1 " << i + 1 << ' ' << n << endl;
    int res; cin >> res;
    if (res & 1) tate.emplace_back(i + 1);
  }
  REP(i, n) {
    cout << "? 1 " << i + 1 << ' ' << n << ' ' << i + 1 << endl;
    int res; cin >> res;
    if (res & 1) yoko.emplace_back(i + 1);
  }
  vector<int> ans;
  if (tate.size() == 2 && yoko.size() == 2) {
    REP(i, 2) REP(j, 2) {
      cout << "? " << tate[i] << ' ' << yoko[j] << ' ' << tate[i] << ' ' << yoko[j] << endl;
      int res; cin >> res;
      if (res == 1) {
        ans.emplace_back(tate[i]);
        ans.emplace_back(yoko[j]);
      }
    }
  } else if (tate.size() == 2) {
    int lb = 0, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      cout << "? " << tate[0] << ' ' << 1 << ' ' << tate[0] << ' ' << mid << endl;
      int res; cin >> res;
      (res & 1 ? ub : lb) = mid;
    }
    ans = {tate[0], ub, tate[1], ub};
  } else {
    int lb = 0, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      cout << "? " << 1 << ' ' << yoko[0] << ' ' << mid << ' ' << yoko[0] << endl;
      int res; cin >> res;
      (res & 1 ? ub : lb) = mid;
    }
    ans = {ub, yoko[0], ub, yoko[1]};
  }
  cout << "! ";
  REP(i, 4) {
    cout << ans[i];
    if (i == 3) cout << endl;
    else cout << ' ';
  }
  return 0;
}