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
vector<long long> divisor(long long num) {
  vector<long long> res;
  for (long long i = 1; i * i <= num; ++i) {
    if (num % i == 0) {
      res.emplace_back(i);
      if (i * i != num) res.emplace_back(num / i);
    }
  }
  sort(ALL(res));
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<pair<int, int> > ab(m);
  REP(i, m) {
    int a, b; cin >> a >> b; --a; --b;
    if (a > b) swap(a, b);
    ab[i] = {a, b};
  }
  sort(ALL(ab));
  auto yakusu = divisor(n);
  yakusu.pop_back();
  for (int p : yakusu) {
    vector<pair<int, int> > tmp;
    REP(i, m) {
      int a = ab[i].first, b = ab[i].second;
      (a += p) %= n; (b += p) %= n;
      if (a > b) swap(a, b);
      tmp.emplace_back(a, b);
    }
    sort(ALL(tmp));
    if (ab == tmp) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}