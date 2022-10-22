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

  int k; cin >> k;
  FOR(n, 5, k) if (k % n == 0) {
    if (k / n < 5) continue;
    string ans = "";
    if (n % 5 == 0) {
      vector<string> boin{"aiueo", "iueoa", "ueoai", "eoaiu", "oaiue"};
      int cnt = 0;
      while ((int)ans.length() < k) {
        ans += boin[cnt % 5];
        ++cnt;
      }
    } else {
      while ((int)ans.length() < k) ans += "aiueo";
    }
    cout << ans.substr(0, k) << '\n';
    return 0;
  }
  cout << -1 << '\n';
  return 0;
}