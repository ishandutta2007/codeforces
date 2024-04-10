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
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, Monoid value) { add(a, b, value, 0, 0, n); }

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

  void add(int a, int b, Monoid value, int node, int left, int right) {
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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string s; cin >> s;
  char now = s[0];
  int cnt = 1;
  vector<pair<char, int> > len;
  FOR(i, 1, s.length()) {
    if (s[i] != now) {
      len.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  len.emplace_back(now, cnt);
  if (len[0].first == '1') len.insert(len.begin(), make_pair('0', 0));
  int n = len.size(), memo = 0;
  vector<int> ori(n);
  for (int i = n - 1; i >= 0; --i) {
    ori[i] = len[i].second + (i + 1 < n ? memo : 0);
    if (len[i].first == '1') memo += len[i].second;
  }
  memo = 0;
  StarrySky<int> ss(n, -INF), zero(n, -INF), one(n, -INF);
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n) {
      one.add(i, i + 1, one.query(i + 1, i + 2));
      ss.add(i, i + 1, one.query(i + 1, i + 2));
    }
    if (len[i].first == '0') {
      zero.add(i, n, len[i].second);
      ss.add(i, n, len[i].second);
    } else {
      one.add(i, i + 1, len[i].second);
      ss.add(i, i + 1, len[i].second);
    }
    if (len[i].first == '1') {
      int plus = min(len[i].second, ori[i] - ss.query(i + 1, n));
      if (plus > 0) {
        zero.add(i - 1, n, plus);
        ss.add(i - 1, n, plus);
        one.add(i, i + 1, -plus);
        ss.add(i, i + 1, -plus);
      }
    }
  }
  string ans = "";
  REP(i, n) {
    // cout << zero[i] << ' ' << one[i] << '\n';
    if (len[i].first == '0') {
      int kaisu = zero.query(i, i + 1) - (i - 1 > 0 ? zero.query(i - 1, i) : 0);
      REP(_, kaisu) ans += '0';
    } else {
      int kaisu = one.query(i, i + 1) - (i + 1 < n ? one.query(i + 1, i + 2) : 0);
      REP(_, kaisu) ans += '1';
    }
  }
  cout << ans << '\n';
  return 0;
}