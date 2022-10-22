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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
template <typename Abelian>
struct BIT {
  BIT(int n_, const Abelian &UNITY = 0) : n(n_), UNITY(UNITY) {
    ++n;
    dat.assign(n, UNITY);
  }

  void add(int idx, const Abelian &value) {
    while (idx < n) {
      dat[idx] += value;
      idx += idx & -idx;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    while (idx > 0) {
      res += dat[idx];
      idx -= idx & -idx;
    }
    return res;
  }

  Abelian sum(int left, int right) {
    if (right < left) return UNITY;
    return sum(right) - sum(left - 1);
  }

  Abelian operator[](const int idx) { return sum(idx, idx); }

  int lower_bound(Abelian value) {
    if (value < UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent < n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask < n && dat[res + mask] < value) {
        value -= dat[res + mask];
        res += mask;
      }
    }
    return res + 1;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};

int main() {
  int n; cin >> n;
  vector<int> a(n + 1); FOR(i, 1, n + 1) cin >> a[i];
  vector<pair<int, int> > s_a(n);
  REP(i, n) s_a[i] = {a[i + 1], -(i + 1)};
  sort(ALL(s_a));
  reverse(ALL(s_a));
  vector<vector<pair<int, int> > > len(n);
  int m; cin >> m;
  REP(i, m) {
    int k, pos; cin >> k >> pos;
    len[k - 1].emplace_back(pos, i);
  }
  BIT<int> bit(n + 1);
  vector<int> ans(m);
  REP(i, n) {
    bit.add(-s_a[i].second, 1);
    for (auto &pr : len[i]) ans[pr.second] = a[bit.lower_bound(pr.first)];
  }
  REP(i, m) cout << ans[i] << '\n';
  return 0;
}