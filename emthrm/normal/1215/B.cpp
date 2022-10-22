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
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    a[i] = (a[i] > 0 ? 1 : -1);
  }
  vector<int> tmp;
  int pos = 0;
  while (pos < n) {
    pos = find(a.begin() + pos + 1, a.end(), -1) - a.begin();
    tmp.emplace_back(pos);
  }
  vector<int> len{tmp[0]};
  FOR(i, 1, tmp.size()) len.emplace_back(tmp[i] - tmp[i - 1]);
  // for (int e : len) cout << e << '\n';
  int even = 0, odd = 0;
  for (int i = 0; i < len.size(); i += 2) even += len[i];
  for (int i = 1; i < len.size(); i += 2) odd += len[i];
  pos = 0;
  long long ans_n = 0, ans_p = 0;
  REP(i, n) {
    if (a[i] == -1) {
      ans_n += even;
      ans_p += odd;
    } else {
      ans_n += odd;
      ans_p += even;
    }
    --len[pos];
    --even;
    if (len[pos] == 0) {
      ++pos;
      swap(even, odd);
    }
  }
  cout << ans_n << ' ' << ans_p << '\n';
  return 0;
}