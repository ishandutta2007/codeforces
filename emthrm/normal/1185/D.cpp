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
  vector<pair<int, int> > b(n);
  REP(i, n) {
    cin >> b[i].first;
    b[i].second = i + 1;
  }
  sort(ALL(b));
  map<int, int> mp;
  FOR(i, 1, n) ++mp[b[i].first - b[i - 1].first];
  REP(i, n) {
    vector<int> kesu;
    if (i < n - 1) kesu.emplace_back(b[i + 1].first - b[i].first);
    if (i > 0) kesu.emplace_back(b[i].first - b[i - 1].first);
    for (int e : kesu) {
      --mp[e];
      if (mp[e] == 0) mp.erase(e);
    }
    if (0 < i && i < n - 1) ++mp[b[i + 1].first - b[i - 1].first];
    if (mp.size() <= 1) {
      cout << b[i].second << '\n';
      return 0;
    }
    for (int e : kesu) ++mp[e];
    if (0 < i && i < n - 1) {
      int tmp = b[i + 1].first - b[i - 1].first;
      --mp[tmp];
      if (mp[tmp] == 0) mp.erase(tmp);
    }
  }
  cout << -1 << '\n';
  return 0;
}