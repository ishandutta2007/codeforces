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
int n, a[100000];

long long cost(int kosu) {
  vector<long long> v(n);
  REP(i, n) v[i] = a[i] + (long long)(i + 1) * kosu;
  sort(ALL(v));
  long long res = 0;
  REP(i, kosu) res += v[i];
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int s; cin >> n >> s;
  REP(i, n) cin >> a[i];
  int lb = 0, ub = n + 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (cost(mid) <= s ? lb : ub) = mid;
  }
  cout << lb << ' ' << cost(lb) << '\n';
  return 0;
}