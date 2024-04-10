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

  int n, h; cin >> n >> h;
  vector<int> a(n); REP(i, n) cin >> a[i];
  for (int i = n - 1; i >= 0; --i) {
    vector<int> kouho;
    REP(j, i + 1) kouho.emplace_back(a[j]);
    sort(ALL(kouho));
    long long height = 0;
    if ((i + 1) & 1) {
      height += kouho.front();
      kouho.erase(kouho.begin());
    }
    for (int j = 0; j < kouho.size(); j += 2) {
      height += kouho[j + 1];
    }
    if (height <= h) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
}