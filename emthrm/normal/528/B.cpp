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
template <typename Monoid>
struct RMQ {
  RMQ(int sz, const Monoid &UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMQ(const vector<Monoid> &a, const Monoid &UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, const Monoid &value) {
    node += n - 1;
    dat[node] = value;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = max(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, const Monoid &value) { return find(a, b, value, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, const Monoid &value, int node, int left, int right) {
    if (dat[node] < value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  int n; cin >> n;
  vector<long long> l(n), r(n), comp;
  REP(i, n) {
    long long x, w; cin >> x >> w;
    l[i] = x - w;
    r[i] = x + w;
    comp.emplace_back(l[i]);
    comp.emplace_back(r[i]);
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  REP(i, n) {
    l[i] = lower_bound(ALL(comp), l[i]) - comp.begin();
    r[i] = lower_bound(ALL(comp), r[i]) - comp.begin();
  }
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int L, int R) { return r[L] != r[R] ? r[L] < r[R] : l[L] < l[R]; });
  int m = comp.size();
  RMQ<int> rmq(m, -INF);
  rmq.update(0, 0);
  REP(i, n) {
    int tmp = rmq.query(0, l[idx[i]] + 1);
    if (tmp + 1 > rmq[r[idx[i]]]) rmq.update(r[idx[i]], tmp + 1);
  }
  cout << rmq.query(0, m) << '\n';
  return 0;
}