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

  int m, n; cin >> m >> n;
  vector<vector<bool> > bought(m, vector<bool>(n, false));
  REP(i, m) {
    int s; cin >> s;
    while (s--) {
      int shop; cin >> shop; --shop;
      bought[i][shop] = true;
    }
  }
  vector<vector<bool> > connected(m, vector<bool>(m, false));
  REP(i, n) {
    vector<int> st;
    REP(j, m) {
      if (bought[j][i]) st.emplace_back(j);
    }
    REP(j, st.size()) FOR(k, j + 1, st.size()) {
      connected[st[j]][st[k]] = true;
    }
  }
  REP(i, m) FOR(j, i + 1, m) {
    if (!connected[i][j]) {
      cout << "impossible\n";
      return 0;
    }
  }
  cout << "possible\n";
  return 0;
}