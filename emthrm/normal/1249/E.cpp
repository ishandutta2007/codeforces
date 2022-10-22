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
template <typename Monoid>
struct StarrySky {
  StarrySky(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  StarrySky(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, const Monoid &value) { add(a, b, value, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  Monoid value(int idx) {
    idx += n - 1;
    Monoid res = added[idx];
    while (idx > 0) {
      idx = (idx - 1) >> 1;
      res += added[idx];
    }
    return res;
  }

private:
  int n = 1;
  const Monoid UNITY, DEFAULT;
  vector<Monoid> dat, added;

  void init(int sz) {
    while (n < sz) n <<= 1;
    added.assign((n << 1) - 1, DEFAULT);
  }

  void add(int a, int b, const Monoid &value, int node, int left, int right) {
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      added[node] += value;
    } else {
      add(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
      add(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = min(dat[(node << 1) + 1] + added[(node << 1) + 1], dat[(node << 1) + 2] + added[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node] + added[node];
    return min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right)) + added[node];
  }
};

int main() {
  int n, c; cin >> n >> c;
  vector<int> a(n, 0), b(n, 0);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  StarrySky<long long> ss(n, LINF);
  cout << 0 << ' ';
  long long prev = 0;
  FOR(floor, 1, n) {
    ss.add(0, floor, b[floor]);
    long long ans = prev + a[floor];
    ans = min(ans, ss.query(0, floor) + c);
    cout << ans << (floor + 1 == n ? '\n' : ' ');
    prev = ans;
    ss.add(floor, floor + 1, ans);
  }
  return 0;
}