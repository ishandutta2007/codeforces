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

  string s; cin >> s;
  int n = s.length();
  vector<pair<char, int> > wow;
  char now = s[0];
  int cnt = 1;
  FOR(i, 1, n) {
    if (now != s[i]) {
      wow.emplace_back(now, cnt);
      cnt = 1;
    } else {
      ++cnt;
    }
    now = s[i];
  }
  wow.emplace_back(now, cnt);
  if (wow[0].first == 'o') wow.erase(wow.begin());
  vector<int> tmp;
  REP(i, wow.size()) {
    if (i % 2 == 0) {
      tmp.emplace_back(wow[i].second - 1);
    } else {
      tmp.emplace_back(wow[i].second);
    }
  }
  if (tmp.size() % 2 == 0) wow.pop_back();
  vector<int> mae(tmp.size(), 0), ushiro(tmp.size());
  int maemae = 0;
  REP(i, tmp.size()) {
    if (i % 2 == 0) maemae += tmp[i];
    else mae[i] = maemae;
  }
  int ushiroushiro = 0;
  for (int i = (int)tmp.size() - 1; i >= 0; --i) {
    if (i % 2 == 0) ushiroushiro += tmp[i];
    else ushiro[i] = ushiroushiro;
  }
  long long ans = 0;
  REP(i, tmp.size()) if (i & 1) {
    ans += (long long)tmp[i] * mae[i] * ushiro[i];
  }
  cout << ans << '\n';
  return 0;
}