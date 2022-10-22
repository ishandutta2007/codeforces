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

  int n; cin >> n;
  vector<int> a(n), b(n, 0);
  vector<int> change;
  REP(i, n) cin >> a[i];
  int q; cin >> q;
  while (q--) {
    int query; cin >> query;
    if (query == 1) {
      int p, x; cin >> p >> x; --p;
      a[p] = x;
      b[p] = change.size();
    } else {
      int x; cin >> x;
      change.emplace_back(x);
    }
  }
  if (change.size() >= 2) {
    for (int i = change.size() - 2; i >= 0; --i) {
      change[i] = max(change[i], change[i + 1]);
    }
  }
  REP(i, n) {
    if (b[i] < change.size()) {
      cout << max(a[i], change[b[i]]);
    } else {
      cout << a[i];
    }
    cout << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}