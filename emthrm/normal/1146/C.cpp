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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << 1 << ' ' << n - 1 << ' ' << 1 << ' ';
    FOR(i, 2, n + 1) {
      cout << i;
      if (i == n) cout << endl;
      else cout << ' ';
    }
    int dist; cin >> dist;
    int lb = 2, ub = n + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      cout << 1 << ' ' << mid - lb << ' ' << 1 << ' ';
      FOR(i, lb, mid) {
        cout << i;
        if (i == mid - 1) cout << endl;
        else cout << ' ';
      }
      int dia; cin >> dia;
      (dia == dist ? ub : lb) = mid;
    }
    cout << 1 << ' ' << n - 1 << ' ' << lb << ' ';
    vector<int> b;
    FOR(i, 1, n + 1) {
      if (i != lb) b.emplace_back(i);
    }
    REP(i, n - 1) {
      cout << b[i];
      if (i == n - 2) cout << endl;
      else cout << ' ';
    }
    int ans; cin >> ans;
    cout << -1 << ' ' << ans << endl;
  }
  return 0;
}