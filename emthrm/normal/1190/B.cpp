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
#define int long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  REP(i, n) {
    cin >> a[i];
    ++mp[a[i]];
  }
  if (n == 1) {
    cout << (a[0] & 1 ? "sjfnb\n" : "cslnb\n");
    return 0;
  }
  int two = 0;
  for (auto p : mp) {
    if (p.second >= 3) {
      cout << "cslnb\n";
      return 0;
    }
    if (p.second == 2) {
      ++two;
      if (mp.count(p.first - 1)) {
        cout << "cslnb\n";
        return 0;
      }
    }
  }
  if (two >= 2) {
    cout << "cslnb\n";
    return 0;
  }
  sort(ALL(a));
  long long yuyo = 0;
  REP(i, n) {
    if (a[i] < i) {
      cout << "cslnb\n";
      return 0;
    }
    yuyo += a[i] - i;
  }
  cout << ((yuyo & 1) ? "sjfnb\n" : "cslnb\n");
  return 0;
}