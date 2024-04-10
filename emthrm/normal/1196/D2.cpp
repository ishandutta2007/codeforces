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
  map<char, int> mp;
  mp['R'] = 0; mp['G'] = 1; mp['B'] = 2;
  while (q--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int> > rgb(n + 1, vector<int>(3, 0));
    REP(j, 3) {
      int color = j;
      REP(i, n) {
        if (mp[s[i]] != color) rgb[i + 1][j] = 1;
        rgb[i + 1][j] += rgb[i][j];
        color = (color + 1) % 3;
      }
    }
    int ans = INF;
    REP(i, n - k + 1) {
      REP(j, 3) ans = min(ans, rgb[i + k][j] - rgb[i][j]);
    }
    cout << ans << '\n';
  }
  return 0;
}