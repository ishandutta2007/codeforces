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
    int n, k; cin >> n >> k;
    vector<int> odd;
    vector<int> a(n);
    REP(i, n) {
      cin >> a[i];
      if (a[i] & 1) odd.emplace_back(i + 1);
    }
    int sz = odd.size();
    if (sz - k >= 0 && (sz - k) % 2 == 0) {
      cout << "YES\n";
      odd.resize(k - 1);
      odd.emplace_back(n);
      REP(i, k) cout << odd[i] << (i == k - 1 ? '\n' : ' ');
    } else {
      cout << "NO\n";
    }
  }
}