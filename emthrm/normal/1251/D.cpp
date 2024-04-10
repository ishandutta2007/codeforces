#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int t; cin >> t;
  while (t--) {
    int n; long long s; cin >> n >> s;
    vector<long long> l(n), r(n); REP(i, n) cin >> l[i] >> r[i];
    vector<pair<int, int> > lr(n);
    REP(i, n) lr[i] = {l[i], r[i]};
    sort(ALL(lr));
    long long lb = lr[n / 2].first, ub = s + 1;
    while (ub - lb > 1) {
      long long mid = (lb + ub) / 2;
      vector<int> a, c;
      vector<pair<long long, long long> > lr;
      REP(i, n) {
        if (r[i] < mid) {
          a.emplace_back(i);
        } else if (mid < l[i]) {
          c.emplace_back(i);
        } else {
          lr.emplace_back(l[i], r[i]);
        }
      }
      if (a.size() >= (n + 1) / 2) {
        ub = mid;
        continue;
      }
      // if (c.size() >= (n + 1) / 2) {
      //   lb = mid;
      //   continue;
      // }
      long long need = 0;
      for (int e : a) need += l[e];
      for (int e : c) need += l[e];
      sort(ALL(lr));
      reverse(ALL(lr));
      int nokori = (n + 1) / 2 - c.size();
      need += mid * nokori;
      FOR(i, nokori, lr.size()) need += lr[i].first;
      (need <= s ? lb : ub) = mid;
    }
    cout << lb << '\n';
  }
  return 0;
}