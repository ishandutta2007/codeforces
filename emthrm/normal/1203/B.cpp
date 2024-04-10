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
  while (q--) {
    int n; cin >> n;
    n *= 4;
    vector<int> a(n); REP(i, n) cin >> a[i];
    map<int, int> mp;
    REP(i, n) ++mp[a[i]];
    vector<int> stick;
    bool ok = true;
    for (auto p : mp) {
      if (p.second & 1) ok = false;
      REP(i, p.second / 2) stick.emplace_back(p.first);
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    sort(ALL(stick));
    int sta = stick.front() * stick.back();
    FOR(i, 1, n / 2) {
      if (stick[i] * stick[n / 2 - 1 - i] != sta) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}