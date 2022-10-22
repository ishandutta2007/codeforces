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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string d; cin >> d;
    map<char, int> mp;
    REP(i, n) ++mp[d[i]];
    vector<int> color(n, 0);
    int two_front = INF;
    REP(i, n) {
      if (d[i] == (*mp.begin()).first && d[i] - '0' <= two_front) {
        color[i] = 1;
      } else if (two_front == INF) {
        two_front = d[i] - '0';
      }
      --mp[d[i]];
      if (mp[d[i]] == 0) mp.erase(d[i]);
    }
    string two = "";
    REP(i, n) {
      if (color[i] == 0) {
        color[i] = 2;
        two += d[i];
      }
    }
    int sz = two.length();
    bool ok = true;
    REP(i, sz - 1) {
      if (two[i] > two[i + 1]) ok = false;
    }
    if (!ok) {
      cout << "-\n";
      continue;
    }
    REP(i, n) cout << color[i];
    cout << '\n';
  }
  return 0;
}