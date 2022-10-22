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
struct StarrySky1 {
  StarrySky1(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  StarrySky1(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
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

template <typename Monoid>
struct StarrySky2 {
  StarrySky2(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  StarrySky2(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
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
      dat[node] = max(dat[(node << 1) + 1] + added[(node << 1) + 1], dat[(node << 1) + 2] + added[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node] + added[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right)) + added[node];
  }
};

int main() {
  int n; string s; cin >> n >> s;
  StarrySky1<int> mn(n, INF);
  StarrySky2<int> mx(n, -INF);
  int pos = 0;
  vector<char> editor(n, '$');
  REP(x, n) {
    if (s[x] != 'L' && s[x] != 'R') {
      if (editor[pos] == '(') {
        mn.add(pos, n, -1);
        mx.add(pos, n, -1);
      } else if (editor[pos] == ')') {
        mn.add(pos, n, 1);
        mx.add(pos, n, 1);
      }
    }
    if (s[x] == '(') {
      mn.add(pos, n, 1);
      mx.add(pos, n, 1);
      editor[pos] = '(';
    } else if (s[x] == ')') {
      mn.add(pos, n, -1);
      mx.add(pos, n, -1);
      editor[pos] = ')';
    } else if (s[x] == 'L') {
      pos = max(pos - 1, 0);
    } else if (s[x] == 'R') {
      ++pos;
    } else {
      editor[pos] = '$';
    }
    if (mn.query(0, n) < 0 || mn.value(n - 1) != 0) {
      cout << -1;
    } else {
      cout << mx.query(0, n);
    }
    cout << (x + 1 == n ? '\n' : ' ');
  }
  return 0;
}