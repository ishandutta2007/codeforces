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

  int n; cin >> n;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  vector<int> b(n); REP(i, n) cin >> b[i];
  map<long long, int> mp;
  map<long long, long long> score;
  REP(i, n) {
    ++mp[a[i]];
    score[a[i]] += b[i];
  }
  long long ans = 0;
  vector<long long> calmly;
  for (auto pr : mp) {
    if (pr.second >= 2) {
      ans += score[pr.first];
      calmly.emplace_back(pr.first);
    }
  }
  for (long long e : calmly) mp.erase(e);
  for (auto pr : mp) {
    bool ok = false;
    for (long long e : calmly) {
      if ((e | pr.first) == e) ok = true;
    }
    if (ok) ans += score[pr.first];
  }
  cout << ans << '\n';
  return 0;
}