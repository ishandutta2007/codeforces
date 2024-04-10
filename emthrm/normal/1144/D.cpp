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

  int n; cin >> n;
  vector<int> a(n), cnt(200001, 0);
  REP(i, n) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  int mx = 0, num;
  REP(i, 200001) {
    if (cnt[i] > mx) {
      mx = cnt[i];
      num = i;
    }
  }
  cout << n - mx << '\n';
  int idx;
  REP(i, n) {
    if (a[i] == num) {
      idx = i;
      break;
    }
  }
  for (int i = idx - 1; i >= 0; --i) {
    cout << (a[i] < a[i + 1] ? 1 : 2) << ' ' << i + 1 << ' ' << i + 2 << '\n';
    a[i] = a[i + 1];
  }
  FOR(i, idx + 1, n) if (a[i - 1] != a[i]) {
    cout << (a[i - 1] < a[i] ? 2 : 1) << ' ' << i + 1 << ' ' << i << '\n';
    a[i] = a[i - 1];
  }
  return 0;
}