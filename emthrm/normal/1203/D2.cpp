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
const int CHARACTER = 26;
vector<vector<int> > nx_init(const string &str) {
  int n = str.size();
  vector<vector<int> > nx(n, vector<int>(CHARACTER, n));
  nx[n - 1][str[n - 1] - 'a'] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    REP(j, CHARACTER) nx[i][j] = nx[i + 1][j];
    nx[i][str[i] - 'a'] = i;
  }
  return nx;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string s, t; cin >> s >> t;
  int s_len = s.length(), t_len = t.length();
  auto nx = nx_init(s);
  vector<int> pos_fr(t_len);
  int pos = 0;
  REP(i, t_len) {
    pos = nx[pos][t[i] - 'a'];
    pos_fr[i] = pos;
    ++pos;
  }
  reverse(ALL(s));
  reverse(ALL(t));
  nx = nx_init(s);
  vector<int> pos_ba(t_len);
  pos = 0;
  REP(i, t_len) {
    pos = nx[pos][t[i] - 'a'];
    pos_ba[i] = s_len - 1 - pos;
    ++pos;
  }
  reverse(ALL(pos_ba));
  int ans = max(pos_ba.front(), s_len - 1 - pos_fr.back());
  REP(i, t_len - 1) {
    ans = max(ans, pos_ba[i + 1] - pos_fr[i] - 1);
  }
  cout << ans << '\n';
  return 0;
}